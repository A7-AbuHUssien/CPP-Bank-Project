#pragma once
#include <iostream>
#include"clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsDeleteClientScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }
public:

    static void DeleteClient()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }


        _DrawScreenHeader("Delete Client Screen");
        string AccountNumber = "";

        cout << "Enter Account Number Yo Wanna Delete : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n\nThis Account Is NOT Found,:( \n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "Are You Sure, Yo Wanna Delete This Client [Y/N]?  ";
        char DeleteSuring = 'N';
        cin >> DeleteSuring;

        if (DeleteSuring == 'Y' || DeleteSuring == 'y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successufully .\n\n";
                _PrintClient(Client1);

            }
            else
            {
                cout << "\nError, Account NOT Deleted .\n\n";
            }
        }
    }
};

