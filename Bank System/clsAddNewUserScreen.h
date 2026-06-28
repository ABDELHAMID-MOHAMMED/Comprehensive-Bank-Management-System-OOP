#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsAddNewUserScreen :protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\n Enter First Name : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\n Enter Last Name : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\n Enter Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\n Enter Phone Number : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\n Enter Password : ";
        User.Password = clsInputValidate::ReadString();
        cout << "\n Enter Permissions : ";

        User.Permissions = _ReadPermissionToSet();
    }

    static int _ReadPermissionToSet()
    {
        int Permission = 0;
        char Answer = 'n';

        cout << "Do You Want TO Give Full Access ?y/n";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            return -1;
        }

        cout << "\nDo You Want To Give Access To :\n";
        cout << "Show Client lists ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pListClients;
        }
        cout << "\nAdd New Client ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pAddNewClient;
        }
        cout << "\nDelete Client ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pDeleteClient;
        }
        cout << "\nUpdate Client ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pUpdateClients;
        }
        cout << "\nFind Client ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pFindClient;
        }
        cout << "\nTransactions ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pTranactions;
        }
        cout << "\nManage Users ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pManageUsers;
        }
        return Permission;
    }
    
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
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t Add New User Screen");

        string UserName = "";
        cout << "\n Please Enter User Name : ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\n User Name is Already Used , Choose Another one : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();
        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << "\n User Added Successfully :-)";
            _PrintUser(NewUser);
            break;
        }

        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User Was Not Saved Because it's Empty";
            break;
        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User Name Already Exists!";
            break;
        }

        }
	}
};

