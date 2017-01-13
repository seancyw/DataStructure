
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

namespace doublyLinkedListStructure {
	//Node that accept int data type
	template<typename T>
	struct Node {
		//Initialize structure variables
		Node() : data(0)
			, next(nullptr)
			, previous(nullptr)
		{
		}

		Node(T value) : data(value)
			, next(nullptr)
			, previous(nullptr)
		{
		}

		T data;
		Node* next;
		Node* previous;
	};

	template<typename T>
	class LinkedList
	{
	public:
		LinkedList()
			: head(nullptr)
			, tail(nullptr)
			, size(0)
		{
		}

		~LinkedList()
		{
			Node<T>* current = head;
			Node<T>* previous = head;

			while (current) {
				previous = current;
				current = previous->next;

				delete previous;
			}
		}

		void pushBack(const T& value)
		{
			Node<T>* newNode = getNewNode(value);

			//if list is empty, assign head and tail point to
			//new node
			if (isEmpty()) {
				head = tail = newNode;
			}
			else {
				//update last previous node
				tail->previous = tail;
				tail->next = newNode;
				tail = newNode;
			}

			++size;
		}

		void pushFront(const T& value)
		{
			Node<T>* newNode = getNewNode(value);

			//if list is empty, assign head and tail point to
			//new node
			if (isEmpty()) {
				head = tail = newNode;
			}
			else {
				//update first node
				newNode->previous = tail;
				newNode->next     = head;
				head = newNode;
			}

			++size;
		}

		bool popBack(T& value)
		{
			//Return false if no node to remove
			if (isEmpty())
				return false;

			//hold tempNode to delete
			Node<T>* tempNode = tail;

			if (head == tail) {
				head = tail = nullptr;
				size = 0;
			}
			else {
				Node<T>* current = head;

				//loop to last second node
				while (current->next != tail)
					current = current->next;

				//remove last node
				tail = current;
				current->next = nullptr;
			}

			if (size > 0)
				--size;

			value = tempNode->data;
			delete tempNode;

			return true;
		}

		bool popFront(T& value)
		{
			//Return false if no node to remove
			if (isEmpty())
				return false;

			if (head == tail) {
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

			if (size > 0)
				--size;

			return true;
		}

		bool isEmpty() const
		{
			return (size == 0);
		}

		int  getSize() const
		{
			return size;
		}

		bool contains(const T& value)
		{
			if (isEmpty())
				return false;

			Node<T>* current = head;

			while (current) {

				if (current->data == value)
					return true;
				else
					current = current->next;
			}

			return false;
		}

		//Use for hash table
		bool popNode(T& value)
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

			while (current) {

				if (current->data == value) {
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

		void printList() const
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

	private:
		Node<T>* head;
		Node<T>* tail;
		int size;

		Node<T>* getNewNode(const Node<T>& value)
		{
			return new Node<T>(value);
		}
	};

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