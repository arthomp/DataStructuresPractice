#include "DoublyLinkedList.h"
#include <iostream>
#include <typeinfo>

int main() {
	DoublyLinkedList<int> dll;
	std::cout << "List is empty: " << dll.isEmpty() << std::endl;
	std::cout << "Type is " << typeid(dll).name() << std::endl;
	return 0;
}