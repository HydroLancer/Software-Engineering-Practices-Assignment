// DynamicLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "filter.h"
int stack;
int parameters[4];

int Filter(int data[], int count, const WCHAR* parameterString)
{


	for (int i = 0; i < 4; i++)
	{
		parameters[i] = parameterString[i] - '0';
	#ifdef  _DEBUG
		cout << "Entry " << i << " in the array is: " << parameters[i] << endl;
	#endif //  _DEBUG
		
	}

	//holy crap this is patchy but it does the job... If the parameters are between 0 and 9...
	//find a way of.. "combining" 2 intergers that doesn't involving adding them together.
	for (int i = 0; i < count; i++)
	{
		if (data[i] < parameters[0])
		{
			data[i] = parameters[0];
		}
		else if (data[i] > parameters[2])
		{
			data[i] = parameters[2];
		}
		else
		{
			data[i];
		}
	}
	for (int i = 0; i <= count; i++)
	{
		if (i == count)
		{
			return count;
		}
		cout << "New entry for slot " << i << " is: " << data[i] << endl;
		
	}

	return Failure;
}
