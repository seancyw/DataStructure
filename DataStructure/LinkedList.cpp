
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Node();
	size = 0;
}


LinkedList::~LinkedList()
{
	Node* current  = head;
	Node* previous = head;

	while(current) {
		previous = current;
		current  = previous->next;

		delete previous;
	}
}

void LinkedList::pushBack(Node* newNode)
{
	//First Node
	if (head->next == NULL) {
		++size;
		head = newNode;

		return;
	}

	Node* current  = head;
	Node* previous = head;

	while(current) {

		previous = current;

		if(current->next == NULL) {
			current->next = newNode;
			++size;
			return;
		}

		current = previous->next;
	}

}

void LinkedList::pushFront(Node* newNode)
{
	//First Node
	if (head == NULL) {
		++size;
		head = newNode;
		return;
	}

	newNode->next = head->next;
	head->next    = newNode;
	++size;
	return;
}

bool LinkedList::popBack()
{
	//Return false if no node to remove
	if (head->next == NULL) {
		return false;
	}

	Node* current  = head;
	Node* previous = head;
	int count = 0;

	while(current) {

		previous = current;

		if(count == size - 1) {
			delete current->next;
			current->next = NULL;
			--size;
			return true;
		}

		current = previous->next;
		count++;
	}

	return false;
}

bool LinkedList::popFront()
{
	//Return false if no node to remove
	if (head->next == NULL) {
		return false;
	}
	
	Node* current  = head;
	Node* previous = head;
	
	while (current) {
		
		if (current != head) {
			previous->next = current->next;
			delete current;
			--size;
			return true;
		}
		previous = current;
		current = previous->next;
	}

	return false;
}

bool LinkedList::isEmpty()
{
	return (size == 0);
}

int  LinkedList::getSize() const
{
	return size;
}

void LinkedList::printList()
{
	Node* current  = head;
	Node* previous = head;

	std::cout << "LinkedList contains " << getSize() << " item \n";

	int count = 0;
	while (current) {
		previous = current;

		std::cout << "Position " << count++ << "\t" << previous->data << "\n";
		current = previous->next;
	}
}