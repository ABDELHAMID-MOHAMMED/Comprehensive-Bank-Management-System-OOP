#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency,string Title)
	{
		cout << "\n" << Title << "\n";
		cout << "\n___________________________";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate($1)            : " << Currency.Rate();
		cout << "\n___________________________";
	}

	static clsCurrency _GetCurrencyCode(string Message)
	{
		string CurrencyCode = "";
		cout << Message << endl;
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Was not Found ,Choose Another One : \n";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}
	

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange : ";

		float NewRate = 0;
		NewRate = clsInputValidate::ReadNumber<float>();
		return NewRate;
	}

	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "Convert From");
		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode()
			<< " = " << AmountInUSD << " USD.\n";
		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}
		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(CurrencyTo, "To");

		float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << Amount << " " << CurrencyFrom.CurrencyCode()
			<< " = " << AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode();

	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';
		while (Continue == 'Y' || Continue == 'y')
		{

			system("cls");

			_DrawScreenHeader("\t Currency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrencyCode("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrencyCode("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation? y/n? ";
			cin >> Continue;

		}
	}
};

