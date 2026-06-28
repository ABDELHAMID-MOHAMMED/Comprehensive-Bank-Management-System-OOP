#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersScreen :protected clsScreen
{
private:

	enum enUsersMenuOptions { eListsUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eUsersMenu = 6 };


	static short _ReadManageUsersMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 6]? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 ? ");
		return Choise;
	}

	static void _ShowListUsersScreen()
	{
		//cout << "\nUser List Screen Will Be Here.\n";
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New User Screen Will Be Here.\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will Be Here.\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User Screen Will Be Here.\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will Be Here.\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackManageUsersMenu()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenu();
	}

	static void _PerFormUsersMenuOptions(enUsersMenuOptions UsersMenuOptions)
	{
		switch (UsersMenuOptions)
		{
		case enUsersMenuOptions::eListsUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackManageUsersMenu();
		}
		case enUsersMenuOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackManageUsersMenu();
		}
		case enUsersMenuOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackManageUsersMenu();
		}
		case enUsersMenuOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackManageUsersMenu();
		}
		case enUsersMenuOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackManageUsersMenu();
		}
		case enUsersMenuOptions::eUsersMenu:
		{
			
		}
		}

	}

public:

	static void ShowManageUsersMenu()
	{
		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		_DrawScreenHeader("\t   Manage Users Screen");


		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] LISTS USERS .\n";
		cout << setw(37) << left << "" << "\t[2] ADD NEW USER .\n";
		cout << setw(37) << left << "" << "\t[3] DELETE USER .\n";
		cout << setw(37) << left << "" << "\t[4] UPDATE USER .\n";
		cout << setw(37) << left << "" << "\t[5] FIND USER .\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu .\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerFormUsersMenuOptions(enUsersMenuOptions(_ReadManageUsersMenuOption()));
	}
};

