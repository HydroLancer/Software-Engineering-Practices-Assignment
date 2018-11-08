#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "filter.h"
using namespace std;

int UseFilter(WCHAR* dllName, int data[], int count, WCHAR* parameterString)
{
	return 0;
}

int LoadMeasurements(WCHAR* inputFile, int data[], int maxSize)
{
	ifstream input(inputFile);
	if (!input)
	{
		cout << "Error Code: " << InvalidParameters;
	}

	while (!input.eof())
	{
		for (int i = 0; i < maxSize; i++)
		{
			input >> data[i];
		}
	}
	return 0;
}

int Filter(int data[], int count, WCHAR* parameterString)
{
	return 0 ;
}

int SaveMeasurements(WCHAR* outputFile, int data[], int maxSize)
{
	return 0;
}