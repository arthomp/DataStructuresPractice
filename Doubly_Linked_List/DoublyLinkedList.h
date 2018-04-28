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
		DoublyLinkedList();
		~DoublyLinkedList();
		bool isEmpty();
		int getLength();
		bool checkValidity();
		void printList();
		void pushFront(T val);
		void pushBack(T val);
		void popFront();
		void popBack();
		void reverse();
		class Iterator;
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
		T& operator*();
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
T& DoublyLinkedList<T>::Iterator::operator*() {
	return current->data;
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
bool DoublyLinkedList<T>::isEmpty() {
	return (length == 0);
}

template<typename T>
int DoublyLinkedList<T>::getLength() {
	return length;
}

template<typename T>
bool DoublyLinkedList<T>::checkValidity() {
	if(isEmpty()) {
		return true;
	} else if(getLength() == 1) {
		return ((head == tail) && ((head->prev == nullptr) && (head->next == nullptr)));
	} else {
		// check validity of head
		if(head->prev != nullptr || head->next == nullptr) {
			return false;
		}
		//check validity of between nodes
		int nodesChecked = 1;
		Node *last = head;
		Node *curr = head->next;
		while(curr != tail) {
			if(curr->prev != last || curr->next == nullptr) {
				return false;
			}
			curr = curr->next;
			last = last->next;
			nodesChecked++;
		}
		// check validity of tail
		if(tail->prev != last || tail->next != nullptr) {
			return false;
		}
		nodesChecked++;
		if(getLength() != nodesChecked) {
			return false;
		}
		return true;
	}
}

template<typename T>
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

template<typename T>
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

template<typename T>
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
