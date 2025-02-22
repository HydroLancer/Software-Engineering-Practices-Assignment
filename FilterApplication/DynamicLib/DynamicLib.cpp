// DynamicLib.cpp : Defines the exported functions for the DLL application.
//
#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition)
#endif

#include "stdafx.h"
#include "filter.h"
int stack;
int parameters[4];

int Filter(int data[], int count, const WCHAR* parameterString)
{
	wchar_t* buffer;
	wchar_t* tok;
	int numbers[2];

	int incrementer = 0;
	wchar_t copiedList[20];
	wcsncpy_s(copiedList, parameterString, 6);
	tok = wcstok_s(copiedList, L" ", &buffer);

	while (tok)
	{
		if (incrementer < 2)
		{
			numbers[incrementer] = _wtoi(tok);
			++incrementer;
			tok = wcstok_s(NULL, L" ", &buffer);
		}
		else if (incrementer > 2)
		{
			return InvalidParameters;
		}
		else
		{
			return UnknownError;
		}
	}
#ifdef _DEBUG
	for (int i = 0; i < 2; i++)
	{
		cout << "PARAMETER " << i << " " << numbers[i] << endl; //outputs parameter string, just in case.
	}
#endif

	for (int i = 0; i < count; i++)
	{
		#ifdef _DEBUG
		cout << data[i] << endl;
		#endif

		if (data[i] < numbers[0])
		{
			data[i] = numbers[0];
			cout << "Item " << i+1 << " in the array is now " << data[i] << endl;
		}
		else if (data[i] > numbers[1])
		{
			data[i] = numbers[1];
			cout << "Item " << i+1 << " in the array is now " << data[i] << endl;
		}
		else
		{
			data[i]; //is left unmodified.
			cout << "Item " << i+1 << " Was not modified." << endl;
		}
	}
	return count;
}
