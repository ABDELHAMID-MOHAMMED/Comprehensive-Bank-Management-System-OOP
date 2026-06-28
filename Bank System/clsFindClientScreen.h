#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
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
        cout << "\nAccount Number   : " << Client.GetAccountNumber();
        cout << "\nPassword         : " << Client.PinCode;
        cout << "\nAccount Balance  : " << Client.AccountBalance;
        cout << "\n--------------------------";
    }
public:
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\t  Find Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is Not Found , Choose another one :   : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
       
        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)";
        }
        else
        {
            cout << "\nClient Was Not Found :-(";
        }
        _PrintClient(Client);

    }
};

