all: sampleTest
CC=g++

sampleTest: sampleTest.cpp holding.hh
	$(CC) -Wall -O2 -std=c++11 sampleTest.cpp holding.hh -o sampleTest

forum: forum.cpp holding.hh
	$(CC) -Wall -std=c++11 forum.cpp holding.hh -o forum

clean:
	rm -f *.o *.gch sampleTest
