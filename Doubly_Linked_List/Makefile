CC = g++
CFLAGS = -Wall -std=c++0x -g
EXECUTABLE = DLL

all: $(EXECUTABLE)

$(EXECUTABLE): Driver.o DoublyLinkedList-impl.o
	$(CC) $(CFLAGS) Driver.o DoublyLinkedList-impl.o -o $(EXECUTABLE)
Driver.o: Driver.cpp
	$(CC) $(CFLAGS) -c Driver.cpp
DoublyLinkedList-impl.o: DoublyLinkedList-impl.cpp
	$(CC) $(CFLAGS) -c DoublyLinkedList-impl.cpp

clean:
	rm -rf *.o *.gch *~ DLL
