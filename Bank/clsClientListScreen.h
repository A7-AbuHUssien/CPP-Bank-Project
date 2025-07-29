#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
private:
	static void PrintClientRecordLine(clsBankClient Client)
	{



		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;

	}
public:

	static void _ShowAllClientsScreen()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}

		vector <clsBankClient>vClients = clsBankClient::GetClientsList();
		string Title = "Client List Screen";
		string SubTitle = "\t(" + to_string(vClients.size()) + ") Clients.";

		_DrawScreenHeader(Title, SubTitle);
		cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\ n\n-----------------------------------------------------------------------------------------------------------------\n\n";

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In The System!";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				PrintClientRecordLine(Client);
				cout << endl;
			}
			cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";

		}
	}
};

