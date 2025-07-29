#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"


using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(int number, int from, int to)
	{
		return (number >= from && number <= to);
	}
	static bool IsNumberBetween(double number, double from, double to)
	{
		return (number >= from && number <= to);

	}
	static bool IsDateBetween(clsDate date, clsDate dateFrom, clsDate dateTo)
	{
		if (clsDate::IsDate1AfterDate2(dateFrom, dateTo))
		{
			clsDate::SwapDates(dateFrom, dateTo);
		}

		return clsDate::IsDate1EqualDate2(date, dateFrom) ||
			(clsDate::IsDate1AfterDate2(date, dateFrom) && clsDate::IsDate1BeforeDate2(date, dateTo));
	}
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static double ReadDoubleNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double DBNumber = 0.0;
		while (!(cin >> DBNumber))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return DBNumber;
	}
	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float FNumber = 0.0;
		while (!(cin >> FNumber))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return FNumber;
	}
	static int ReadIntNumberBetween(int from, int to, string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number = ReadIntNumber();
		while (!IsNumberBetween(Number, from, to))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static double ReadDoubleNumberBetween(double from, double to, string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number = ReadDoubleNumber();
		while (!IsNumberBetween(Number, from, to))
		{
			cout << ErrorMessage;
			Number = ReadDoubleNumber();
		}
		return Number;
	}
	static bool IsValidDate(clsDate date)
	{
		return (clsDate::IsValidDate(date));
	}
	static string ReadString()
	{
		string S;
		cin >> S;
		return S;
	}
};

