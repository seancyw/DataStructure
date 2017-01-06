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

		void pushBack(const T&);
		void pushFront(const T&);

		bool popBack(T&);
		bool popFront(T&);

		//Use for hash table
		bool popNode(T&);

		bool isEmpty() const;
		int  getSize() const;

		bool contains(const T&);

		void printList() const;

	private:
		Node<T>* head;
		Node<T>* tail;
		int size;

		Node<T>* getNewNode(const Node<T>&);
	};

	template<typename T>
	LinkedList<T>::LinkedList()
		: head(nullptr)
		, tail(nullptr)
		, size(0)
	{
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
	void LinkedList<T>::pushBack(const T& value)
	{
		Node<T>* newNode = getNewNode(value);

		//if list is empty, assign head and tail point to
		//new node
		if (isEmpty()) {
			head = tail = newNode;
		}
		else {
			//update last previous node
			tail->next = newNode;
			tail = newNode;
		}

		++size;
	}

	template<typename T>
	void LinkedList<T>::pushFront(const T& value)
	{
		Node<T>* newNode = getNewNode(value);

		//if list is empty, assign head and tail point to
		//new node
		if (isEmpty()) {
			head = tail = newNode;
		}
		else {
			//update first node
			newNode->next = head;
			head = newNode;
		}

		++size;
	}

	template<typename T>
	bool LinkedList<typename T>::popBack(T& value)
	{
		//Return false if no node to remove
		if(isEmpty())
			return false;

		//hold tempNode to delete
		Node<T>* tempNode = tail;

		if(head == tail) {
			head = tail = nullptr;
			size = 0;
		}
		else {
			Node<T>* current  = head;
			
			//loop to last second node
			while(current->next != tail)
				current = current->next;

			//remove last node
			tail = current;
			current->next = nullptr;
		}

		if(size > 0)
			--size;

		value = tempNode->data;
		delete tempNode;

		return true;
	}

	template<typename T>
	bool LinkedList<T>::popFront(T& value)
	{
		//Return false if no node to remove
		if(isEmpty())
			return false;

		if(head == tail) {
			value = head->data;
			head = tail = nullptr;
			size = 0;
		}
		else {
			Node<T>* current = head;
			
			head = head->next;
			value = current->data;
			delete current;
		}

		if(size > 0)
			--size;

		return true;
	}

	template<typename T>
	bool LinkedList<T>::isEmpty() const
	{
		return (size == 0);
	}

	template<typename T>
	int  LinkedList<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	bool LinkedList<T>::contains(const T& value)
	{
		if(isEmpty())
			return false;

		Node<T>* current = head;

		while(current) {
			
			if(current->data == value)
				return true;
			else
				current = current->next;
		}

		return false;
	}

	template<typename T>
	//Use for hash table
	bool LinkedList<T>::popNode(T& value)
	{
		if (isEmpty() && !contains(value))
			return false;

		//if the list only contains one node
		if (head == tail) {
			if (head->data == value) {
				head = tail = nullptr;
				size = 0;
				return true;
			}
		}

		Node<T>* current = head;
		Node<T>* tempNode = head;

		while(current) {

			if(current->data == value) {
				tempNode->next = current->next;
				delete current;
				--size;
				return true;
			}
			
			//assign current node to tempNode
			tempNode = current;

			//assign next node to current node
			current = current->next;
		}

		return false;
	}

	template<typename T>
	void LinkedList<T>::printList() const
	{
		if (isEmpty()) {
			cout << "List is empty" << endl;
			return;
		}

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

	template<typename T>
	Node<T>* LinkedList<T>::getNewNode(const Node<T>& value)
	{
		return new Node<T>(value);
	}

	template<typename T>
	void testLinkedList(LinkedList<T> testList, int iteration, T initialValue, T increment, std::string listType)
	{
		cout << "Pushing back...." << endl;
		for (int iter = 0; iter < iteration; ++iter) {
			testList.pushBack(initialValue);
			cout << initialValue << " is pushed to " << listType << ". Current list size: " << testList.getSize() << endl;
			initialValue += increment;
		}

		testList.printList();

		cout << "Popping back...." << endl;
		T value;
		while (testList.popBack(value))
			cout << value << " is popped out from " << listType << ". Current list size: " << testList.getSize() << endl;

		testList.printList();

		cout << "Pushing front...." << endl;
		for (int iter = 0; iter < iteration; ++iter) {
			initialValue -= increment;
			testList.pushBack(initialValue);
			cout << initialValue << " is pushed to " << listType << ". Current list size: " << testList.getSize() << endl;
		}

		testList.printList();

		cout << "Popping front...." << endl;
		while (testList.popFront(value))
			cout << value << " is popped out from " << listType << ". Current list size: " << testList.getSize() << endl;

		testList.printList();
	}
}
#endif