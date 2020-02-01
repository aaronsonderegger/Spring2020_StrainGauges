#include "D:\Research\code\AveragingFilter\AverageFiltering.h"
#include "D:\Research\code\AveragingFilter\AverageFiltering.c"

int reading = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(A0);
  Serial.print(reading);
  Serial.print(",");
  reading = UpdateFilter(reading);
  Serial.println(reading);
}
