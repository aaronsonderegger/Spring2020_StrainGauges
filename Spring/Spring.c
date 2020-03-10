#include "C:\Users\User\Desktop\Spring 2020 Research\Code\Spring\Spring.h"

// *** Pre-Compiler ***
#define EXTENDED_LEG 524   	// Leg Extended Limit value
#define COMPRESSED_LEG 438 	// Leg Compressed Limit value
#define SpringK 0.010     	// [lb/milli-in]  10/1000 (10 lbs/in)
#define X_MIN 0           	// [milli-in]    0.0*1000 
#define X_MAX 1780        	// [milli-in]   1.78*1000

// *** Global Variables ***
int LinearPotReadings[NumberOfReadings] = {};
int AnalogPin;


// *** Public Functions ***
// Setup Proceedure
void SetSpringAnalogPin(int pin)
{
	AnalogPin = pin;
}

// Update the reading of the Linear Pot
void UpdateSpringFilter()
{
	UpdateFilter(analogRead(AnalogPin), LinearPotReadings);
}

// Using Measured Values to Calculate Force of Spring
int CalculateSpringForce()
{
	int filterSignal = GetFilteredSignal(LinearPotReadings);
	if(filterSignal > EXTENDED_LEG)
	{
		filterSignal = EXTENDED_LEG;
	}

	if(filterSignal < COMPRESSED_LEG)
	{
		filterSignal = COMPRESSED_LEG;
	}

	return -0.6961*filterSignal + 364.65;	// [lbs] Equation from excel and lab scale
}