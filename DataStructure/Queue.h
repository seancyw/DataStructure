
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkedList.h"

namespace queueStructure {
	
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
		linkedListStructure::LinkedList<T> list;
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
		list.pushBack(data);
	}

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

	template<typename T>
	bool Queue<T>::isEmpty()
	{
		return list.isEmpty();
	}

	template<typename T>
	void Queue<T>::printQueue()
	{
		list.printList();
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
		while ( queue.dequeue(value) )
			cout << "Dequeue " << value << " from queue " << endl;

		queue.printQueue();

		cout << "Queue is empty. Nothing to dequeue " << endl;
	}
}
#endif