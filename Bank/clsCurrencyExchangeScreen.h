#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include"clsFindCurrencyScreen.h"
#include "clsUpdateCurrenciesRateScreen.h"
#include "clsCurrenciesCalculatorScreen.h"


class clsCurrencyExchangeScreen : protected clsScreen
{
private:

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		system("cls");
		ShowCurrencyExchangeScreen();
	}
	static short _ReadCurrencyChoice()
	{
		short  Choice;
		Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Not in Range, Enter Again [1:5] : ");
		return Choice;
	}
	enum enCurrencyChoice
	{
		ListCurrencies = 1, FindCurrency = 2, UpdateCurrenciesRate = 3,
		CurrenciesCalculator = 4, MainMenue = 5
	};



	static void _ShowListCurrenciesScreen()
	{
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}
	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateCurrenciesRateScreen()
	{
		clsUpdateCurrenciesRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrenciesCalculatorScreen()
	{
		clsCurrenciesCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyChoice(enCurrencyChoice CurrencyChoice)
	{
		switch (CurrencyChoice)
		{
		case clsCurrencyExchangeScreen::ListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToMainMenue();
			break;
		case clsCurrencyExchangeScreen::FindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToMainMenue();
			break;
		case clsCurrencyExchangeScreen::UpdateCurrenciesRate:
			system("cls");
			_ShowUpdateCurrenciesRateScreen();
			_GoBackToMainMenue();
			break;
		case clsCurrencyExchangeScreen::CurrenciesCalculator:
			system("cls");
			_ShowCurrenciesCalculatorScreen();
			_GoBackToMainMenue();
			break;
		case clsCurrencyExchangeScreen::MainMenue:
			break;

		}
	}


public:

	static void ShowCurrencyExchangeScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pCurrencies))
		{
			return;
		}
		_DrawScreenHeader("Currency Exchange Main Screen");
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "       Currency Exchange Menue.\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "[1] List Currencies.\n";
		cout << setw(37) << left << "" << "[2] Find Currency.\n";
		cout << setw(37) << left << "" << "[3] Update Currencies Rate.\n";
		cout << setw(37) << left << "" << "[4] Currencies Calculator.\n";
		cout << setw(37) << left << "" << "[5] Main Menue.\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "Choose What Do You Wanna Do?[1:5]? ";
		_PerformCurrencyChoice((enCurrencyChoice)_ReadCurrencyChoice());
	}
};

