/**
 * DoublyLinkedList.h
 * Purpose: Custom implementation of templated doubly linked list with iterators
 *
 * @author: Austin Thompson
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template<typename T>
class DoublyLinkedList {
	private:
		class Node;
		Node *head, *tail;
		int length;
	public:
		class Iterator;
		DoublyLinkedList();
		~DoublyLinkedList();
		bool isEmpty() const;
		int getLength() const;
		void printList();
		void pushFront(const T val);
		void pushBack(const T val);
		void popFront();
		void popBack();
		void reverse();
		Iterator find(const T val);
		Iterator begin();
		Iterator end();
		T front();
		T back();
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
		Iterator next(int n = 1);
		Iterator prev(int n = 1);
};

/**
 * Constructor: Iterator
 * Description: creates bidirectional iterator object that points to node in list
 * Parameters: Node *n
 * Return: none
*/
template<typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node *n) {
	current = n;
}

/**
 * Overload: prefix ++ operator
 * Description: defines prefix ++ behavior for iterator
 * Parameters: none
 * Return: Iterator&
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++() {
	current = current->next;
	return *this;
}

/**
 * Overload: postfix ++ operator
 * Description: defines postfix ++ behavior for iterator
 * Parameters: int (dummy parameter)
 * Return: Iterator
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int) {
	Iterator temp = *this;
	++*this;
	return temp;
}

/**
 * Overload: prefix -- operator
 * Description: defines prefix -- behavior for iterator
 * Parameters: none
 * Return: Iterator&
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--() {
	current = current->prev;
	return *this;
}

/**
 * Overload: postfix -- operator
 * Description: defines postfix -- behavior for iterator
 * Parameters: int (dummy parameter)
 * Return: Iterator
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int) {
	Iterator temp = *this;
	--*this;
	return temp;
}

/**
 * Overload: dereference operator (*)
 * Description: defines dereference behavior for iterator
 * Parameters: none
 * Return: T&
*/
template<typename T>
T& DoublyLinkedList<T>::Iterator::operator*() const {
	return current->data;
}

/**
 * Overload: comparison operator (==)
 * Description: defines comparison behavior for iterator
 * Parameters: const Iterator& other
 * Return: bool
*/
template<typename T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& other) const {
	return current == other.current;
}

/**
 * Overload: comparison operator (!=)
 * Description: defines comparison behavior for iterator
 * Parameters: const Iterator& other
 * Return: bool
*/
template<typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
	return current != other.current;
}

/**
 * Function: next
 * Parameters: n (default = 1)
 * Description: provides iterator pointing to the node it would be pointing to
 *				if advanced n positions
 * Return: Iterator
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::next(int n) {
	Iterator itr = *this;
	for(int i = 0; i < n; ++i) {
		++itr;
	}
	return itr;
}

/**
 * Function: prev
 * Parameters: n (default = 1)
 * Description: provides iterator pointing to the node it would be pointing to
 *				if advanced -n positions
 * Return: Iterator
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::prev(int n) {
	Iterator itr = *this;
	for(int i = 0; i < n; ++i) {
		--itr;
	}
	return itr;
}

/**
 * Constructor: DoublyLinkedList
 * Description: creates list object by initializing head and tail sentinel nodes
 * Parameters: none
 * Return: none
*/
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = new Node();
	tail = new Node();
	head->prev = nullptr;
	head->next = tail;
	tail->prev = head;
	tail->next = nullptr;
	length = 0;
}

/**
 * Destructor: ~DoublyLinkedList
 * Description: removes all nodes from list by calling popFront until empty, then
 *              deletes head and tail
 * Parameters: none
 * Return: none
*/
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	while(!isEmpty()) {
		popFront();
	}
	delete head;
	delete tail;
}

/**
 * Function: isEmpty
 * Description: checks if length of list is equal to 0
 * Parameters: none
 * Return: bool
*/
template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
	return (length == 0);
}

/**
 * Function: getLength
 * Description: gets length of list
 * Parameters: none
 * Return: int
*/
template<typename T>
int DoublyLinkedList<T>::getLength() const {
	return length;
}

/**
 * Function: printList
 * Description: prints length of list as well as visual representation of list
 * Parameters: none
 * Return: void
*/
template<typename T>
void DoublyLinkedList<T>::printList() {
	std::cout << std::endl;
	if(isEmpty()) {
		std::cout << "List is empty!" << std::endl;
	} else {
		std::cout << "Length of list: " << getLength() << std::endl << "List: [H] <--> ";
		for(Iterator itr = begin(); itr != end(); ++itr) {
			std::cout << "[" << *itr << "]";
			if(itr.next() != end()) {
				std::cout << " <--> ";
			}
		}
		std::cout << " <--> [T]" << std::endl;
	}
	std::cout << std::endl;
}

/**
 * Function: pushFront
 * Description: inserts new node at front of list and increments length
 * Parameters: const T val
 * Return: void
*/
template<typename T>
void DoublyLinkedList<T>::pushFront(const T val) {
	Node *temp = new Node();
	temp->data = val;
	temp->next = head->next;
	temp->prev = head;
	head->next->prev = temp;
	head->next = temp;
	length++;
}

/**
 * Function: pushBack
 * Description: inserts new node at end of list and increments length
 * Parameters: const T val
 * Return: void
*/
template<typename T>
void DoublyLinkedList<T>::pushBack(const T val) {
	Node *temp = new Node();
	temp->data = val;
	temp->prev = tail->prev;
	temp->next = tail;
	tail->prev->next = temp;
	tail->prev = temp;
	length++;
}

/**
 * Function: popFront
 * Description: removes node from front of list and decrements length, does not
 *          	allow delete if list is empty
 * Parameters: none
 * Return: void
*/
template<typename T>
void DoublyLinkedList<T>::popFront() {
	if(isEmpty()) {
		std::cout << "Err(popFront): Can't delete from empty list!" << std::endl;
	} else {
		Node *temp = head->next;
		head->next = temp->next;
		head->next->prev = head;
		delete temp;
		length--;
	}
}

/**
 * Function: popBack
 * Description: removes node from back of list and decrements length, does not
 *          	allow delete if list is empty
 * Parameters: none
 * Return: void
*/
template<typename T>
void DoublyLinkedList<T>::popBack() {
	if(isEmpty()) {
		std::cout << "Err(popBack): Can't delete from empty list!" << std::endl;
	} else {
		Node *temp = tail->prev;
		tail->prev = temp->prev;
		tail->prev->next = tail;
		delete temp;
		length--;
	}
}

/**
 * Function: reverse
 * Description: reverses the order of the nodes in the list
 * Parameters: none
 * Return: void
*/
template<typename T>
void DoublyLinkedList<T>::reverse() {
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

/**
 * Function: find
 * Description: provides iterator pointing to the first node found that contains
 *              val, otherwise provides iterator pointing to tail node
 * Parameters: const T val
 * Return: Iterator
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::find(const T val) {
	for(Iterator itr = begin(); itr != end(); ++itr) {
		if(*itr == val) {
			return itr;
		}
	}
	return end();
}

/**
 * Function: begin
 * Description: provides iterator pointing to node directly after head node
 * Parameters: none
 * Return: Iterator
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
	return Iterator(head->next);
}

/**
 * Function: end
 * Description: provides iterator pointing to tail node
 * Parameters: none
 * Return: Iterator
*/
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() {
	return Iterator(tail);
}

/**
 * Function: front
 * Description: gets value stored in node directly after head node
 * Parameters: none
 * Return: T
*/
template<typename T>
T DoublyLinkedList<T>::front() {
	return *begin();
}

/**
 * Function: back
 * Description: gets value stored in node directly before tail node
 * Parameters: none
 * Return: T
*/
template<typename T>
T DoublyLinkedList<T>::back() {
	return *(--end());
}


#endif /* DOUBLYLINKEDLIST_H */
