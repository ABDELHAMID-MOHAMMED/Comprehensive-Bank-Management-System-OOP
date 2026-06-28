#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsFindUserScreen :protected clsScreen
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
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t Find User Screen");
    
        string UserName = "";
        cout << "\nPlease Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is Not Found , Choose another one :   : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)";
        }
        else
        {
            cout << "\nUser Was Not Found :-(";
        }
        _PrintUser(User);
    }
};

