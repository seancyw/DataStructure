
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace heapStructure
{
	template<typename T>
	class Heap 
	{
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
			_heap.push_back(value);

			bubbleUp(getHeapSize() - 1);
		}

		bool pop(T& value)
		{
			if (isEmpty())
				return false;
			
			_heap._Pop_back_n(getHeapSize());
			bubbleDown(0);
		}

		void bubbleDown(int index)
		{
			if (_maxHeap) {
				//If replaced elements is less than any of its child
				//node, swap the elements with its greatest child

			}
			else {
				//If replaced elements is greater than any of its child
				//node, swap the elements with its smallest child

			}
			
		}

		//Parent n have child of 2n+1 and 2n+2
		//child n has a parent of (n-1/2) round to lowest value
		void bubbleUp(size_t index)
		{
			//return if less than 2 elements on the heap
			if (_heap.size() < 2)
				return;

			if (_maxHeap) {
				//if inserted element is greater than its parent 
				//node, swap the elements with its parents


			}
			else {
				//if inserted element is smaller than its parent 
				//node, swap the elements with its parents

			}
		}

		void printHeap()
		{
			std::cout << _maxHeap ? "Max heap " : "Min heap " << " contains the followings elements.\n";

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
	};

}

#endif
