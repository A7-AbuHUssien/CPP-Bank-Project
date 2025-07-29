#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsListCurrenciesScreen : protected clsScreen
{
	static void _PrintCurrenciesRecordLine(clsCurrency CurrencyRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(28) << left << CurrencyRecord.getCountry();
		cout << "| " << setw(8) << left << CurrencyRecord.getCurrencyCode();
		cout << "| " << setw(42) << left << CurrencyRecord.getCurrencyName();
		cout << "| " << setw(10) << left << to_string(CurrencyRecord.getRate()) << endl;
	}
public:

	static void ShowListCurrenciesScreen()
	{
		
		vector<clsCurrency>vCurrencies = clsCurrency::GetCurrenciesList();

		_DrawScreenHeader("\tCurrencies List.");

		cout << setw(8) << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n\n";

		cout << setw(8) << "" << "| " << left << setw(28) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(42) << "Currency Name";
		cout << "| " << left << setw(10) << "Rate(1$)";
		cout << setw(8) << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n\n";

		if (vCurrencies.size() == 0)
		{
			cout << clsUtil::Tabs(4) << "No Currencies available In this System \n";
		}

		else
		{
			for (clsCurrency CurrenciesRecord : vCurrencies)
			{
				_PrintCurrenciesRecordLine(CurrenciesRecord);
			}
		}

	}
};

