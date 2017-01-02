#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Node that accept int data type
struct Node {
	//Initialize structure variables
	Node() : data(0)
		   , next(NULL)
	{
	}

	Node(int value) : data(value)
		, next(NULL)
	{
	}

	int data;
	Node* next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void pushBack(Node* newNode);
	void pushFront(Node* newNode);

	bool popBack();
	bool popFront();

	bool isEmpty();
	int  getSize() const;

	void printList();

private:
	Node* head;
	int size;
};

#endif