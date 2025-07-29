#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersScreen : protected clsScreen
{
private:

    static void _GoBackToManageUserScreen()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ManageUsersScreen();
    }

    enum enManageUsersChoice
    {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };
    static short _ReadManageUsersMenueOption()
    {

        cout << "Enter Your Choice : ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Not in Range [1:6], Enter Again : ");
        return Choice;

    }
    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
    }
    static void _ShowAddNewUsersScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }
    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }
    static void _ShowMainMenueScreen()
    {
        //cout << "Show Main Menue Screen Will be Here.\n";
    }
    static void _PerformManageUsersMenueOption(enManageUsersChoice ManageUsersChoice)
    {
        switch (ManageUsersChoice)
        {
        case enManageUsersChoice::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUserScreen();
            break;
        }

        case enManageUsersChoice::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUsersScreen();
            _GoBackToManageUserScreen();
            break;
        }

        case enManageUsersChoice::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUserScreen();
            break;
        }
        case enManageUsersChoice::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUserScreen();
            break;
        }
        case enManageUsersChoice::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUserScreen();
            break;
        }
        case enManageUsersChoice::eMainMenue:
        {
            // nothing here the main screen will handle it :-) ;
        }

        }
    }
public:

    static void ManageUsersScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersChoice)_ReadManageUsersMenueOption());
    }
};

