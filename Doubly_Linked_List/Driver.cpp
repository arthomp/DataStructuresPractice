#include "DoublyLinkedList.h"
#include <iostream>

int main() {
	DoublyLinkedList<int> dll;
	std::cout << "Checking if list is empty: " << dll.isEmpty() << std::endl;
	dll.printList();

	std::cout << "Inserting node to empty list (pushFront)..." << std::endl;
	dll.pushFront(1);

	std::cout << "Checking if list is empty: " << dll.isEmpty() << std::endl;
	dll.printList();

	std::cout << "Inserting second node to list (pushFront)..." << std::endl;
	dll.pushFront(2);

	std::cout << "Checking if list is empty: " << dll.isEmpty() << std::endl;
	dll.printList();

	std::cout << "Inserting third node to list (pushBack)..." << std::endl;
	dll.pushBack(3);
	dll.printList();

	std::cout << "Deleting head node (popBack)..." << std::endl;
	dll.popBack();
	dll.printList();

	std::cout << "Deleting head node (popFront)..." << std::endl;
	dll.popFront();
	dll.printList();

	std::cout << "Deleting head node (popFront)..." << std::endl;
	dll.popFront();
	dll.printList();

	std::cout << "Deleting head node (popFront)..." << std::endl;
	dll.popFront();
	dll.printList();

	return 0;
}