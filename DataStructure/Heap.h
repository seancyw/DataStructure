
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>

namespace heapStructure
{
	template<typename T>
	class Heap 
	{
	public:
		Heap(std::vector<T> elements, bool maxHeap)
			: _maxHeap(maxHeap)
		{
			for (size_t index = 0; index < elements.size(); ++index) {
				_heap.push_back(elements[i]);
				bubbleUp(i);
			}
		}

		Heap(bool maxHeap)
			: _maxHeap(maxHeap)
		{
		}

		~Heap()
		{
		}

		void push(const T& value)
		{
			if (contains(value)) {
				std::cout << "Duplicate value " << value << " cannot push onto heap.\n";
				return;
			}

			_heap.push_back(value);

			bubbleUp(getHeapSize() - 1);
		}

		bool pop(T& value)
		{
			if (isEmpty())
				return false;
			
			//get the top value
			value = _heap.front();
			
			//swap the first and the last value
			std::swap(_heap.front(), _heap.back());

			//pop the last value out
			_heap.pop_back();

			//bubble down from root
			bubbleDown(0);

			return true;
		}

		void bubbleDown(size_t index)
		{
			if (getHeapSize() == index)
				return;

			if (_maxHeap) {
				//If replaced elements is less than any of its child
				//node, swap the elements with its greatest child
				if (_heap.size() - 1 > getLeftChildIndex(index) && _heap.size() - 1 >= getRightChildIndex(index)) {

					//Swap the current value with the max between two value
					if (_heap[index] < max(_heap[getLeftChildIndex(index)], _heap[getRightChildIndex(index)])) {

						if (_heap[getLeftChildIndex(index)] > _heap[getRightChildIndex(index)]) {
							std::swap(_heap[index], _heap[getLeftChildIndex(index)]);

							//go to the next level
							bubbleDown(getLeftChildIndex(index));
						}
						else {
							std::swap(_heap[index], _heap[getRightChildIndex(index)]);

							//go to the next level
							bubbleDown(getRightChildIndex(index));
						}
					}

					return;
				}
				else if (_heap.size() - 1 >= getLeftChildIndex(index)) {
					//Swap the current value with the max value
					if (_heap[index] < _heap[getLeftChildIndex(index)]) {
						std::swap(_heap[index], _heap[getLeftChildIndex(index)]);

						//go to the next level
						bubbleDown(getLeftChildIndex(index));
					}

					return;
				}
				else if (_heap.size() - 1 >= getRightChildIndex(index)) {
					//Swap the current value with the max value
					if (_heap[index] < _heap[getRightChildIndex(index)]) {
						std::swap(_heap[index], _heap[getRightChildIndex(index)]);
						
						//go to the next level
						bubbleDown(getRightChildIndex(index));
					}

					return;
				}
			}
			else {
				//If replaced elements is greater than any of its child
				//node, swap the elements with its smallest child
				if (_heap.size() - 1 > getLeftChildIndex(index) && _heap.size() - 1 >= getRightChildIndex(index)) {

					//Swap the current value with the max between two value
					if (_heap[index] > min(_heap[getLeftChildIndex(index)], _heap[getRightChildIndex(index)])) {
						if (_heap[getLeftChildIndex(index)] < _heap[getRightChildIndex(index)]) {
							std::swap(_heap[index], _heap[getLeftChildIndex(index)]);
							
							//go to the next level
							bubbleDown(getLeftChildIndex(index));
						}
						else {
							std::swap(_heap[index], _heap[getRightChildIndex(index)]);

							//go to the next level
							bubbleDown(getRightChildIndex(index));
						}
					}
				}
				else if (_heap.size() - 1 >= getLeftChildIndex(index)) {
					//Swap the current value with the max value
					if (_heap[index] > _heap[getLeftChildIndex(index)]) {
						std::swap(_heap[index], _heap[getLeftChildIndex(index)]);

						//go to the next level
						bubbleDown(getLeftChildIndex(index));
					}

					return;
				}
				else if (_heap.size() - 1 >= getRightChildIndex(index)) {
					//Swap the current value with the max value
					if (_heap[index] > _heap[getRightChildIndex(index)]) {
						std::swap(_heap[index], _heap[getRightChildIndex(index)]);

						//go to the next level
						bubbleDown(getRightChildIndex(index));
					}

					return;
				}
			}
		}

		//Parent n have child of 2n+1 and 2n+2
		//child n has a parent of (n-1/2) round to lowest value
		void bubbleUp(size_t index)
		{
			//return if less than 2 elements on the heap
			if (index == 0)
				return;

			if (_maxHeap) {
				//if inserted element is greater than its parent 
				//node, swap the elements with its parents
				if (_heap[index] > _heap[getParentIndex(index)]) {
					std::swap(_heap[index], _heap[getParentIndex(index)]);

					bubbleUp(getParentIndex(index));
				}
			}
			else {
				//if inserted element is smaller than its parent 
				//node, swap the elements with its parents
				if (_heap[index] < _heap[getParentIndex(index)]) {
					std::swap(_heap[index], _heap[getParentIndex(index)]);

					bubbleUp(getParentIndex(index));
				}
			}
		}

		void printHeap()
		{
			if(_maxHeap)
				std::cout << "Max heap ";
			else
				std::cout << "Min heap ";

			std::cout << " contains the followings elements.\n";

			std::for_each(_heap.begin(), _heap.end(), [](T& value) { cout << value << " "; });

			std::cout << std::endl;
		}

		bool isEmpty() const
		{
			return getHeapSize() == 0;
		}

	private:
		bool _maxHeap;         //determine if the heap is MAX heap or MIN heap
		std::vector<T> _heap;

		size_t getParentIndex(const size_t child)
		{
			return (child - 1) / 2;
		}

		size_t getLeftChildIndex(const size_t parent)
		{
			return 2 * parent + 1;
		}

		size_t getRightChildIndex(const size_t parent)
		{
			return 2 * parent + 2;
		}

		size_t getHeapSize() const
		{
			return _heap.size();
		}

		bool contains(const T& value)
		{
			return std::any_of(_heap.begin(), _heap.end(), [value](T& data) { return data == value; });
		}
	};

	template<typename T>
	void testHeap(Heap<T> heap, bool maxHeap, const std::string & heapType)
	{
		//initialize random seeds
		srand((unsigned int)time(NULL));

		//test push function
		T randomValue;
		for (size_t i = 0; i < 15; ++i) {
			randomValue = rand() % 100 + 1;
			heap.push(randomValue);
		}

		//print heap
		heap.printHeap();

		//test pop function
		T popValue;
		if (heap.pop(popValue))
			std::cout << popValue << " is popped out from the heap.\n";
		else
			std::cout << "Cannot pop value out from the heap.\n";

		//print heap;
		heap.printHeap();
	}
}

#endif
