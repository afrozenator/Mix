CC=g++ -std=c++11
CFLAGS=-c -Wall

all: testing_main

testing_main: byte.o testing_main.cc
	$(CC) testing_main.cc byte.o -o testing_main 

mix.o: mix.cc instruction.o
	$(CC) $(CFLAGS) mix.cc

op_code.o: op_code.cc
	$(CC) $(CFLAGS) op_code.cc

instruction.o: instruction.cc word.o
	$(CC) $(CFLAGS) instruction.cc

word.o: word.cc byte.o
	$(CC) $(CFLAGS) word.cc

byte.o: byte.cc
	$(CC) $(CFLAGS) byte.cc

clean:
	rm -rf *.o *.gch
