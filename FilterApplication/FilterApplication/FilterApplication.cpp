// FilterApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//input file is input1.txt

//#include "stdafx.h"
#include "pch.h"
#include "filter.h"

int main()
{
	int data[MAX_DATA];

	LoadMeasurements(inputFile, data, MAX_DATA);

#ifdef _DEBUG
	for (int i = 0; i < stack; i++)
	{
		cout << data[i] << endl;
	}
#endif // _DEBUG

	cout << "array loaded" << endl;
	system("pause");
}

