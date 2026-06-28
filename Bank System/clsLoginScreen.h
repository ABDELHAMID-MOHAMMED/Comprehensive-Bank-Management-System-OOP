#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"
class clsLoginScreen :protected clsScreen
{
private:
	static void _Login()
	{
		bool LoginFaild = false;
		string UserName, Password;
		do {
			if (LoginFaild)
			{
				cout << "\n Invalid UserName/Password!\n\n";
			}
			cout << "Enter User Name : ";
			cin >> UserName;

			cout << "Enter Passwrod : ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		clsMainScreen::ShowMainMenu();
	}

public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}
};

