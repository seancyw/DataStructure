#include <iostream>
#include <iomanip>
#include "LinkedList.h"
#include "Stack.h"
#include <string>
#include "Queue.h"

using namespace std;

enum TEST_CASE {
	LINKED_LIST,
	STACK,
	QUEUE
};

void linkedListTest();
void stackTest();
void queueTest();

int main()
{
	TEST_CASE test = QUEUE;

	switch (test)
	{
		case LINKED_LIST:
			linkedListTest();
			break;

		case STACK:
			stackTest();
			break;

		case QUEUE:
			queueTest();
			break;

		default:
			break;
	}

	cin.ignore();

	return 0;
}

void linkedListTest()
{
	linkedListStructure::Node<int>* A = new linkedListStructure::Node<int>(10);
	linkedListStructure::Node<int>* B = new linkedListStructure::Node<int>(20);
	linkedListStructure::Node<int>* C = new linkedListStructure::Node<int>(30);
	linkedListStructure::Node<int>* D = new linkedListStructure::Node<int>(40);
	linkedListStructure::Node<int>* E = new linkedListStructure::Node<int>(50);
	linkedListStructure::Node<int>* F = new linkedListStructure::Node<int>(60);

	linkedListStructure::LinkedList<int> list;

	list.pushFront(A);
	list.pushFront(B);
	list.printList();

	list.pushBack(C);
	list.pushBack(D);
	list.printList();

	int value = 0;
	list.popFront(value);
	list.printList();

	list.popBack(value);
	list.printList();

	list.pushFront(F);
	list.printList();

	list.pushBack(E);
	list.printList();
}

void stackTest()
{
	stackStructure::Stack<double> doubleStack(5);
	stackStructure::Stack<int>	  intStack(8);

	stackStructure::testStack<double>(doubleStack, 2.0, 0.5, "doubleStack");
	stackStructure::testStack<int>(intStack, 100, 50, "intStack");
}

void queueTest()
{
	queueStructure::Queue<int> intQueue;

	queueStructure::testQueue(intQueue, 5, 10, "intQueue");
}