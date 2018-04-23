#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T>
class DoublyLinkedList {
	private:
		struct Node{
			T data;
			Node *next, *prev;
		};
		Node *head, *tail;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		bool isEmpty();
		void pushFront(T val);
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;	
}

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
	return (head == nullptr && tail == nullptr);
}

template<class T>
void DoublyLinkedList<T>::pushFront(T val) {

}

#endif /* DOUBLYLINKEDLIST_H */
