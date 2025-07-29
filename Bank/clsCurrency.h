#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>
#include <fstream>


class clsCurrency
{
private:
	enum enMode {EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrency _ConvertLinetoCurrencyObject(string Line)
	{
		vector <string> vString = clsString::Split(Line, "#//#");

		return clsCurrency(enMode::UpdateMode, vString[0], vString[1], vString[2], stof(vString[3]));
	}
	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.getCountry() + Seperator;
		stCurrencyRecord += Currency.getCurrencyCode() + Seperator;
		stCurrencyRecord += Currency.getCurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.getRate());

		return stCurrencyRecord;

	}
	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrencys)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;



			}

			MyFile.close();

		}

	}
	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.getCurrencyCode() == getCurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencys);

	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		clsCurrency Curr(enMode::EmptyMode, "", "", "", 0);
		return Curr;
	}
	static vector<clsCurrency>_LoadCurrencyDataFromFile() {

		vector<clsCurrency>vCurrencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			MyFile.close();
		}
		return vCurrencies;
	}
	

public:
	// Setter and Getter Proparties
	string getCountry() {
		return _Country;
	}
	string getCurrencyCode() {
		return _CurrencyCode;
	}
	string getCurrencyName() {
		return _CurrencyName;
	}
	float getRate() {
		return _Rate;
	}
	void setRate(float new_rate) {
		_Rate = new_rate;
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCurrencyCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	



	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	

	static vector<clsCurrency>GetCurrenciesList() {

		vector<clsCurrency>vCurrencies = _LoadCurrencyDataFromFile();
		
		return vCurrencies;
	}
	static clsCurrency FindByCurrencyCode(string CurrencyCode) {

		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		
		vector<clsCurrency>vCurrencies = _LoadCurrencyDataFromFile();
		for (clsCurrency& C : vCurrencies) {
			if (C.getCurrencyCode() == CurrencyCode) {
				return C;
			}
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string CountryName) {

		CountryName = clsString::LowerAllString(CountryName);
		CountryName = clsString::UpperFirstLetterOfEachWord(CountryName);

		vector<clsCurrency>vCurrencies = _LoadCurrencyDataFromFile();
		for (clsCurrency& C : vCurrencies) {
			if (C.getCountry() == CountryName) {
				return C;
			}
		}
		return _GetEmptyCurrencyObject();
	}

	float ConvertToUSD(float Amount) {

		return (Amount / getRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2) {

		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.getCurrencyCode() == "USD") {

			return AmountInUSD;
		}
		
		return (AmountInUSD * Currency2.getRate());
	}
};
