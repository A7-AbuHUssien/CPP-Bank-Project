#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        clsDate Date = clsDate::GetSystemDate();
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t" << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\t" << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\t" << "User : " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\t" << "Date : " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n\n";
    }
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t--------------------------------------------------------------------------\n";
            cout << "\n\t\t\t\t\t Access Denied !, Contact Your Admin\n";
            cout << "\t\t\t\t--------------------------------------------------------------------------\n";
            return false;
        }
        else
        {
            return true;
        }
    }

};