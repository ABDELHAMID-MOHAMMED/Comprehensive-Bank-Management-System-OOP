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
	static bool _Login()
	{
		bool LoginFaild = false;
		string UserName, Password;
		short FaildLoginCount = 0;

		do {
				if (LoginFaild)
				{
					FaildLoginCount++;
					
						cout << "\n Invalid UserName/Password!\n\n";
						cout << "\nYou Have " << 3- FaildLoginCount << " Trails to Ligin \n\n";
				}
				if (FaildLoginCount == 3)
				{
					cout << "\n Your Locked After 3 Faild Trails\n\n";
					return false;
				}
				cout << "Enter User Name : ";
				cin >> UserName;

				cout << "Enter Passwrod : ";
				cin >> Password;

				CurrentUser = clsUser::Find(UserName, Password);

				LoginFaild = CurrentUser.IsEmpty();

			
		} while (LoginFaild);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;

	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};

