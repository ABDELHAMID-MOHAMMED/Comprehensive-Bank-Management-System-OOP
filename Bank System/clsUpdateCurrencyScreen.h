#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
class clsUpdateCurrencyScreen :protected clsScreen
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

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";

        float NewRate = 0;
        NewRate = clsInputValidate::ReadNumber<float>();
        return NewRate;
    }

public:
	static void ShowUpdateCurrencyScreen()
	{
        _DrawScreenHeader("\t  Update Currency Screen");

            string CurrencyCode = "";
            cout << "\nPlease Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            while (!clsCurrency::IsCurrencyExist(CurrencyCode))
            {
                cout << "\nCurrency Was not Found ,Choose Another One : \n";
                CurrencyCode = clsInputValidate::ReadString();
            }
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _PrintCurrency(Currency);

            cout << "\nAre you sure you want to update the rate of this currency y/n? ";
            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            {
                cout << "\n\nUpdate Currency Rate:";
                cout << "\n________________________________";
                
                Currency.UpdateRate(_ReadRate());

                cout << "\nCurrency Updated Successfully :-)\n";
                _PrintCurrency(Currency); 
            }
            else
            {
                cout << "\nUpdating Cancelled.\n";
            }
	}
};

