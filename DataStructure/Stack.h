
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include "LinkedList.h"

//Stack implementation using array of pointer 
namespace stackStructure {

	//Implementation from C++ How To Program 8th Edition by Paul Deitel Harvey
	template<typename T>
	class Stack
	{
	public:
		//Default stack size in 10
		explicit Stack(int maxSize)
			: size(maxSize > 0 ? maxSize : 10) //validate size
			, top(-1)	//stack initially empty
			, stackPointer(new T[size]) //allocate memory for elements
		{
		}

		~Stack()
		{
			delete[] stackPointer;
		}

		//push an element onto the stack
		bool push(const T& pushValue)
		{
			if (!isFull()) {
				stackPointer[++top] = pushValue;
				return true;
			}

			return false;
		}

		//pop an element off the stack
		bool pop(T & popValue)
		{
			if (!isEmpty()) {
				popValue = stackPointer[top--];
				return true;
			}

			return false;
		}

		//determine if the stack empty
		bool isEmpty() const
		{
			return top == -1;
		}

		//determine whether the stack is full
		bool isFull() const
		{
			return top == size - 1;
		}

	private:
		int size;	//number of elements in stack
		int top;	//location of top element(-1 means empty)
		T* stackPointer;	//pointer to internal representation of the stack
	};

	template<typename T>
	void testStack(Stack<T> stack, T initialValue, T incrementStep, std::string stackTypeName)
	{
		while (stack.push(initialValue)) {
			std::cout << "Pushing " << initialValue << " to the " << stackTypeName << std::endl;
			initialValue += incrementStep;
		}

		std::cout << "Stack is full! Cannot push item anymore" << std::endl;

		T tempValue;
		while (stack.pop(tempValue))
			std::cout << tempValue << " is pop out from the " << stackTypeName << std::endl;

		std::cout << "Stack is empty cannot pop element anymore" << std::endl;
	}
}

//Stack implementation with linked list using private inheritance
namespace stackListStructure {

	//Implementation from C++ How To Program 8th Edition by Paul Deitel Harvey
	template<typename T>
	class Stack : private linkedListStructure::LinkedList<T>
	{
	public:
		//no constructor; Linked-list constructor does the initialization

		//push an element onto the stack
		void push(const T& data)
		{
			return pushFront(data);
		}

		//pop an element off the stack
		bool pop(T & data)
		{
			return popFront(data);
		}

		//determine if the stack empty
		bool isEmpty() const
		{
			return this->isEmpty();
		}

		//print stack data
		void printStack() const
		{
			this->printList();
		}
	};

	//driver to test functionality of stackList class
	template<typename T>
	void testStack(Stack<T> stack, int iteration, T initialValue, T incrementStep, std::string stackTypeName)
	{
		for (int iter = 0; iter < iteration; ++iter ) {
			stack.push(initialValue);
			std::cout << "Pushing " << initialValue << " to the " << stackTypeName << std::endl;
			initialValue += incrementStep;
		}

		stack.printStack();

		T tempValue;
		while (stack.pop(tempValue))
			std::cout << tempValue << " is pop out from the " << stackTypeName << std::endl;

		std::cout << "Stack is empty cannot pop element anymore" << std::endl;

		stack.printStack();
	}
}

//Stack implementation with linked list through composition
namespace stackListCompositionStructure {

	//Implementation from C++ How To Program 8th Edition by Paul Deitel Harvey
	template<typename T>
	class Stack
	{
	public:
		//no constructor; Linked-list constructor does the initialization

		//push an element onto the stack
		void push(const T& data)
		{
			return stackList.pushFront(data);
		}

		//pop an element off the stack
		bool pop(T & data)
		{
			return stackList.popFront(data);
		}

		//determine if the stack empty
		bool isEmpty() const
		{
			return stackList.isEmpty();
		}

		//print stack data
		void printStack() const
		{
			stackList.printList();
		}

	private:
		linkedListStructure::LinkedList<T> stackList;	//composed List Object
	};

	//driver to test stackListComposition structure
	template<typename T>
	void testStack(Stack<T> stack, int iteration, T initialValue, T incrementStep, std::string stackTypeName)
	{
		for (int iter = 0; iter < iteration; ++iter) {
			stack.push(initialValue);
			std::cout << "Pushing " << initialValue << " to the " << stackTypeName << std::endl;
			initialValue += incrementStep;
		}

		stack.printStack();

		T tempValue;
		while (stack.pop(tempValue))
			std::cout << tempValue << " is pop out from the " << stackTypeName << std::endl;

		std::cout << "Stack is empty cannot pop element anymore" << std::endl;

		stack.printStack();
	}
}
#endif