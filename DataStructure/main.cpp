#include <iostream>
#include <iomanip>
#include "LinkedList.h"
#include "Stack.h"
#include <string>
#include "Queue.h"
#include "HashTable.h"
#include "Tree.h"
#include "Graph.h"
#include "DoublyLinkedList.h"
#include "Heap.h"
#include "Array.h"

using namespace std;

enum TEST_CASE {
	LINKED_LIST,
	DOUBLY_LINKED_LIST,
	STACK,
	STACK_LIST,
	QUEUE,
	QUEUE_STACK,
	HASH_TABLE,
	BINARY_TREE,
	GRAPH,
	HEAP,
	ARRAY
};

//function prototype
void linkedListTest();
void doublyLinkedListTest();
void stackTest();
void stackListTest();
void queueTest();
void queueStackTest();
void hashTableTest();
void binaryTreeTest();
void graphTest();
void heapTest();
void arrayTest();

int main()
{
	TEST_CASE test = ARRAY;

	switch (test)
	{
		case LINKED_LIST:
			linkedListTest();
			break;

		case DOUBLY_LINKED_LIST:
			doublyLinkedListTest();
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

		case GRAPH:
			graphTest();
			break;

		case HEAP:
			heapTest();
			break;

		case ARRAY:
			arrayTest();
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

void doublyLinkedListTest()
{
	doublyLinkedListStructure::LinkedList<int> list;

	doublyLinkedListStructure::testLinkedList<int>(list, 10, 100, 5, "intList");
}

void stackTest()
{
	stackStructure::Stack<double> doubleStack(5);
	stackStructure::Stack<int>	  intStack(8);

	stackStructure::testStack<double>(doubleStack, 2.0, 0.5, "doubleStack");
	//stackStructure::testStack<int>(intStack, 100, 50, "intStack");
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

	binaryTreeStructure::testTree<int>(intTree, 10, "intTree");
}

void graphTest()
{
	graphStructure::testGraph();
}

void heapTest()
{
	heapStructure::Heap<int> intHeap(true);

	heapStructure::testHeap(intHeap, true, "INT MAX Heap");

	heapStructure::Heap<double> doubleHeap(false);

	heapStructure::testHeap(doubleHeap, false, "DOUBLE MIN Heap");
}

void arrayTest()
{
	arrayStructure::Array<int>    intArray(10);
	arrayStructure::Array<double> doubleArray(25);

	arrayStructure::testArray(intArray, 50, 10, 10);

	arrayStructure::testArray(doubleArray, 100., static_cast<size_t>(25), 0.5);
}