#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen :protected clsScreen
{
private:
	enum enCurrencyMenuOptions {
		eListsCurrency = 1, eFindCurrency = 2, eUpdateCurrency = 3,
		eCurrencyCalculator = 4, eMainMenu = 5
	};

	static short _ReadCurrencyExchangeMenuOption()
	{
		cout << setw(37) << left << "" << "Choose What do You Want To Do ? [1 to 5]? ";
		short Choise = clsInputValidate::ReadNumberBetween(1, 5, "Enter Number Between 1 to 5");
		return Choise;
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exchange Main Menue...\n";
		system("Pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _ShowListsCurrenciesScreen()
	{
		//cout << "\n List Currency Screen Will be here...\n";
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
		//cout << "\n Find Currency Screen Will be here...\n";
	}
	static void _ShowUpdateRateScreen()
	{
		//cout << "\n Update Rate Screen Will be here...\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\n Currency Calculator Screen Will be here...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyExchangeMenuOption(enCurrencyMenuOptions CurrencyMenuOptions)
	{
		switch (CurrencyMenuOptions)
		{
		case enCurrencyMenuOptions::eListsCurrency:
		{
			system("cls");
			_ShowListsCurrenciesScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyMenuOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyMenuOptions::eUpdateCurrency:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyMenuOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyMenuOptions::eMainMenu:
		{
			
		}
		}
	}

public:
	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Currency Exchange Main Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] LISTS CURRENCIES .\n";
		cout << setw(37) << left << "" << "\t[2] FIND CURRENCY .\n";
		cout << setw(37) << left << "" << "\t[3] UPDATE RATE .\n";
		cout << setw(37) << left << "" << "\t[4] CURRENCY CALCULATOR.\n";
		cout << setw(37) << left << "" << "\t[5] MAIN MENU .\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyExchangeMenuOption(enCurrencyMenuOptions(_ReadCurrencyExchangeMenuOption()));
	}
};

