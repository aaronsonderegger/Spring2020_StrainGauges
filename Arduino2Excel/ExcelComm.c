#include "ExcelComm.h"

#define IS_ARDUINO 0

// #define MyPrint(x) (Serial.print(x))
// #define MyPrintLn() (Serial.println())

#include <stdio.h>
#define MyPrint(x) printf("%c",(char)x)
#define MyPrintLn() printf("\n")



void SendData2Excel(ExcelCommunication* Data)
{
	for(int i = 0; i < 10; ++i)
	{
		if(Data->Channel[i] != Invalid)
		{
			#ifdef Serial
				Serial.print(Data->Channel[i]);
			#else
				printf("%d",Data->Channel[i]);
			#endif
		}

		if(i < 9)
		{
			#ifdef Serial
				Serial.print(',');
			#else
				printf(",");
			#endif
		}
		else
		{
			#ifdef Serial
				Serial.println();
			#else
				printf("\n");
			#endif
		}
	}
}

void RecieveDataFromExcel(ExcelCommunication* Data)
{
	#ifdef Serial
		int totalValue = 0;
		char index = 0;
		char incomingChar;

		while(Serial.available() > 0)
		{
			incomingChar = Serial.read();
			if(incomingChar >= '0' && incomingChar <= '9')
			{
				totalValue = 10*totalValue + (incomingChar - '0');
			}

			if(incomingChar == ',')
			{
				Data->Channel[index] = totalValue
				totalValue = 0;
				++index;
			}
			delay(20);  	// waits for the incoming character to be processed.
		}
	#else
		printf("Put work into reading from a Serial Port\n");
	#endif
	
}