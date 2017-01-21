
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

namespace arrayStructure
{
	template<typename T>
	class Array
	{
		friend std::ostream &operator<<(std::ostream & output, const Array & outArray)
		{
			std::for_each(outArray, outArray + outArray.getSize(), [&](const T& value) { output << value; });

			return output;
		}

		friend std::istream &operator>>(std::istream & input, Array & inArray)
		{
			std::for_each(inArray, inArray + inArray.getSize(), [&](const T& value) { input >> value; });

			return input;
		}

	public:
		Array()
		{
		}

		//Constructor
		Array(const size_t& arraySize)
			: size(arraySize)
			, arrayList(new T[arraySize])
		{
		}

		//Copy constructor
		Array(const Array& arrayCopy)
			: size(arrayCopy.size)
		{
			arrayList = new T[size];

			for (size_t i = 0; i < size; ++i)
				arrayList[i] = arrayCopy.arrayList[i];
		}

		//Assignment operator
		//const return avoids: (a1 = a2) = a3
		const Array &operator=(const Array& right)
		{
			//avoid self-assignment
			if (&right != this) {
				
				if (getSize() != right.getSize()) {
					if (arrayList != nullptr) {
						delete [] arrayList;
						arrayList = nullptr;

						setSize(right.getSize());
					}
				}
			}

			return *this;
		}

		//Equality operator
		bool operator==(const Array & right) const
		{
			if (getSize() != right.getSize())
				return false;

			for (int i = 0; i < getSize(); ++i) {
				if (arrayList[i] != right.arrayList[i])
					return false;
			}

			return true;
		}

		//Inequality operator
		bool operator!=(const Array& right) const
		{
			return !(*this == right);
		}

		//Subscript operator for non-const objects return modifiable lvalue
		T & operator[](size_t index)
		{
			if (index >= getSize())
				throw std::out_of_range("Subscript out of range");

			return arrayList[index];
		}

		//Subscript operator for const objects returns rvalue
		T operator[](size_t index)const
		{
			if (index >= getSize())
				throw std::out_of_range("Subscript out of range");

			return arrayList[index];
		}

		~Array()
		{
			if (arrayList != nullptr) {
				delete [] arrayList;
				arrayList = nullptr;
			}
		}

		void setSize(const size_t& arraySize)
		{
			size = arraySize;
			arrayList = new T[arraySize];
		}

		size_t getSize() const
		{
			return size;
		}

		void set(size_t index, const T& value)
		{
			if (index > getSize())
				throw std::exception("unable to set value! index is out of range!");

			arrayList[index] = value;
		}

		const T get(size_t index)
		{
			if (index > getSize())
				throw std::exception("unable to get value! index is out of range!");

			return arrayList[index];
		}

		void printArray()
		{
			std::cout << "Array contains " << getSize() << " elements:";
			std::for_each(arrayList, arrayList + size, [](const T& value) { std::cout << value << " "; });
			std::cout << std::endl;
		}

	private:
		T* arrayList;
		size_t size;
	};

	template<typename T>
	void testArray(Array<T> arrayList, T startValue, const size_t iteration, const T increment)
	{
		//Set function test
		for (size_t i = 0; i < iteration / 2; ++i) {
			arrayList.set(i, startValue);
			startValue += increment;
		}

		//Subscript operator test
		for (size_t i = iteration / 2; i < iteration; ++i) {
			arrayList[i] = startValue;
			startValue += increment;
		}

		//Print array
		arrayList.printArray();

		//Get function test
		std::cout << "\nValue at position " << iteration / 2 << " is " << arrayList.get(iteration / 2);
		
		//Subscript operator test
		std::cout << "\nValue at position " << iteration / 4 << " is " << arrayList[iteration / 4];

		//Test copy constructor
		Array<T> copyArray = arrayList;

		std::cout << "\n\nCopy from original array to new array\n";
		std::cout << "\nOriginal array:\n";
		arrayList.printArray();

		std::cout << "\nCopy array:\n";
		copyArray.printArray();


		//Test equality
		std::cout << "\nCopy array is same as original array: " << bool( copyArray == arrayList );

		//Test inequality
		copyArray[iteration / 2] = copyArray[iteration / 2] + 1;
		std::cout << "\n\nOriginal array:\n";
		arrayList.printArray();
		
		std::cout << "\nCopy array:\n";
		copyArray.printArray();

		std::cout << "\nCopy array is different from original array: " << bool( copyArray != arrayList );

		std::cout << "\n\n";
	}
}

#endif