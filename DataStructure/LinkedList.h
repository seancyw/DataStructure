#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace linkedListStructure {
	//Node that accept int data type
	template<typename T>
	struct Node {
		//Initialize structure variables
		Node() : data(0)
			, next(nullptr)
		{
		}

		Node(T value) : data(value)
			, next(nullptr)
		{
		}

		T data;
		Node* next;
	};

	template<typename T>
	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList();

		void pushBack(Node<T>* newNode);
		void pushFront(Node<T>* newNode);

		bool popBack(T&);
		bool popFront(T&);

		bool isEmpty();
		int  getSize() const;

		void printList();

	private:
		Node<T>* head;
		int size;
	};

	template<typename T>
	LinkedList<T>::LinkedList()
	{
		head = new Node<T>();
		size = 0;
	}

	template<typename T>
	LinkedList<T>::~LinkedList()
	{
		Node<T>* current = head;
		Node<T>* previous = head;

		while (current) {
			previous = current;
			current = previous->next;

			delete previous;
		}
	}

	template<typename T>
	void LinkedList<T>::pushBack(Node<T>* newNode)
	{
		//First Node
		if (head->next == NULL) {
			++size;
			head = newNode;

			return;
		}

		Node<T>* current = head;
		Node<T>* previous = head;

		while (current) {

			previous = current;

			if (current->next == NULL) {
				current->next = newNode;
				++size;
				return;
			}

			current = previous->next;
		}

	}

	template<typename T>
	void LinkedList<T>::pushFront(Node<T>* newNode)
	{
		//First Node
		if (head == NULL) {
			++size;
			head = newNode;
			return;
		}

		newNode->next = head->next;
		head->next = newNode;
		++size;
		return;
	}

	template<typename T>
	bool LinkedList<typename T>::popBack(T& value)
	{
		//Return false if no node to remove
		if (head->next == NULL) {
			return false;
		}

		Node<T>* current = head;
		Node<T>* previous = head;
		int count = 0;

		while (current) {

			previous = current;

			if (count == size - 1) {
				value = current->next->data;
				delete current->next;
				current->next = NULL;
				--size;
				return true;
			}

			current = previous->next;
			count++;
		}

		return false;
	}

	template<typename T>
	bool LinkedList<T>::popFront(T& value)
	{
		//Return false if no node to remove
		if (head->next == NULL) {
			return false;
		}

		Node<T>* current = head;
		Node<T>* previous = head;

		while (current) {

			if (current != head) {
				value = current->next->data;
				previous->next = current->next;
				delete current;
				--size;
				return true;
			}
			previous = current;
			current = previous->next;
		}

		return false;
	}

	template<typename T>
	bool LinkedList<T>::isEmpty()
	{
		return (size == 0);
	}

	template<typename T>
	int  LinkedList<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	void LinkedList<T>::printList()
	{
		Node<T>* current = head;
		Node<T>* previous = head;

		std::cout << "LinkedList contains " << getSize() << " item \n";

		int count = 0;
		while (current) {
			previous = current;

			std::cout << "Position " << count++ << "\t" << previous->data << "\n";
			current = previous->next;
		}
	}

}
#endif