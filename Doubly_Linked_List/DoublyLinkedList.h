#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

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

#endif /* DOUBLYLINKEDLIST_H */