#include <iostream>
#include <iomanip>
#include "LinkedList.h"
#include "Stack.h"
#include <string>
#include "Queue.h"
#include "HashTable.h"
#include "Tree.h"

using namespace std;

enum TEST_CASE {
	LINKED_LIST,
	STACK,
	STACK_LIST,
	QUEUE,
	QUEUE_STACK,
	HASH_TABLE,
	BINARY_TREE
};

//function prototype
void linkedListTest();
void stackTest();
void stackListTest();
void queueTest();
void queueStackTest();
void hashTableTest();
void binaryTreeTest();

int main()
{
	TEST_CASE test = BINARY_TREE;

	switch (test)
	{
		case LINKED_LIST:
			linkedListTest();
			break;

		case STACK:
			stackTest();
			break;

		case STACK_LIST:
			stackListTest();
			break;

		case QUEUE:
			queueTest();
			break;

		case QUEUE_STACK:
			queueStackTest();
			break;

		case HASH_TABLE:
			hashTableTest();
			break;

		case BINARY_TREE:
			binaryTreeTest();
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

void stackListTest()
{
	stackListStructure::Stack<double> doubleStack;
	stackListStructure::Stack<int>	  intStack;

	stackListStructure::testStack<double>(doubleStack, 10, 2.0, 0.5, "doubleStack");
	stackListStructure::testStack<int>(intStack, 20, 100, 50, "intStack");
}

void queueTest()
{
	queueStructure::Queue<int> intQueue;

	queueStructure::testQueue<int>(intQueue, 5, 10, "intQueue");
}

void queueStackTest()
{
	queueOnStackStructure::Queue<int> intQueue;

	queueOnStackStructure::testQueue<int>(intQueue, 5, 10, "intQueue");
}

void hashTableTest()
{
	hashTableStructure::testHashTable();
}

void binaryTreeTest()
{
	binaryTreeStructure::Tree<int> intTree;

	binaryTreeStructure::testTree<int>(intTree, 10, 10, 50, "intTree");
}