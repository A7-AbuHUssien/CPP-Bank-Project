#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrenciesCalculatorScreen : protected clsScreen
{
private:

    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;

        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static clsCurrency _GetCurrency(string Message)
    {

        string CurrencyCode;
        cout << Message << endl;

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
        return Currency;

    }




    static string _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        //_PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        //cout << Amount << " " << Currency1.getCurrencyCode() << " = " << AmountInUSD << " USD\n";

     

        //cout << "\nConverting from USD to:\n";

        //_PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        return to_string(Amount)+" " + Currency1.getCurrencyCode() + " = " + to_string(AmountInCurrrency2) + " " + Currency2.getCurrencyCode();
         
    }


public:

    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");

            _DrawScreenHeader("\tUpdate Currency Screen");

            clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
            float Amount = _ReadAmount();

            string S = _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\t\t\t\t\t||===================================================||\n";
            cout << "\t\t\t\t\t||        " << S << "       ||\n";
            cout << "\t\t\t\t\t||===================================================||\n";

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;

        }


    }

};

