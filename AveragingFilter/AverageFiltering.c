#include<stdio.h>
#include "AverageFiltering.h"


#ifndef __cplusplus
	typedef char bool;
	#define true 1
	#define false 0
	// static int Readings[NumberOfReadings] = {[0 ... NumberOfReadings-1] = InvalidFilterReading};
#else
	// static int Readings[NumberOfReadings] = {InvalidFilterReading,InvalidFilterReading,
	// 										 InvalidFilterReading,InvalidFilterReading,
	// 										 InvalidFilterReading,InvalidFilterReading,
	// 										 InvalidFilterReading,InvalidFilterReading,
	// 										 InvalidFilterReading,InvalidFilterReading};

#endif

static char DEBUG = 0;


//** Private Functions **
void AppendSignals(const int reading, int* signals)
{
	for(int i = 0; i < NumberOfReadings; ++i)
	{
		if(i < NumberOfReadings - 1)
		{
			signals[i] = signals[i+1];
		}
		else
		{
			signals[i] = reading;
		}
	}
}



//** Public Functions ** 
int GetFilteredSignal(const int* signals);
void StartFilter(int* signals);
void UpdateFilter(const int reading, int* signals);
void RestartFilter(int* signals);


void DebugFilter()
{
	DEBUG = true;
}

void StartFilter(int* signals)
{
	for(int i = 0; i < NumberOfReadings; ++i)
	{
		signals[i] = InvalidFilterReading; 
	}
}


void UpdateFilter(const int reading, int* signals)
{
	AppendSignals(reading, signals);
}


int GetFilteredSignal(const int* signals)
{
	int value = 0;
	int length = 0;
	for(int i = 0; i < NumberOfReadings; ++i)
	{
		if(signals[i] != InvalidFilterReading)
		{
			value += signals[i];
			++length;
		}
	}
	if(length == 0)
	{
		return InvalidFilterReading;
	}
	// printf("%d\n", value);
	return value/length;
}

void RestartFilter(int* signals)
{
	for(int i = 0; i < NumberOfReadings; ++i)
	{
		signals[i] = InvalidFilterReading;		
	}
}