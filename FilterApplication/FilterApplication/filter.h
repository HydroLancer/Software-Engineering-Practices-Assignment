#ifndef HEADER_H
#define HEADER_H

#ifdef _UNICODE
#define WCHAR wchar_t
#else
#define WCHAR char
#endif

//in SLL
int UseFilter(WCHAR* dllName, int data[], int count, WCHAR* parameterString);	//load DLL at Runtime from file and process data stored in the array using Filter() function FROM THE DLL
																				//passes the parameter string each time the function is called

int LoadMeasurements(WCHAR* outputFile, int data[], int maxSize);				//Reads data from inputFile into array

int SaveMeasurements(WCHAR* outputFile, int data[], int maxSize);				//outputs data from the array into an output file

//in DLL
int Filter(int data[], int count, WCHAR* parameterString);						//applies algorithm to given data (this function is in DynamicLib)

#endif //HEADER_H