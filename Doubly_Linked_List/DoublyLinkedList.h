#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template<typename T>
class DoublyLinkedList {
	class Node;
	private:
		Node *head, *tail;
		int length;
	public:
		class Iterator;
		DoublyLinkedList();
		~DoublyLinkedList();
		bool isEmpty() const;
		int getLength() const;
		void printList() const;
		void pushFront(const T val);
		void pushBack(const T val);
		void popFront();
		void popBack();
		void reverse();
		Iterator begin();
		Iterator end();
};

template<typename T>
class DoublyLinkedList<T>::Node {
	public:
		T data;
		Node *next, *prev;
};

template<typename T>
class DoublyLinkedList<T>::Iterator {
	private:
		Node *current;

	public:
		Iterator(Node *n);
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);
		T& operator*() const;
		bool operator==(const Iterator& other) const;
		bool operator!=(const Iterator& other) const;
};

template<typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node *n) {
	current = n;
}

template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++() {
	current = current->next;
	return *this;
}

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int) {
	Iterator temp = *this;
	++*this;
	return temp;
}

template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--() {
	current = current->prev;
	return *this;
}

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int) {
	Iterator temp = *this;
	--*this;
	return temp;
}

template<typename T>
T& DoublyLinkedList<T>::Iterator::operator*() const {
	return current->data;
}

template<typename T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& other) const {
	return current == other.current;
}

template<typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
	return current != other.current;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	while(!isEmpty()) {
		popFront();
	}
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
	return (length == 0);
}

template<typename T>
int DoublyLinkedList<T>::getLength() const {
	return length;
}



template<typename T>
void DoublyLinkedList<T>::printList() const {
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

template<typename T>
void DoublyLinkedList<T>::pushFront(const T val) {
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

template<typename T>
void DoublyLinkedList<T>::pushBack(const T val) {
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
	return Iterator(head);
}

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() {
	return Iterator(nullptr);
}



#endif /* DOUBLYLINKEDLIST_H */
