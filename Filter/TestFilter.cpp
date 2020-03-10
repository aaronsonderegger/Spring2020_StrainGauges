#include <stdio.h>
#include "Filter.cpp"

void GenerateSignals(int numSignals, Filter fltr); 	// This generates signals for a filter.
bool Test1();   // This test checks filter before UpdateFilter() function
bool Test2();   // This test checks filter with 1 signal reading of UpdateFilter() 
bool Test3();   // This test checks filter with 20 signals
bool Test4();   // This test checks RestartFilter() function
bool Test5();   // This test checks GetFilteredSignal()
bool Test6();   // This test checks UpdatedFilter() with 100 signals.
bool Test7();   // This test checks filter for multiple filters before UpdateFilter() function
bool Test8();   // This test checks filter for multiple filters with 1 signal reading of UpdateFilter() 
bool Test9();   // This test checks filter for multiple filters with 20 signals
bool Test10();  // This test checks filter for multiple filters RestartFilter() function 
bool Test11();  // This test checks filter for multiple filters GetFilterSignal()
bool Test12();  // This test checks filter for multiple filters UpdateFitler with 100 signals
bool Test13();  // This test checks filter for multiple filters with reseting 1 filter and not others
// bool Test14();  // This test checks

int main()
{
	int passedTests = 0;
	int totalTests = 13;
	
	passedTests += Test1();
	passedTests += Test2();
	passedTests += Test3();
	passedTests += Test4();
	passedTests += Test5();
	passedTests += Test6();
	passedTests += Test7();
	passedTests += Test8();
	passedTests += Test9();
	passedTests += Test10();
	passedTests += Test11();
	passedTests += Test12();
	passedTests += Test13();
	passedTests += Test14();

	std::cout << passedTests << " / " totalTests << "Passed\n";
	return 0;
}

// This generates signals for a filter.
void GenerateSignals(int numSignals, Filter fltr)
{

}

// This test checks filter before UpdateFilter() function
bool Test1()
{

}

// This test checks filter with 1 signal reading of UpdateFilter()
bool Test2()
{

}

// This test checks filter with 20 signals 
bool Test3()
{

}

// This test checks RestartFilter() function
bool Test4()
{

}   

// This test checks GetFilteredSignal()
bool Test5()
{

}

// This test checks UpdatedFilter() with 100 signals.
bool Test6()
{

}   

// This test checks filter for multiple filters before UpdateFilter() function
bool Test7()
{

}   

// This test checks filter for multiple filters with 1 signal reading of UpdateFilter()
bool Test8()
{

}

// This test checks filter for multiple filters with 20 signals 
bool Test9()
{

}   

// This test checks filter for multiple filters RestartFilter() function 
bool Test10()
{

}  

// This test checks filter for multiple filters GetFilterSignal()
bool Test11()
{

}  

// This test checks filter for multiple filters UpdateFitler with 100 signals
bool Test12()
{

}  

// This test checks filter for multiple filters with reseting 1 filter and not others
bool Test13()
{

}
