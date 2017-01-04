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
	TEST_CASE test = LINKED_LIST;

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
	linkedListStructure::LinkedList<int> list;

	linkedListStructure::testLinkedList<int>(list, 10, 100, 5, "intList");
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

	queueStructure::testQueue<int>(intQueue, 5, 10, "intQueue");
}