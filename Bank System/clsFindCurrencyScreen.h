#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen :protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card : ";
        cout << "\n___________________________";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCode        : " << Currency.CurrencyCode();
        cout << "\nName        : " << Currency.CurrencyName();
        cout << "\nRate($1)            : " << Currency.Rate();
        cout << "\n___________________________";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By : [1] Code or [2] Country? ";
        short Choice = clsInputValidate::ReadNumberBetween(1, 2);

        if (Choice == 1)
        {
            string CurrencyCode = "";
            cout << "\nPlease Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else if (Choice == 2)
        {
            string CountryName = "";
            cout << "\nPlease Enter Country Name: ";
            CountryName = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
            _ShowResults(Currency);
        }
    }
};

