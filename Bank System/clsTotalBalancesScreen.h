#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
#include "clsUtil.h"
class clsTotalBalancesScreen :protected clsScreen
{
private:
    static void _PrintClientRecordBalancesLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.GetFullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

public:

    static void ShowTotalBalances()
    {

        vector<clsBankClient>vClients = clsBankClient::GetClientsList();
        string Title = "\t  Balance List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ")Clients (s). ";
        
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
       
        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
        {
            cout << "\t\t\tNo Client Available In The System .\n";
        }
        else
        {
            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordBalancesLine(Client);
                cout << endl;
            }
            cout << "\n-------------------------------------------------------------------";
            cout << "------------------------------------\n\n";

            cout << "\t\t\t\t\tTotal Balances : " << TotalBalances << endl;
            cout << "\t\t\t\t\t (" << clsUtil::NumberToText(TotalBalances) << ")\n";
        }

    }

};

