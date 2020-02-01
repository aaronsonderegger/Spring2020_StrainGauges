#include<stdio.h>
#include "AverageFiltering.h"


#ifndef __cplusplus
	typedef char bool;
	#define true 1
	#define false 0
	static int Readings[NumberOfReadings] = {[0 ... NumberOfReadings-1] = InvalidFilterReading};
#else
	static int Readings[NumberOfReadings] = {InvalidFilterReading,InvalidFilterReading,
											 InvalidFilterReading,InvalidFilterReading,
											 InvalidFilterReading,InvalidFilterReading,
											 InvalidFilterReading,InvalidFilterReading,
											 InvalidFilterReading,InvalidFilterReading};

#endif

static char DEBUG = 0;


//** Private Functions **
void AppendSignals(const int reading)
{
	for(int i = 0; i < NumberOfReadings; ++i)
	{
		if(i < NumberOfReadings - 1)
		{
			Readings[i] = Readings[i+1];
		}
		else
		{
			Readings[i] = reading;
		}
	}
}



//** Public Functions ** 
void DebugFilter()
{
	DEBUG = true;
}

int UpdateFilter(const int reading)
{
	AppendSignals(reading);
	return GetFilteredSignal();
}

int GetFilteredSignal()
{
	int value = 0;
	int length = 0;
	for(int i = 0; i < NumberOfReadings; ++i)
	{
		if(Readings[i] != InvalidFilterReading)
		{
			value += Readings[i];
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

void RestartFilter()
{
	for(int i = 0; i < NumberOfReadings; ++i)
	{
		Readings[i] = InvalidFilterReading;		
	}
}