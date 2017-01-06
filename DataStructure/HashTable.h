
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "LinkedList.h"
#include <string>

//string hash table implementation
namespace hashTableStructure {
	class HashTable
	{
	public:
		HashTable(size_t size)
			: tableSize(size)
		{
			hashTable = new linkedListStructure::LinkedList<std::string>[size];
		}

		~HashTable()
		{
			if (hashTable != nullptr)
				delete[] hashTable;
		}

		bool insertItem(std::string data)
		{
			size_t key = hash(data);

			if (!hashTable[key].contains(data)) {
				hashTable[key].pushFront(data);
				return true;
			}

			return false;
		}

		bool removeItem(std::string data)
		{
			size_t key = hash(data);

			if (hashTable[key].popNode(data))
				return true;
			else
				return false;
		}

		size_t getTableSize() const
		{
			return tableSize;
		}

		void printTable() const
		{
			std::cout << "Hash Table List" << std::endl;
			for (size_t i = 0; i < tableSize; ++i) {
				std::cout << "Array " << i + 1 << std::endl;
				hashTable[i].printList();
			}
		}

		void printHistogram() const
		{
			std::cout << "Hash Table Histogram" << std::endl;
			for (size_t i = 0; i < tableSize; ++i) {

				std::cout << "Array " << i + 1 << ": ";
				for (size_t j = 0; j < hashTable[i].getSize(); ++j) {
					std::cout << " X ";
				}
				std::cout << std::endl;
			}
		}

	private:
		linkedListStructure::LinkedList<std::string> *hashTable;
		size_t tableSize;

		//utility function to get hash key for string type
		size_t hash(std::string& data)
		{
			size_t value = 0;

			for (size_t i = 0; i < data.length(); ++i)
				value += data[i];

			return value % tableSize;
		}
	};

	void testHashTable()
	{
		HashTable table(10);

		table.insertItem("Happy");
		table.insertItem("New");
		table.insertItem("Year");
		table.insertItem("This");
		table.insertItem("is");
		table.insertItem("a");
		table.insertItem("testing");
		table.insertItem("function");

		table.printTable();
		table.printHistogram();

		table.removeItem("a");
		table.printTable();
		table.printHistogram();

	}

}

#endif