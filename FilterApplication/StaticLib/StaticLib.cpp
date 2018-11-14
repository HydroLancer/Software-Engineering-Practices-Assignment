#include "stdafx.h"
#include "filter.h"
using namespace std;

typedef int(*FilterProc)(int[], int, const WCHAR*);

int UseFilter(const WCHAR* dllName, int data[], int count, const WCHAR* parameterString)
{
	HINSTANCE loadLib = LoadLibrary(dllName);
	FilterProc Filter;

	if (loadLib != NULL)
	{
		Filter = (FilterProc)GetProcAddress(loadLib, "Filter");

	if (NULL != Filter)
		{
			Filter(data, count, parameterString);
			
			return Success;
		}
		return DllInvalidFormat;
	}
	else
	{
		return DllNotFound;
	}
	return UnknownError;
}

int LoadMeasurements(const WCHAR* inputFile, int data[], int maxSize)
{
	ifstream input(inputFile);
	if (!input)
	{
		cout << "Error Code: " << InvalidParameters << endl;
		return InvalidParameters;
	}

	while (!input.eof())				//makes sure it's only going to run the loop if a file actually loads
	{
		for (int i = 0; i < MAX_DATA; i++)
		{
			input >> data[i];
			stack++;					//used for determining how much data is actually in the array, rather than going through the entire empty array. 
			if (input.eof())
			{
				return Success;			//just stops the loop. 
			}
		}
	}
	return UnknownError; //if it fails to run the loop, the file doesn't end for some reason, yet the file loads, gives this. 
}

int SaveMeasurements(const WCHAR* outputFile, int data[], int maxSize)
{
	ofstream output(outputFile);
	if (!output)
	{
		cout << "Error Code: " << InvalidParameters << endl;
		return InvalidParameters;
	}
	else
	{
		output << "Filtered Array: " << endl;
		for (int i = 0; i < maxSize; i++)
		{
			output << data[i] << endl;
		}
		output.close();
		return Success;
	}
	return UnknownError;
	
}

