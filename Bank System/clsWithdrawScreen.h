#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsWithdrawScreen :protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClinet Card : ";
        cout << "\n--------------------------";
        cout << "\nFirst Name       : " << Client.FirstName;
        cout << "\nLast Name        : " << Client.LastName;
        cout << "\nFull Name        : " << Client.GetFullName();
        cout << "\nEmail            : " << Client.Email;
        cout << "\nPhone            : " << Client.Phone;
        cout << "\nAccount Number   : " << Client.AccountNumber();
        cout << "\nPassword         : " << Client.PinCode;
        cout << "\nAccount Balance  : " << Client.AccountBalance;
        cout << "\n--------------------------";
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number : ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient With [" << AccountNumber << "] Does Not Exist.";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\n\nPlease Enter Withdraw Amount?";
        Amount = clsInputValidate:: ReadNumber<double>();
        cout << "\nAre You Sure You Want To Perform This Transaction?";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Withdraw(Amount))
            {
                cout << "\nAmount Withdarw Successfully.\n";
                cout << "\nNew Balance Is : " << Client.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdarw, Insuffecient Balance!\n";
                cout << "\nAmount to Withdraw is : " << Amount;
                cout << "\nYour Balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperation was Cancelled \n";
        }
    }

};

