#include "Filter.h"

class Filter
{
private:
	int* Signals;
	int NumberOfSignals;
	
	void AppendSignals(int reading)
	{
		for(int i = 0; i < NumberOfSignals; ++i)
		{
			if(i < NumberOfSignals - 1)
			{
				Signals[i] = Signals[i+1];
			}
			else
			{
				Signals[i] = reading;
			}
		}
	}

public:
	int InvalidFilterReading = 2000;	// Readings are 0-1023

	Filter()
	{
		NumberOfSignals = 10;
		Signals = new int[NumberOfSignals];
		for(int i = 0; i < NumberOfSignals; ++i)
		{
			Signals[i] = InvalidFilterReading;
		}
	}
	Filter(int _numSignals)
	{
		NumberOfSignals = _numSignals;
		Signals = new int[NumberOfSignals];
	}

	~Filter()
	{
		delete Signals;
	}

	int GetAverageSignal()
	{
		int value = 0;
		int length = 0;
		for(int i = 0; i < NumberOfSignals; ++i)
		{
			if(Signals[i] != InvalidFilterReading)
			{
				value += Signals[i];
				++length;
			}
		}
		if(length == 0)
		{
			return InvalidFilterReading;
		}
		return value/length;
	}

	void UpdateFilter(const int reading)
	{
		self.AppendSignals(reading);
	}

	int GetFilterVariance()
	{
		int ave = self.GetAverageSignal();
		int variance = 0;
		for(int i = 0; i < NumberOfSignals; ++i)
		{
			variance = 
		}
	}

	void RestartFilter()
	{
		for(int i = 0; i < NumberOfSignals; ++i)
		{
			Signals[i] = InvalidFilterReading;
		}
	}
};

// int GetFilteredSignal(const int* signals);
// void StartFilter(int* readings);
// void UpdateFilter(const int reading, int* signals);
// void RestartFilter(int* signals);