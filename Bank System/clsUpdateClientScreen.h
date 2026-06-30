#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen :protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\n Enter First Name : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n Enter Last Name : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\n Enter Email : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\n Enter Phone Number : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\n Enter Pin Code : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\n Enter Account Balance : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

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
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        _DrawScreenHeader("\t Update Client Screen");

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

        cout << "\n\nUpdate Client Info : ";
        cout << "\n---------------------------------\n";
        _ReadClientInfo(Client);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-) ";
            _PrintClient(Client);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Account Was Not Saved Because it's Empty ";
            break;
        }
        }
    }

};

