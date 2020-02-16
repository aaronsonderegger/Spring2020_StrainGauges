#include<stdio.h>
#include "AverageFiltering.h"

#define TotalTests 13

// ** ProtoType Functions **
int	Test1();	// Test of UpdateFilter(const int reading) Function, Test before anything is filtered
int Test2();	// Test of UpdateFilter(const int reading) Function, Test the Filtering of a signal of 1 reading
int Test3();	// Test of UpdateFilter(const int reading) Function, Test 20 signals
int Test4();	// Test the RestartFilter() Function
int Test5();	// Test the GetFilteredSignal() Function
int Test6();	// Test of UpdateFilter(const int reading) Function, Test 100 signals
		// Tests for multiple signals.
int Test11();	// Similar to test1
int Test12();	// Similar to test2
int Test13();	// Similar to test3
int Test14();	// Similar to test4
int Test15(); 	// Similar to test5
int Test16();	// Similar to test6
int Test17();	// Resets 1 filter but not others

void ReadFile();	// This is a scratch to see if I can read a file the right way

// ** Main Function **
int main()
{
	int testPassed = 0;
	DebugFilter();
	Aaron = 5;
	// * Run Tests *
	testPassed += Test1();
	testPassed += Test2();
	testPassed += Test3();
	testPassed += Test4();
	testPassed += Test5();
	testPassed += Test6();
		// Test for multiple signals
	testPassed += Test11(); 
	testPassed += Test12();	
	testPassed += Test13();	
	testPassed += Test14();	
	testPassed += Test15(); 	
	testPassed += Test16();	
	testPassed += Test17();

	printf("%d of %d passed\n",testPassed, TotalTests );

	ReadFile();
	return 0;
}

// int GetFilteredSignal(const int* signals);
// void StartFilter(int* signals);
// void UpdateFilter(const int reading, int* signals);
// void RestartFilter(*int signals);

//** Helper Functions **
// Test of UpdateFilter(const int reading) Function, Test before anything is filtered
int Test1() 
{
	int signal[NumberOfReadings];
	StartFilter(signal);
	if (GetFilteredSignal(signal) == InvalidFilterReading)
	{
		return 1;
	}
	else
	{
		printf("Test1 Failed\n");
		return 0;
	}
}

// Test of UpdateFilter(const int reading) Function, Test the Filtering of a signal of 1 reading
int Test2()
{
	int sgnl = 255;
	int signals[NumberOfReadings];
	StartFilter(signals);
	UpdateFilter(sgnl, signals);
	if(GetFilteredSignal(signals) == sgnl)
	{
		return 1;
	}
	else
	{
		printf("Test2 Failed\n");
		return 0;
	}
}

// Test of UpdateFilter(const int reading) Function, Test 20 signals
int Test3()
{
	int correctValue = 0;
	int lastNumber = 0;

	int signals[NumberOfReadings];
	StartFilter(signals);
	for(int i = 1; i <= NumberOfReadings; ++i)
	{	
		correctValue += i;
		UpdateFilter(i, signals);
		lastNumber++;
	}

	// printf("%d %d %d %d\n",correctValue,lastNumber,correctValue/lastNumber, tmp );
	if(GetFilteredSignal(signals) == correctValue/lastNumber)
	{
		return 1;
	}
	else{
		printf("Test3 Failed\n");
		return 0;
	}
}

// Test the RestartFilter() Function
int Test4()
{
	int signals[NumberOfReadings];
	StartFilter(signals);
	for(int i = 1; i <= 20; ++i)
	{
		UpdateFilter(i, signals);
	}

	RestartFilter(signals);
	if(GetFilteredSignal(signals) == InvalidFilterReading)
	{
		return 1;
	}
	else
	{	
		printf("Test4 Failed\n");
		return 0;
	}
}

// Test the GetFilteredSignal() Function
int Test5()
{
	int signals[NumberOfReadings];
	StartFilter(signals);
	UpdateFilter(10, signals);
	UpdateFilter(10, signals);
	if(GetFilteredSignal(signals) == 10)
	{
		return 1;
	}
	else
	{
		printf("Test5 Failed\n");
		return 0;
	}
}

// Test of UpdateFilter(const int reading) Function, Test 100 signals
int Test6()
{
	int signals[NumberOfReadings];
	StartFilter(signals);

	int correctValue = 0;
	int counter = 0;
	for(int i = 1; i <= 100; ++i)
	{	
		if(i > 100 - NumberOfReadings)
		{
			correctValue += i;
			++counter;
		}
		UpdateFilter(i, signals);
	}
	int tmp = GetFilteredSignal(signals);

	// printf("%d %d %d %d\n",correctValue,NumberOfReadings,correctValue/NumberOfReadings, tmp );
	if(GetFilteredSignal(signals) == correctValue/NumberOfReadings)
	{
		return 1;
	}
	else{
		printf("Test6 Failed\n");
		return 0;
	}
}

// Multiple Signals
int Test11()
{
	int signal1[NumberOfReadings];
	int signal2[NumberOfReadings];
	int signal3[NumberOfReadings];
	StartFilter(signal1);
	StartFilter(signal2);
	StartFilter(signal3);

	if (GetFilteredSignal(signal1) == InvalidFilterReading 
		&& GetFilteredSignal(signal2) == InvalidFilterReading
		&& GetFilteredSignal(signal3) == InvalidFilterReading)
	{
		return 1;
	}
	else
	{
		printf("Test11 Failed\n");
		return 0;
	}
}

int Test12()
{
	int signal1[NumberOfReadings];
	int signal2[NumberOfReadings];
	int signal3[NumberOfReadings];
	StartFilter(signal1);
	StartFilter(signal2);
	StartFilter(signal3);
	int sgnl1 = 255;
	int sgnl2 = 370;
	int sgnl3 = 14; 

	UpdateFilter(sgnl1, signal1);
	UpdateFilter(sgnl2, signal2);
	UpdateFilter(sgnl3, signal3);

	if(GetFilteredSignal(signal1) == sgnl1
	   && GetFilteredSignal(signal2) == sgnl2
	   && GetFilteredSignal(signal3) == sgnl3)
	{
		return 1;
	}
	else
	{
		printf("Test12 Failed\n");
		return 0;
	}
}

int Test13()
{
	int signal1[NumberOfReadings];
	int signal2[NumberOfReadings];
	int signal3[NumberOfReadings];
	StartFilter(signal1);
	StartFilter(signal2);
	StartFilter(signal3);


	int correctValue1 = 0;
	int correctValue2 = 0;
	int correctValue3 = 0;
	int lastNumber = 0;
	// Signal1
	for(int i = 1; i <= NumberOfReadings; ++i)
	{	
		correctValue1 += i;
		correctValue2 += 2*i;
		correctValue3 += i + 10;
		UpdateFilter(i, signal1);
		UpdateFilter(2*i, signal2);
		UpdateFilter(i+10, signal3);
		lastNumber++;
	}


	if(GetFilteredSignal(signal1) == correctValue1/lastNumber
	   && GetFilteredSignal(signal2) == correctValue2/lastNumber
	   && GetFilteredSignal(signal3) == correctValue3/lastNumber)
	{
		return 1;
	}
	else{
		printf("Test13 Failed\n");
		return 0;
	}
}

int Test14()
{
	int signal1[NumberOfReadings];
	int signal2[NumberOfReadings];
	int signal3[NumberOfReadings];
	StartFilter(signal1);
	StartFilter(signal2);
	StartFilter(signal3);

	for(int i = 1; i <= 20; ++i)
	{
		UpdateFilter(i+50, signal1);
		UpdateFilter(i*3, signal2);
		UpdateFilter(i-10, signal3);
	}

	RestartFilter(signal1);
	RestartFilter(signal2);
	RestartFilter(signal3);
	if(GetFilteredSignal(signal1) == InvalidFilterReading
	   && GetFilteredSignal(signal2) == InvalidFilterReading
	   && GetFilteredSignal(signal3) == InvalidFilterReading
	)
	{
		return 1;
	}
	else
	{	
		printf("Test14 Failed\n");
		return 0;
	}
}

int Test15()
{
	int signal1[NumberOfReadings];
	int signal2[NumberOfReadings];
	int signal3[NumberOfReadings];
	StartFilter(signal1);
	StartFilter(signal2);
	StartFilter(signal3);

	UpdateFilter(10, signal1);
	UpdateFilter(10, signal1);

	UpdateFilter(15, signal2);
	UpdateFilter(15, signal2);

	UpdateFilter(20, signal3);
	UpdateFilter(20, signal3);
	if(GetFilteredSignal(signal1) == 10
	   && GetFilteredSignal(signal2) == 15 
	   && GetFilteredSignal(signal3) == 20)
	{
		return 1;
	}
	else
	{
		printf("Test15 Failed\n");
		return 0;
	}
}

int Test16()
{
	int signal1[NumberOfReadings];
	int signal2[NumberOfReadings];
	int signal3[NumberOfReadings];
	StartFilter(signal1);
	StartFilter(signal2);
	StartFilter(signal3);

	int correctValue1 = 0;
	int correctValue2 = 0;
	int correctValue3 = 0;
	int counter = 0;
	for(int i = 1; i <= 100; ++i)
	{	
		if(i > 100 - NumberOfReadings)
		{
			correctValue1 += i;
			correctValue2 += 2*i;
			correctValue3 += 10 + i;
		}
		UpdateFilter(i, signal1);
		UpdateFilter(2*i, signal2);
		UpdateFilter(10 + i, signal3);
	}

	// printf("%d %d %d\n", GetFilteredSignal(signal1), GetFilteredSignal(signal2), GetFilteredSignal(signal3));
	if(GetFilteredSignal(signal1) == correctValue1/NumberOfReadings
	   && GetFilteredSignal(signal2) == correctValue2/NumberOfReadings
	   && GetFilteredSignal(signal3) == correctValue3/NumberOfReadings)
	{
		return 1;
	}
	else{
		printf("Test16 Failed\n");
		return 0;
	}
}

// Clear 1 signal but not the others
int Test17()
{
	int signal1[NumberOfReadings];
	int signal2[NumberOfReadings];
	int signal3[NumberOfReadings];
	StartFilter(signal1);
	StartFilter(signal2);
	StartFilter(signal3);

	int correctValue1 = 0;
	int correctValue2 = 0;
	for(int i = 1; i <= 100; ++i)
	{
		if(i > 100 - NumberOfReadings)
		{
			correctValue1 += i;
			correctValue2 += 2*i;
		}
		UpdateFilter(i, signal1);
		UpdateFilter(2*i, signal2);
		UpdateFilter(i + 10, signal3);
	}

	RestartFilter(signal3);
	// printf("%d,%d,%d\n", GetFilteredSignal(signal1), GetFilteredSignal(signal2), GetFilteredSignal(signal3));
	if(GetFilteredSignal(signal1) == correctValue1/NumberOfReadings
	   && GetFilteredSignal(signal2) == correctValue2/NumberOfReadings
	   && GetFilteredSignal(signal3) == InvalidFilterReading)
	{
		return 1;
	}
	else
	{
		printf("Test17 Failed\n");
		return 0;
	}
}

void ReadFile()
{
	int c;
	FILE *file;

	printf("\nTesting Reading Files\n");
	file = fopen("./TestCases/Test3.txt","r");
	if (file)
	{
		while((c = getc(file)) != EOF){
			// putchar(c);
			printf("%d\n", c);
		}
		fclose(file);
	}

}