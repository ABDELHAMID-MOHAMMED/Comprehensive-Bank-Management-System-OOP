#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
class clsListCurrenciesScreen :protected clsScreen
{
private:
    static void _PrintCurrenciesRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(6) << left << Currency.CurrencyCode();
        cout << "| " << setw(35) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();
    }
public:
    static void ShowListCurrenciesScreen()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrencyList();

        string Title = "\t  Currency List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(6) << "Code";
        cout << "| " << left << setw(35) << "Name";
        cout << "| " << left << setw(12) << "Rate/(1$)";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
        {
            cout << "\t\t\t\tNo Currency Available In the System!";
        }
        else
        {
            for (clsCurrency Currency : vCurrency)
            {
                _PrintCurrenciesRecordLine(Currency);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;


    }
};

