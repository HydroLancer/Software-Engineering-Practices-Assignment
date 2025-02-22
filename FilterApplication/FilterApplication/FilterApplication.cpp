// FilterApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//input file is input1.txt
//#include "stdafx.h" (comment out when on laptop..)
#include "pch.h"
#include "filter.h"

#define ASEXPORT
const WCHAR* outputFile = (L"output.txt");
const WCHAR* inputFile = (L"input1.txt");
const WCHAR* parameterString = { L"-1 20" };
const WCHAR* dllName = (L"DynamicLib.dll");
int stack;
int compare = 10;

int main()
{
	stack = 0;
	int data[MAX_DATA];

	//outputs success code (0), bad input file (-5), or Unknown Error (-4)
	cout << "Items in array " << LoadMeasurements(inputFile, data, MAX_DATA) << endl << endl;
	
#ifdef _DEBUG
	for (int i = 0; i < stack; i++)
	{
		cout << data[i] << endl;		// Only outputs data within the array when in debug mode into a console window.
	}

#endif // _DEBUG
	cout << "Items Processed: "<< UseFilter(dllName, data, stack, parameterString) << endl;

	//makes a file called output.txt. Returns code 0 for success, -5 for bad filename (should be no issue), -4 for an unknown error
	cout << "Amount of numbers written to file: " << SaveMeasurements(outputFile, data, stack) << endl;
	system("pause");
}

