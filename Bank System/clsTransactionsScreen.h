#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;
class clsTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionsMenuOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenu = 6
	};
	static short ReadTransactionsMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 6]? ";
		short Choise = clsInputValidate::ReadNumberBetween(1, 6, "Enter Number between 1 to 4? ");
		return Choise;
	}

	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screen Will Be Here.\n";
		clsDepositScreen::ShowDepositScreen();
	}


	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen Will Be Here.\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}


	static void _ShowTotalBalanceScreen()
	{
		//cout << "\nTotalBalance Screen Will Be Here.\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer Screen Will Be Here.\n";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\nTransfer Log Screen Will Be Here.\n";
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackTransactionsMenu()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOptions)
	{
		switch (TransactionsMenuOptions)
		{
		case enTransactionsMenuOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowMainMenu:
		{
			
		}
		}

	}
public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t  Transaction Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionsMenuOption(enTransactionsMenuOptions(ReadTransactionsMenuOption()));
	}
};

