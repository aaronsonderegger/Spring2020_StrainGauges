# Simple Makefile

# "make run" or "make"
run: FilteringTest.o AverageFiltering.o
	gcc FilteringTest.o AverageFiltering.o -o run

FilteringTest.o: FilteringTest.c AverageFiltering.h
	gcc -c FilteringTest.c -o FilteringTest.o

AverageFiltering.o: AverageFiltering.c AverageFiltering.h
	gcc -c AverageFiltering.c -o AverageFiltering.o

clean:
	rm *.o
