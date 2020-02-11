// ** Preprocessor Commands **
#include "D:\Research\code\AveragingFilter\AverageFiltering.h"
#include "D:\Research\code\AveragingFilter\AverageFiltering.c"
#define Sensor1 A0
#define Sensor2 A1 
#define Sensor3 A2
#define Sensor4 A3

// ** Data Type Definitions **

// ** Global Variables **
int reading1 = 0;
int reading2 = 0;
int reading3 = 0;
int reading4 = 0;

// ** Function Prototypes **

// ** Main Functions **
void setup() {
  Serial.begin(9600);
}

void loop() {
  reading1 = analogRead(Sensor1);
  reading2 = UpdateFilter(analogRead(Sensor2));
//  reading2 = analogRead(Sensor2);
//  reading3 = analogRead(Sensor3);
//  reading4 = analogRead(Sensor4);

  Serial.print(reading1);
  Serial.print(" ");
  Serial.print(reading2);
//  Serial.print(" ");
//  Serial.print(reading3);
//  Serial.print(" ");
//  Serial.print(reading4);
  Serial.println();
}

// ** Helper Functions **

