#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
class clsUpdateUserScreen :protected clsScreen
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
        cout << "\nLogin register List ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pLoginRegister;
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

    static void ShowUpdateUserScreen()
    {
        system("cls");
        _DrawScreenHeader("\t Update User Screen");

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
        cout << "\n are You Sure You Want To Update This User y/n ? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\n\nUpdate User Info : ";
            cout << "\n---------------------------------\n";
            _ReadUserInfo(User);
            clsUser::enSaveResults SaveResult;
            SaveResult = User.Save();
            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-) ";
                _PrintUser(User);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User Was Not Saved Because it's Empty ";
                break;
            }
            }


        }
        else
        {
            cout << "\nError User Was Not Deleted !";
        }

    }
    
};

