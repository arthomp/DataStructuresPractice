#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template<class T>
class DoublyLinkedList {
	private:
		struct Node{
			T data;
			typename DoublyLinkedList<T>::Node *next, *prev;
		};
		typename DoublyLinkedList<T>::Node *head, *tail;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		bool isEmpty();
};


#endif /* DOUBLYLINKEDLIST_H */