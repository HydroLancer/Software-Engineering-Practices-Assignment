#ifndef HEADER_H
#define HEADER_H

#ifndef ASEXPORT
#define DLLIMPORTOREXPORT dllexport
#else
#define DLLIMPORTOREXPORT dllimport
#endif

#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

//parameters for functions both in SLL and DLL.
extern const WCHAR* outputFile;
extern const WCHAR* inputFile;
extern const WCHAR* parameterString;
extern const WCHAR* dllName;
extern int compare;				//used to check if a member of the array is lower or higher than.

extern int stack;				//increments every time an item is read from a file and put into data[] 
	//not necessarily a stack, just the best way I could label something
	//that only incremented until it ran out of stuff - So when outputting and processing
	//it didn't go through the whole array (which can contain 1000 elements)

//Error codes
const int Success = 0;
const int Failure = -1;
const int DllNotFound = -2;			//can't find dll to import
const int DllInvalidFormat = -3;	//Unable to find import function in the dll
const int UnknownError = -4;		//only returns when any expected outcomes fail.
const int InvalidParameters = -5;	//returns when filenames or variable names are wrong

const int MAX_DATA = 1000;			// the maximum size of the array for loading data 
const int DATE_SIZE = 19;			// the maximum size of a date as a null-terminated string

//in SLL
int UseFilter(const WCHAR* dllName, int data[], int count, const WCHAR* parameterString);			//load DLL at Runtime from file and process data stored in the array using Filter() function FROM THE DLL
																									//passes the parameter string each time the function is called

int LoadMeasurements(const WCHAR* inputFile, int data[], int maxSize);								//Reads data from inputFile into array

int SaveMeasurements(const WCHAR* outputFile, int data[], int maxSize);								//outputs data from the array into an output file

#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface – with no name mangling
#endif

//in DLL
_declspec(DLLIMPORTOREXPORT) int Filter(int data[], int count, const WCHAR* parameterString);		//applies algorithm to given data (this function is in DynamicLib)

#ifdef __cplusplus    // If used by C++ code, 
}  // end extern "C"
#endif

#endif