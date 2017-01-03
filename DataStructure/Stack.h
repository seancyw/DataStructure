
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>

namespace stackStructure {

	//Implementation from C++ How To Program 8th Edition by Paul Deitel Harvey
	template<typename T>
	class Stack
	{
	public:
		//Default stack size in 10
		explicit Stack(int = 10);

		~Stack();

		//push an element onto the stack
		bool push(const T&);

		//pop an element off the stack
		bool pop(T &);

		//determine if the stack empty
		bool isEmpty() const;

		//determine whether the stack is full
		bool isFull() const;

	private:
		int size;	//number of elements in stack
		int top;	//location of top element(-1 means empty)
		T* stackPointer;	//pointer to internal representation of the stack
	};

	template<typename T>
	Stack<T>::Stack(int maxSize)
		: size(maxSize > 0 ? maxSize : 10) //validate size
		, top(-1)	//stack initially empty
		, stackPointer(new T[size]) //allocate memory for elements
	{

	}

	template<typename T>
	Stack<T>::~Stack()
	{
		delete[] stackPointer;
	}

	//push an element onto the stack
	template<typename T>
	bool Stack<T>::push(const T& pushValue)
	{
		if (!isFull()) {
			stackPointer[++top] = pushValue;
			return true;
		}

		return false;
	}

	//pop an element off the stack
	template<typename T>
	bool Stack<T>::pop(T & popValue)
	{
		if (!isEmpty()) {
			popValue = stackPointer[top--];
			return true;
		}

		return false;
	}

	//determine if the stack empty
	template<typename T>
	bool Stack<T>::isEmpty() const
	{
		return top == -1;
	}

	//determine whether the stack is full
	template<typename T>
	bool Stack<T>::isFull() const
	{
		return top == size - 1;
	}

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
#endif