#include <iostream>
#include <string>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <iomanip>
using namespace std;

void ReadClientInfo(clsBankClient& Client)
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

void UpdateClient()
{
    string AccountNumber = "";
    cout << "\nPlease Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is Not Found , Choose another one :   : ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\n\nUpdate Client Info : ";
    cout << "\n---------------------------------\n";
    ReadClientInfo(Client);
    clsBankClient::enSaveResults SaveResult;
    SaveResult = Client.Save();
    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-) ";
        Client.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError Account Was Not Saved Because it's Empty ";
        break;
    }
    }

}

void AddNewClient()
{
    string AccountNumber = "";
    cout << "\n Please Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\n Account Number is Already Used , Choose Another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient NewClient = clsBankClient::GetAddNewClientobject(AccountNumber);
    ReadClientInfo(NewClient);
    clsBankClient::enSaveResults SaveResult;
    SaveResult = NewClient.Save();
    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\n Client Added Successfully :-)";
        NewClient.Print();
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

void DeleteClient()
{
    string AccountNumber = "";
    cout << "\nPlease Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is Not Found , Choose another one :   : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    char Answer='n';
    cout << "\n are You Sure You Want To Delete This Client y/n ? ";
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y')
    {
        if (Client.Delete())
        {
            cout << "\n Client Deleted Successfully :-)";
            Client.Print();
        }
        else
        {
            cout << "\nError Client Was Not Deleted !";

        }
    }
}

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.GetAccountNumber();
    cout << "| " << setw(20) << left << Client.GetFullName();
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(20) << left << Client.Email;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void PrintClientRecordBalancesLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.GetAccountNumber();
    cout << "| " << setw(20) << left << Client.GetFullName();
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowClientsList()
{
    vector<clsBankClient>vClients = clsBankClient::GetClientLists();
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Clients (s) ";
    cout << "\n-------------------------------------------------";

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n-------------------------------------------------";


    if (vClients.size() == 0)
    {
        cout << "\t\t\tNo Client Available In The System .\n";
    }
    else
    {
        for (clsBankClient Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
        cout << "\n-------------------------------------------------";
    }

}

void ShowTotalBalances()
{
    vector<clsBankClient>vClients = clsBankClient::GetClientLists();
    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ")Clients (s) ";
    cout << "\n-------------------------------------------------------------------";
    cout << "------------------------------------\n";

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n-------------------------------------------------------------------";
    cout << "------------------------------------\n";

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
    {
        cout << "\t\t\tNo Client Available In The System .\n";
    }
    else
    {
        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalancesLine(Client);
            cout << endl;
        }
        cout << "\n-------------------------------------------------------------------";
        cout << "------------------------------------\n\n";

        cout << "\t\t\t\t\tTotal Balances : " << TotalBalances << endl;
        cout << "\t\t\t\t\t (" << clsUtil::NumberToText(TotalBalances)<<")\n";
    }

}

int main()
{
    ShowTotalBalances();
}
