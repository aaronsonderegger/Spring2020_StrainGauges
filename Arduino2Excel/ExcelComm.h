#ifndef EXCELCOMM_H
#define EXCELCOMM_H

typedef struct{
	int Channel[10]; 
} ExcelCommunication;

void SendData2Excel(ExcelCommunication* Data);
void RecieveDataFromExcel(ExcelCommunication* Data);

enum SendingInfo {SendContinous = 0, Send15 = 1, Invalid = 112233};  

#endif 