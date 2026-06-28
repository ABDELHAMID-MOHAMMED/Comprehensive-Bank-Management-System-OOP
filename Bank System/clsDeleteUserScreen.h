#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsDeleteUserScreen :protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card : ";
        cout << "\n--------------------------";
        cout << "\nFirst Name       : " << User.FirstName;
        cout << "\nLast Name        : " << User.LastName;
        cout << "\nFull Name        : " << User.GetFullName();
        cout << "\nEmail            : " << User.Email;
        cout << "\nPhone            : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword         : " << User.Password;
        cout << "\nPermissions  : " << User.Permissions;
        cout << "\n--------------------------";
    }

public:
    static void ShowDeleteUserScreen()
    {
        system("cls");

        _DrawScreenHeader("\t Delete User Screen");

        string UserName = "";
        cout << "\nPlease Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is Not Found , Choose another one :   : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        char Answer = 'n';
        cout << "\n are You Sure You Want To Delete This User y/n ? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (User.Delete())
            {
                cout << "\n User Deleted Successfully :-)";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError User Was Not Deleted !";
            }
        }
    }
};

