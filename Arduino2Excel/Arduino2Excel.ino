#include "ExcelComm.h"

const int PotPin = A0;
const int ButtonPin = 13;
ExcelCommunication IncomingData;
ExcelCommunication OutgoingData;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}


void loop() {
  if(Serial.available()){
    RecieveDataFromExcel(&IncomingData);
    OutgoingData[0] = IncomingData[0];
    for(int i = 1; i < IncomingData[0]; ++i)
    {
        val = analogRead(PotPin);
        if(i == 1){
          OutgoingData[i] = i;
        }
        else
        {
          OutgoingData[i] = val;
        }
        SendData2Excel(&OutgoingData);
    }
  }
}
  







// ************* Practice *********************
//  // put your main code here, to run repeatedly:
//  if(Serial.available())
//  {
//    int howMany = 0;
////    int index = 0;
//    char port;
//    while(Serial.available() > 0)
//    {
//      port = Serial.read();
//      if(port >= '0' && port <= '9'){
////        howMany[index] = 10*howMany[index] + (port - '0');
//        howMany = 10*howMany + (port - '0');
//      }
////      if(port == ',')
////      {
////        ++index;
////      }
//      delay(20);
//    }
//    for(int i = 0; i < 15; ++i)
//    {
//      Serial.println();
//      delay(20);
//    }
//    
//    for(int i = 1; i <= howMany; ++i)
//    {
//      val = analogRead(PotPin);
//      // CH1
//      Serial.print(i);
//      Serial.print(',');
//      // Channel 2
//      Serial.print(howMany);
//      Serial.print(',');
//      // Channel 3
//      Serial.print(val++);
////      Serial.print(howMany[1]);
//      Serial.print(',');
//      // Channel 4
//      Serial.print(val++);
////      Serial.print(howMany[2]);
//      Serial.print(',');
//      // Channel 5
//      Serial.print(val++);
////      Serial.print(howMany[3]);
//      Serial.print(',');
//      // Channel 6
//      Serial.print(val++);
//      Serial.print(',');
//      // Channel 7
//      Serial.print(val++);
//      Serial.print(',');
//      // Channel 8
//      Serial.print(val++);
//      Serial.print(',');
//      // Channel 9
//      Serial.print(val++);
//      Serial.print(',');
//      // Channel 10
//      Serial.print(val);
//      Serial.println();
//      delay(20);
//    }
//  }
