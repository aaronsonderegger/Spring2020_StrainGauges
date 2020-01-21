#include "ExcelComm.h"

int main()
{
	ExcelCommunication Data;
	for(int i = 0; i < 10; ++i)
	{
		Data.Channel[i] = i;
	}
	
	SendData2Excel(&Data);

	return 0;
}