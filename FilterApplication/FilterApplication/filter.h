#ifndef HEADER_H
#define HEADER_H

#ifdef _UNICODE
#define WCHAR wchar_t
#else
#define WCHAR char
#endif

//Error codes
extern const int Success = 0;
extern const int Failure = -1;
extern const int DllNotFound = -2;		// can't find dll to import
extern const int DllInvalidFormat = -3;	// Unable to find import function in the dll
extern const int UnknownError = -4;
extern const int InvalidParameters = -5;

extern WCHAR* inputFile = (WCHAR*) ("input1.txt");

const int MAX_DATA = 1000;  // the maximum size of the array for loading data 
int DATE_SIZE = 19;  // the maximum size of a date as a null-terminated string

//in SLL
int UseFilter(WCHAR* dllName, int data[], int count, WCHAR* parameterString);	//load DLL at Runtime from file and process data stored in the array using Filter() function FROM THE DLL
																				//passes the parameter string each time the function is called

int LoadMeasurements(WCHAR* outputFile, int data[], int maxSize);				//Reads data from inputFile into array

int SaveMeasurements(WCHAR* outputFile, int data[], int maxSize);				//outputs data from the array into an output file

//in DLL
int Filter(int data[], int count, WCHAR* parameterString);						//applies algorithm to given data (this function is in DynamicLib)

#endif //HEADER_H