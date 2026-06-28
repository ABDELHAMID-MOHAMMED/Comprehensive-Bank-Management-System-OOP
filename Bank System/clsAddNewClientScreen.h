#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsScreen.h"

class clsAddNewClientScreen :protected clsScreen
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
        cout << "\nAccount Number   : " << Client.GetAccountNumber();
        cout << "\nPassword         : " << Client.PinCode;
        cout << "\nAccount Balance  : " << Client.AccountBalance;
        cout << "\n--------------------------";
    }
public:

	static void ShowAddNewClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }

		_DrawScreenHeader("\t Add New Client Screen");


        string AccountNumber = "";
        cout << "\n Please Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n Account Number is Already Used , Choose Another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientobject(AccountNumber);
        _ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\n Client Added Successfully :-)";
           _PrintClient(NewClient);
            break;
        }

        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Account Was Not Saved Because it's Empty";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError Account Number Already Exists!";
            break;
        }

        }

	}
};

