CC = g++
CFLAGS = -Wall -std=c++0x -g
EXECUTABLE = DLL

all: $(EXECUTABLE)

$(EXECUTABLE): DoublyLinkedList.o
	$(CC) $(CFLAGS) DoublyLinkedList.o -o $(EXECUTABLE)
DoublyLinkedList.o: DoublyLinkedList.cpp
	$(CC) $(CFLAGS) -c DoublyLinkedList.cpp
clean:
	rm -rf *.o *.gch *~ DLL
