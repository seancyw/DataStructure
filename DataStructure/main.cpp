#include <iostream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

int main()
{
	Node* A = new Node(10);
	Node* B = new Node(20);
	Node* C = new Node(30);
	Node* D = new Node(40);
	Node* E = new Node(50);
	Node* F = new Node(60);

	LinkedList list;

	list.pushFront(A);
	list.pushFront(B);
	list.printList();

	list.pushBack(C);
	list.pushBack(D);
	list.printList();

	list.popFront();
	list.printList();

	list.popBack();
	list.printList();

	list.pushFront(F);
	list.printList();

	list.pushBack(E);
	list.printList();

	cin.ignore();

	return 0;
}