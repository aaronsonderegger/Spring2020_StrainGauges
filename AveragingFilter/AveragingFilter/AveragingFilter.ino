//#include "D:\Research\code\AveragingFilter\AverageFiltering.h"
//#include "D:\Research\code\AveragingFilter\AverageFiltering.c"

#include "C:\Users\User\Desktop\Spring 2020 Research\Code\AveragingFilter\AverageFiltering.h"
#include "C:\Users\User\Desktop\Spring 2020 Research\Code\AveragingFilter\AverageFiltering.c"
#include "C:\Users\User\Desktop\Spring 2020 Research\Code\Spring\Spring.h"
#include "C:\Users\User\Desktop\Spring 2020 Research\Code\Spring\Spring.c"


// *** Global Variables ***
int changingSignal[NumberOfReadings] = {};
int staticSignal[NumberOfReadings] = {};


// *** Function Prototypes ***
void printResults(void);
void UpdateFitlers(void);


// *** Main Setup ***
void setup() { 
  StartFilter(changingSignal);
  StartFilter(staticSignal);
  SetSpringAnalogPin(A2);
  
  Serial.begin(9600);
}

// *** Main ***
void loop() {
  UpdateFilters();
  printResults();  
}


// *** Helper Functions ***
void UpdateFilters(void)
{
  UpdateFilter(analogRead(A0), changingSignal);
  UpdateFilter(analogRead(A1), staticSignal);
  UpdateSpringFilter();
}

void printResults(void)
{
  Serial.print( GetFilteredSignal(changingSignal ) );
  Serial.print(" ");
  Serial.print( GetFilteredSignal(staticSignal) ); 
  Serial.print(" ");
  Serial.println( CalculateSpringForce() ); 

}
