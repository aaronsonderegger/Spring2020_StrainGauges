#ifndef FILTERING_H
#define FILTERING_H

void DebugFilter();

#define NumberOfReadings 10			// NumberOfReadings I want to filter
#define InvalidFilterReading 2000			// The analog read function reads vaules of 0-1023

// Write Test for these
int GetFilteredSignal(const int* signals);
void StartFilter(int* readings);
void UpdateFilter(const int reading, int* signals);
void RestartFilter(int* signals);

#endif