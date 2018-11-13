// FilterApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//input file is input1.txt
//#include "stdafx.h"
#include "pch.h"
#include "filter.h"

#include <iostream>

string outputFile = "output.txt";
string inputFile = "input1.txt";
int stack;

int main()
{
	stack = 0;
	int data[MAX_DATA];

	//outputs success code (0), bad input file (-5), or Unknown Error (-4)
	cout << "Code: " << LoadMeasurements(inputFile, data, MAX_DATA) << endl << endl;

#ifdef _DEBUG
	for (int i = 0; i < stack; i++)
	{
		cout << data[i] << endl;
	}
#endif // _DEBUG

	//makes a file called output.txt. Returns code 0 for success, -5 for bad filename (should be no issue), -4 for an unknown error
	cout << "Code: " << SaveMeasurements(outputFile, data, stack) << endl;

	
	system("pause");
}

