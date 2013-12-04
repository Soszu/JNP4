all: sampleTest
CC=colorgcc

holding: holding.hh
	$(CC) -Wall -O2 -std=c++11 -c holding.hh -o holding.o

sampleTest: sampleTest.cpp holding
	$(CC) -Wall -O2 -std=c++11 sampleTest.cpp holding.o -o sampleTest

clean:
	rm -f *.o *.gch sampleTest
