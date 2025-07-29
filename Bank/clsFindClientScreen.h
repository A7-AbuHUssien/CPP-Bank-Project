#pragma once
#include <iostream>
#include"clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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

	static void FindClient()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("Find Client Screen\n");

		string AccNum;
		cout << "Enter The Account Number : ";
		AccNum = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccNum))
		{
			cout << "This Account Number is NOT Exists, Enter Another  : ";
			AccNum = clsInputValidate::ReadString();

		}

		_PrintClient(clsBankClient::Find(AccNum));

	}

};

