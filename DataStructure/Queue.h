
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

//Queue implementation based on linked-list
namespace queueStructure {
	
	template<typename T>
	class Queue
	{
	public:
		//default constructor
		Queue();

		//destructor
		~Queue();

		//enqueue data to the queue
		void enqueue(int data);

		//dequeue data from the queue
		bool dequeue(T& value);

		//check if the queue empty
		bool isEmpty();

		//print the data contains at the queue
		void printQueue();

	private:
		linkedListStructure::LinkedList<T> list; //composed Linked-List object
	};

	template<typename T>
	//default constructor
	Queue<T>::Queue()
	{
	}

	//destructor
	template<typename T>
	Queue<T>::~Queue()
	{
	}

	//enqueue data to the queue
	template<typename T>
	void Queue<T>::enqueue(int data)
	{
		list.pushBack(data);
	}

	//dequeue data from the queue
	template<typename T>
	bool Queue<T>::dequeue(T& value)
	{
		if (!list.isEmpty()) {
			
			if (list.popFront(value))
				return true;
			else
				return false;
		}

		return false;
	}

	//check if the queue empty
	template<typename T>
	bool Queue<T>::isEmpty()
	{
		return list.isEmpty();
	}

	//print the data contains at the queue
	template<typename T>
	void Queue<T>::printQueue()
	{
		list.printList();
	}

	//driver function to test functionality of Queue class
	template<typename T>
	void testQueue(Queue<T> queue, T initialValue, T increment, std::string queueType)
	{
		for (int i = 0; i < 5; i++) {
			queue.enqueue(initialValue);
			cout << "Enqueue " << initialValue << " to " << queueType << endl;
			initialValue += increment;
		}

		queue.printQueue();

		T value;
		while ( queue.dequeue(value) )
			cout << "Dequeue " << value << " from queue " << endl;

		queue.printQueue();

		cout << "Queue is empty. Nothing to dequeue " << endl;
	}
}

//Implementation of Queue based on Stack class
namespace queueOnStackStructure {

	template<typename T>
	class Queue
	{
	public:
		Queue();
		~Queue();

		void enqueue(int data);

		bool dequeue(T& value);

		bool isEmpty();

		void printQueue();

	private:
		stackListCompositionStructure::Stack<T> inStack;
		stackListCompositionStructure::Stack<T> outStack;
	};

	template<typename T>
	Queue<T>::Queue()
	{
	}

	template<typename T>
	Queue<T>::~Queue()
	{
	}

	template<typename T>
	void Queue<T>::enqueue(int data)
	{
		inStack.push(data);
	}

	template<typename T>
	bool Queue<T>::dequeue(T& value)
	{
		if(outStack.isEmpty()) {

			T tempValue;
			while(inStack.pop(tempValue))
				outStack.push(tempValue);
		}

		if(outStack.pop(value))
			return true;

		return false;
	}

	template<typename T>
	bool Queue<T>::isEmpty()
	{
		return inStack.isEmpty() && outStack.isEmpty();
	}

	template<typename T>
	void Queue<T>::printQueue()
	{
		if (!outStack.isEmpty())
			outStack.printStack();


		inStack.printStack();
	}

	template<typename T>
	void testQueue(Queue<T> queue, T initialValue, T increment, std::string queueType)
	{
		for (int i = 0; i < 5; i++) {
			queue.enqueue(initialValue);
			cout << "Enqueue " << initialValue << " to " << queueType << endl;
			initialValue += increment;
		}

		queue.printQueue();

		T value;
		while (queue.dequeue(value))
			cout << "Dequeue " << value << " from queue " << endl;

		queue.printQueue();

		cout << "Queue is empty. Nothing to dequeue " << endl;
	}
}
#endif