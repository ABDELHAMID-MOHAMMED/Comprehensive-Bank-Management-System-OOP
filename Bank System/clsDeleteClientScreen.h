#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeleteClientScreen :protected clsScreen
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
public:
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }

        _DrawScreenHeader("\t Delete Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is Not Found , Choose another one :   : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        char Answer = 'n';
        cout << "\n are You Sure You Want To Delete This Client y/n ? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Delete())
            {
                cout << "\n Client Deleted Successfully :-)";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nError Client Was Not Deleted !";
            }
        }
    }
};

