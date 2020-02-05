//** Pre-Compiling Things **
#include "C:\Users\User\Desktop\Spring 2020 Research\Code\AveragingFilter\AverageFiltering.h"
#include "C:\Users\User\Desktop\Spring 2020 Research\Code\AveragingFilter\AverageFiltering.c"
struct Forces{
  int VerticleForce;
  int HorizontalForce;
};
#define __DEBUG__ true


//** Global Variables **
const int StrainGaugeSensor = A0;
int StrainReading = 0;
int LegAngle = 0;
Forces CalculatedForces;



//** Setup Steps **
void setup() {
  // Need to initialize something to get the leg angle. Communication Protocol.
  // Need something to send the strain reading or force calculation to Brains/Controller
  Serial.begin(9600);
  if(__DEBUG__){
//    Serial.println("Strain:,Verticle,Horizontal:");
  }
}

//** Main **
void loop() {
  //** Gather Data From Sensors **
  StrainReading = UpdateFilter( analogRead(StrainGaugeSensor) );
  analogRead(A1);
//  LegAngle = QueerySomething

  //** Process Data **
  CalculatedForces.VerticleForce = StrainReading + 5;
  CalculatedForces.HorizontalForce = StrainReading + 10;
  
  //** Send Data **
//  sendData(Forces)

  //** Debuging Things **
  if(__DEBUG__){
//    Serial.print("STrain: ");
    Serial.print(StrainReading);
    Serial.print(" ");
//    Serial.print(",Vertical: ");
    Serial.print(CalculatedForces.VerticleForce);
    Serial.print(" ");
//    Serial.print(",Horizontal: ");
    Serial.println(CalculatedForces.HorizontalForce);
//    Serial.println();
  }
  
}
