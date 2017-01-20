
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

namespace arrayStructure
{
	template<typename T>
	class Array
	{
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

			return arrayList[index] = value;
		}

	private:
		T* arrayList;
		size_t size;
	};
}

#endif