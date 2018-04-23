#include "DoublyLinkedList.h"
#include <iostream>

int main() {
	DoublyLinkedList<int> dll;
	std::cout << "List is empty: " << dll.isEmpty() << std::endl;
	return 0;
}