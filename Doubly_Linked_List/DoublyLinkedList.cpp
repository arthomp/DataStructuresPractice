#include "DoublyLinkedList.h"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;	
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	if(!isEmpty()) {
		typename DoublyLinkedList<T>::Node *temp;
		while(head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() {
	return (head == nullptr && tail == nullptr);
}