#ifndef HEADER_H
#define HEADER_H

#ifdef _UNICODE
#define WCHAR wchar_t
#else
#define WCHAR char
#endif


#ifndef ASEXPORT
#define DLLIMPORTOREXPORT dllimport
#else
#define DLLIMPORTOREXPORT dllimport
#endif

#include <string>
#include <fstream>
#include <iostream>

//Error codes

using namespace std;

extern string outputFile;
extern string inputFile;
extern int stack;

const int Success = 0;
const int Failure = -1;
const int DllNotFound = -2;		// can't find dll to import
const int DllInvalidFormat = -3;	// Unable to find import function in the dll
const int UnknownError = -4;
const int InvalidParameters = -5;

const int MAX_DATA = 1000;  // the maximum size of the array for loading data 
const int DATE_SIZE = 19;  // the maximum size of a date as a null-terminated string

//in SLL
extern int UseFilter(WCHAR* dllName, int data[], int count, WCHAR* parameterString);	//load DLL at Runtime from file and process data stored in the array using Filter() function FROM THE DLL
																				//passes the parameter string each time the function is called

extern int LoadMeasurements(string inputFile, int data[], int maxSize);				//Reads data from inputFile into array

extern int SaveMeasurements(string outputFile, int data[], int maxSize);				//outputs data from the array into an output file

//in DLL
_declspec(DLLIMPORTOREXPORT) int Filter(int data[], int count, WCHAR* parameterString);						//applies algorithm to given data (this function is in DynamicLib)

#endif