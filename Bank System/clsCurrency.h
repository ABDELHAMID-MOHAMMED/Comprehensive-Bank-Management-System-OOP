#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include <string>

class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		if (vCurrencyData.size() < 4)
		{
			return _GetEmptyCurrencyObject();
		}

		string Country = vCurrencyData[0];
		string CurrencyCode = vCurrencyData[1];
		string CurrencyName = vCurrencyData[2];
		float Rate = 0;

		string RateStr = vCurrencyData[3];

		if (!RateStr.empty() && RateStr.front() == '"') RateStr.erase(0, 1);
		if (!RateStr.empty() && RateStr.back() == '"')  RateStr.pop_back();

		try
		{
			Rate = stof(RateStr);
		}
		catch (...)
		{
			Rate = 0;
		}

		return clsCurrency(enMode::UpdateMode, Country, CurrencyCode, CurrencyName, Rate);
	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string CurrencyRecord = "";
		CurrencyRecord += Currency._Country + Seperator;
		CurrencyRecord += Currency._CurrencyCode + Seperator;
		CurrencyRecord += Currency._CurrencyName + Seperator;
		CurrencyRecord += to_string(Currency._Rate);
		return CurrencyRecord;
	}

	static  vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector <clsCurrency> vCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				if (Line == "")
					continue;

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrency;

	}

	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrency)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrency)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;

			}

		}

		MyFile.close();

	}

	void _Update()
	{
		vector <clsCurrency> vCurrency;
		vCurrency = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrenciesDataToFile(vCurrency);

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}


	float Rate()
	{
		return _Rate;
	}


	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					if (Line == "") continue;

					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					if (Line == "") continue;

					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1=clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		return (float)(AmountInUSD * Currency2.Rate());
	}

};

