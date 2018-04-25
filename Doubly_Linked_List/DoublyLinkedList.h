#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template<class T>
class DoublyLinkedList {
	private:
		struct Node{
			T data;
			Node *next, *prev;
		};
		Node *head, *tail;
		int length;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		bool isEmpty();
		int getLength();
		void printList();
		void pushFront(T val);
		void pushBack(T val);
		void popFront();
		void popBack();
		void reverse();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

// TODO: alter destructor to use popFront()
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	if(!isEmpty()) {
		Node *temp;
		while(head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() {
	return (length == 0);
}

template<class T>
int DoublyLinkedList<T>::getLength() {
	return length;
}

template<class T>
void DoublyLinkedList<T>::pushFront(T val) {
	Node *temp = new Node();
	temp->data = val;
	if(isEmpty()) {
		temp->next = nullptr;
		temp->prev = nullptr;
		head = temp;
		tail = temp;
	} else {
		temp->next = head;
		head->prev = temp;
		temp->prev = nullptr;
		head = temp;	
	}
	length++;
}

template<class T>
void DoublyLinkedList<T>::pushBack(T val) {
	Node *temp = new Node();
	temp->data = val;
	if(isEmpty()) {
		temp->next = nullptr;
		temp->prev = nullptr;
		head = temp;
		tail = temp;
	} else {
		temp->prev = tail;
		tail->next = temp;
		temp->next = nullptr;
		tail = temp;
	}
	length++;
}

template<class T>
void DoublyLinkedList<T>::popFront() {
	if(isEmpty()) {
		std::cout << "Err(popFront): Can't delete from empty list!" << std::endl;
	} else {
		Node *temp;
		temp = head;
		head = head->next;
		delete temp;
		length--;
		if(head != nullptr) {
			head->prev = nullptr;
		} else {
			tail = head;
		}
	}
}

template<class T>
void DoublyLinkedList<T>::popBack() {
	if(isEmpty()) {
		std::cout << "Err(popBack): Can't delete from empty list!" << std::endl;
	} else {
		Node *temp;
		temp = tail;
		tail = tail->prev;
		delete temp;
		length--;
		if(tail != nullptr) {
			tail->next = nullptr;
		} else {
			head = tail;
		}
	}
}

template<class T>
void DoublyLinkedList<T>::reverse() {
	if(isEmpty() || getLength() == 1) {
		std::cout << "Err(reverse): List is empty or contains a single node (no action required)" << std::endl;
	} else {
		Node *temp, *current;
		current = head;
		while(current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		temp = head;
		head = tail;
		tail = temp;
	}
}

template<class T>
void DoublyLinkedList<T>::printList() {
	std::cout << "---------------------" << std::endl;
	if(isEmpty()) {
		std::cout << "List is empty!" << std::endl;
	} else {
		Node *temp;
		temp = head;
		std::cout << "Length of list: " << getLength() << std::endl << "List = ";
		while(temp != nullptr) {
			std::cout << "[" << temp->data << "]";
			if(temp->next != nullptr) {
				std::cout << "-->";
			}
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	std::cout << "---------------------" << std::endl;
}

#endif /* DOUBLYLINKEDLIST_H */
