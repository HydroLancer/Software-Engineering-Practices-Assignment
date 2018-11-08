#ifndef HEADER_H
#define HEADER_H

#ifdef _UNICODE
#define WCHAR wchar_t
#else
#define WCHAR char
#endif
#include <string>
//Error codes

using namespace std;

int stack = 0;
const int Success = 0;
const int Failure = -1;
const int DllNotFound = -2;		// can't find dll to import
const int DllInvalidFormat = -3;	// Unable to find import function in the dll
const int UnknownError = -4;
const int InvalidParameters = -5;

//in SLL
extern int UseFilter(WCHAR* dllName, int data[], int count, WCHAR* parameterString);	//load DLL at Runtime from file and process data stored in the array using Filter() function FROM THE DLL
																				//passes the parameter string each time the function is called

extern int LoadMeasurements(string inputFile, int data[], int maxSize);				//Reads data from inputFile into array

extern int SaveMeasurements(WCHAR* outputFile, int data[], int maxSize);				//outputs data from the array into an output file

//in DLL
int Filter(int data[], int count, WCHAR* parameterString);						//applies algorithm to given data (this function is in DynamicLib)

#endif