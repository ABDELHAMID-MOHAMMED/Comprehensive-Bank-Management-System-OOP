#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
using namespace std;
class clsTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionsMenuOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eShowMainMenu = 4
	};
	static short ReadTransactionsMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 4]? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
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
		cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionsMenuOption(enTransactionsMenuOptions(ReadTransactionsMenuOption()));
	}
};

