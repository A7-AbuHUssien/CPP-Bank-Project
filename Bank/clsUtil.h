#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;
class clsUtil
{
public:
	enum enCharType {
		SmallLetter = 1, CapitalLetter = 2, Digit = 3,
		MixCharacters = 4, SpeacialCharacter = 5
	};
	static void Srand() {

		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To) {

		int RandomNum = rand() % (To - From + 1) + From;
		return RandomNum;
	}
	static char GetRandomCharacter(enCharType CharType) {

		if (CharType == MixCharacters)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}
		switch (CharType)
		{
		case enCharType::SmallLetter: return char(RandomNumber(97, 122));
		case enCharType::CapitalLetter: return char(RandomNumber(65, 90));
		case enCharType::Digit: return char(RandomNumber(48, 57));
		case enCharType::SpeacialCharacter: return char(RandomNumber(33, 47));
		defualt:return char(RandomNumber(65, 90));
		}

	}
	static string GenerateWord(enCharType CharType, short Length) {

		string Word = "";
		for (short i = 0; i < Length; i++) {

			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey(enCharType CharType = CapitalLetter) {

		string Key = "";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);
		return Key;
	}
	static void GenrateKeys(short NumberOfKeys) {

		for (short i = 0; i < NumberOfKeys; i++) {
			cout << "Key[" << i + 1 << "] : " << GenerateKey() << endl;
		}
	}
	static void FillArraywithRandomNumbers(int Arr[], int arrLength, int From, int To) {

		for (short i = 0; i < arrLength; i++) {
			Arr[i] = RandomNumber(From, To);
		}
	}
	static void FillArraywithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
	{

		for (short i = 0; i < arrLength; i++) {

			arr[i] = GenerateWord(CharType, Wordlength);
		}
	}
	static void FillArraywithRandomKeys(string arr[100], int arrLength)
	{

		for (short i = 0; i < arrLength; i++) {

			arr[i] = GenerateKey();
		}
	}
	static void Swap(int& A, int& B) {

		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(double& A, double& B) {

		double Temp;

		Temp = A;
		A = B;
		B = Temp;

	}
	static void Swap(bool& A, bool& B) {

		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(char& A, char& B) {

		char Temp;

		Temp = A;
		A = B;
		B = Temp;

	}
	static void Swap(string& A, string& B) {
		string Temp;

		Temp = A;
		A = B;
		B = Temp;


	}
	static void Swap(clsDate& A, clsDate& B) {

		clsDate::SwapDates(A, B);
	}
	static void ShuffleArray(int arr[], int arrLength) {

		for (int i = 0; i < arrLength; i++)
		{

			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}
	static void ShuffleArray(string arr[], int arrLength) {

		for (int i = 0; i < arrLength; i++)
		{

			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}
	static string EncryptText(string Text, short EncryptionKey = 6) {

		for (short i = 0; i < Text.length(); i++) {

			Text[i] = char((int)Text[i] + EncryptionKey);

		}
		return Text;
	}
	static string DecryptText(string Text, short EncryptionKey = -6) {

		EncryptText(Text, EncryptionKey);
		return Text;
	}
	static string NumberToText(float number) {
		if (number < 0) {
			return "Negative " + NumberToText(-number);
		}

		if (number == 0) {
			return "Zero";  // Return "Zero" for 0.
		}

		// Handle integer part
		int integerPart = static_cast<int>(number);
		string result;

		static const string arr1[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
											 "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
											 "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
											 "Nineteen" };

		static const string arr2[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty",
											 "Sixty", "Seventy", "Eighty", "Ninety" };

		if (integerPart < 20) {
			result += arr1[integerPart] + " ";
		}
		else if (integerPart < 100) {
			result += arr2[integerPart / 10] + " " + arr1[integerPart % 10] + " ";
		}
		else if (integerPart < 1000) {
			result += arr1[integerPart / 100] + " Hundred " + NumberToText(static_cast<float>(integerPart % 100));
		}
		else if (integerPart < 1000000) {
			result += NumberToText(static_cast<float>(integerPart / 1000)) + " Thousand " + NumberToText(static_cast<float>(integerPart % 1000));
		}
		else if (integerPart < 1000000000) {
			result += NumberToText(static_cast<float>(integerPart / 1000000)) + " Million " + NumberToText(static_cast<float>(integerPart % 1000000));
		}
		else {
			result += NumberToText(static_cast<float>(integerPart / 1000000000)) + " Billion " + NumberToText(static_cast<float>(integerPart % 1000000000));
		}

		// Handle decimal part
		int decimalPart = static_cast<int>(round((number - integerPart) * 100)); // Convert to two decimal places
		if (decimalPart > 0) {
			result += "point ";
			if (decimalPart < 10) {
				result += "Zero ";  // Handle single-digit decimals
			}
			result += NumberToText(static_cast<float>(decimalPart));
		}

		return result;
	}


};

