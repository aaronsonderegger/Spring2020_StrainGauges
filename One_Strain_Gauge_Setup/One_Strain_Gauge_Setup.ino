//** Pre-Compiling Things **
#include "C:\Users\User\Desktop\Spring 2020 Research\Code\AveragingFilter\AverageFiltering.h"
#include "C:\Users\User\Desktop\Spring 2020 Research\Code\AveragingFilter\AverageFiltering.c"
#define __DEBUG__ true

//** Structures **
struct Forces{
  int VerticleForce;
  int HorizontalForce;
};

//** Global Variables **
const int StrainGaugeSensor = A0;
const int StrainGaugeReferenceSensor = A1;
int StrainReference[NumberOfReadings];
int StrainReadings[NumberOfReadings];
int LegAngle = 0;       // Need to Get this from main controller
Forces CalculatedForces;



//** Setup Steps **
void setup() {
  // Need to initialize something to get the leg angle. Communication Protocol.
  // Need something to send the strain reading or force calculation to Brains/Controller
  Serial.begin(9600);
  StartFilter(StrainReference);
  StartFilter(StrainReadings);
}

//** Main **
void loop() {
  //** Gather Data From Sensors **
  UpdateFilter(analogRead(StrainGaugeSensor), StrainReadings);
  UpdateFilter(analogRead(StrainGaugeReferenceSensor), StrainReference);
//  LegAngle = QueerySomething

  //** Process Data **
  // CalculatedForces.VerticleForce = GetFilteredSignal(StrainReadings);
  // CalculatedForces.HorizontalForce = GetFilteredSignal(StrainReference);
  
  //** Send Data **
//  sendData(Forces)

  //** Debuging Things **
  if(__DEBUG__){
    Serial.print(analogRead(StrainGaugeSensor));
    Serial.print(" ");
    Serial.print(analogRead(StrainGaugeReferenceSensor));
    Serial.print(" ");
    Serial.print(GetFilteredSignal(StrainReadings));
    Serial.print(" ");
    Serial.println(GetFilteredSignal(StrainReference));
    
  }
  
}
