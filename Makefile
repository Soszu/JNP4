all: sampleTest
CC=g++

sampleTest: sampleTest.cpp holding.hh
	$(CC) -Wall -O2 -std=c++11 sampleTest.cpp holding.hh -o sampleTest

clean:
	rm -f *.o *.gch sampleTest
