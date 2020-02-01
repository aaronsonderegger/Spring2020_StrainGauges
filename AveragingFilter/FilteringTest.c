#include<stdio.h>
#include "AverageFiltering.h"

#define TotalTests 6

// ** ProtoType Functions **
int	Test1();	// Test of UpdateFilter(const int reading) Function, Test before anything is filtered
int Test2();	// Test of UpdateFilter(const int reading) Function, Test the Filtering of a signal of 1 reading
int Test3();	// Test of UpdateFilter(const int reading) Function, Test 20 signals
int Test4();	// Test the RestartFilter() Function
int Test5();	// Test the GetFilteredSignal() Function
int Test6();	// Test of UpdateFilter(const int reading) Function, Test 100 signals
void ReadFile();	// This is a scratch to see if I can read a file the right way

// ** Main Function **
int main()
{
	int testPassed = 0;
	DebugFilter();
	// * Run Tests *
	testPassed += Test1();
	RestartFilter();
	testPassed += Test2();
	RestartFilter();
	testPassed += Test3();
	RestartFilter();
	testPassed += Test4();
	RestartFilter();
	testPassed += Test5();
	testPassed += Test6();

	printf("%d of %d passed\n",testPassed, TotalTests );

	ReadFile();
	return 0;
}

//** Helper Functions **
// Test of UpdateFilter(const int reading) Function, Test before anything is filtered
int Test1() 
{
	if (GetFilteredSignal() == InvalidFilterReading)
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
	int signal = 255;
	UpdateFilter(signal);
	if(GetFilteredSignal() == signal)
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
	for(int i = 1; i <= 20; ++i)
	{	
		correctValue += i;
		UpdateFilter(i);
		lastNumber++;
	}

	// printf("%d %d %d %d\n",correctValue,lastNumber,correctValue/lastNumber, tmp );
	if(GetFilteredSignal() == correctValue/lastNumber)
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
	for(int i = 1; i <= 20; ++i)
	{
		UpdateFilter(i);
	}

	RestartFilter();
	if(GetFilteredSignal() == InvalidFilterReading)
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
	UpdateFilter(10);
	UpdateFilter(10);
	if(GetFilteredSignal() == 10)
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
	int correctValue = 0;
	int counter = 0;
	for(int i = 1; i <= 100; ++i)
	{	
		if(i > 100 - NumberOfReadings)
		{
			correctValue += i;
			++counter;
		}
		UpdateFilter(i);
	}
	int tmp = GetFilteredSignal();

	printf("%d %d %d %d\n",correctValue,NumberOfReadings,correctValue/NumberOfReadings, tmp );
	if(GetFilteredSignal() == correctValue/NumberOfReadings)
	{
		return 1;
	}
	else{
		printf("Test3 Failed\n");
		return 0;
	}
}

void ReadFile()
{
	int c;
	FILE *file;
	printf("Testing Reading Files\n");
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