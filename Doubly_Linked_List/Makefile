CC = g++
CFLAGS = -Wall -std=c++0x -g
EXECUTABLE = DLL

all: $(EXECUTABLE)

$(EXECUTABLE): Driver.o
	$(CC) $(CFLAGS) Driver.o -o $(EXECUTABLE)
Driver.o: Driver.cpp
	$(CC) $(CFLAGS) -c Driver.cpp

clean:
	rm -rf *.o *.gch *~ DLL
