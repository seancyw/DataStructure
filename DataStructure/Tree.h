
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <random>
#include <ctime>

namespace binaryTreeStructure 
{
	template<typename T>
	struct treeNode {
		treeNode()
			: data(0)
			, left(nullptr)
			, right(nullptr)
		{
		}

		treeNode(T value)
			: data(value)
			, left(nullptr)
			, right(nullptr)
		{
		}

		T data;
		treeNode* left;
		treeNode* right;
	};

	template<typename T>
	class Tree {
	public:
		Tree()
		{
			root = nullptr; // indicate tree is initially empty
		}
	
		~Tree()
		{
			destroyTree(&root);
		}

		void push(const T& data)
		{
			pushHelper(&root, data);
		}

		treeNode<T>* pop(const T& data)
		{
			return popHelper(&root, data);
		}

		void preOrderTraversal() const
		{
			preOrderHelper(root);
		}

		void inOrderTraversal() const
		{
			inOrderHelper(root);
		}

		void postOrderTraversal() const
		{
			postOrderHelper(root);
		}

		void levelOrderTraversal() const
		{
			levelOrderHelper(root);
		}

		bool isBinarySearchTree()
		{
			return isBinarySearchTreeHelper(root, INT_MIN, INT_MAX);
		}

		bool search(const T& data)
		{
			return searchHelper(root, data);
		}

		treeNode<T>* searchNode(const T& data)
		{
			return searchNodeHelper(root, data);
		}

		T getSuccessor(const T& data)
		{
			return getSuccessorHelper(root, data);
		}

		treeNode<T>* getSuccessorNode(const T& data)
		{
			return getSuccessorNodeHelper(root, data);
		}

		T getPredecessor(const T& data)
		{
			return getPredecessorHelper(root, data);
		}

		treeNode<T>* getPredecessorNode(const T& data)
		{
			return getPredecessorNodeHelper(root, data);
		}

	private:
		treeNode<T>* root;

		//utility functions
		void pushHelper(treeNode<T>** node, const T& data)
		{
			//subtree is empty
			//create new tree node containing value
			if (*node == nullptr) {
				*node = new treeNode<T>(data);
			}
			else {
				//data to insert is less than data in current node
				if (data < (*node)->data) {
					pushHelper(&((*node)->left), data);
				}
				else {
					// data to insert is greater than data in current node
					if (data > (*node)->data)
						pushHelper((&(*node)->right), data);
					else
						std::cout << data << " is duplicated" << std::endl;
				}
			}
		}

		treeNode<T>* popHelper(treeNode<T>** node, const T& data)
		{
			//subtree is empty
			//nothing to delete
			if (*node == nullptr) {
				return (*node);
			}
			else {

				//data to remove is less than data in current node
				if (data < (*node)->data) {
					popHelper(&(*node)->left, data);
				}
				else if(data > (*node)->data ) {
					//data to remove is greater than data in current node
					popHelper(&(*node)->right, data);
				}
				else {
					//case 1: no child
					if ((*node)->left == nullptr && (*node)->right == nullptr) {
						delete (*node);
						(*node) = nullptr;
					}
					//case 2: one child
					else if ((*node)->left == nullptr) {
						treeNode<T>* tempNode = (*node);
						(*node) = (*node)->right;
						delete tempNode;
					}
					else if ((*node)->right == nullptr) {
						treeNode<T>* tempNode = (*node);
						(*node) = (*node)->left;
						delete tempNode;
					}
					//case 3: two child
					else {
						//Note**: the concept will be contrastly for left subtree, which 
						//find the maximum data instead of minimum in step 2

						//1. Find the minimum value in the right subtree
						treeNode<T>* tempNode = findMinimumNode((*node)->right);
						
						//2. Replace the value with the minimum data in right subtree
						(*node)->data = tempNode->data;

						//3. Delete the duplicate data in right subtree
						(*node)->right = popHelper(&(*node)->right, tempNode->data);
					}

					return (*node);
				}
			}

			return (*node);
		}

		//Find the minimum node in a tree (Iterative method)
		treeNode<T>* findMinimumNode(treeNode<T>* node) 
		{
			while (node->left != NULL)
				node = node->left;
			
			return node;
		}

		//Find the minimum data in a tree (iterative method)
		T findMinimumIterative(treeNode<T>* node)
		{
			if (node == nullptr) {
				std::cout << "Tree is empty!" << endl;
				return -1;
			}

			while (node->left != NULL)
				node = node->left;

			return node->data;
		}

		//Find the minimum data in a tree (recursive method)
		T findMinimumRecursive(treeNode<T>* node)
		{
			if (node == nullptr) {
				std::cout << "Tree is empty!" << endl;
				return -1;
			}
			else if (node->left == NULL) {
				return node->data;
			}

			//search in left subtree
			return findMinimumRecursive(node->left);
		}

		//Find the maximum node in a tree (Iterative method)
		treeNode<T>* findMaximumNode(treeNode<T>* node)
		{
			while (node->right != NULL)
				node = node->right;

			return node;
		}

		//Find the maximum data in a tree (iterative method)
		T findMaximumIterative(treeNode<T>* node)
		{
			if (node == nullptr) {
				std::cout << "Tree is empty!" << endl;
				return -1;
			}

			while (node->right != NULL)
				node = node->right;

			return node->data;
		}

		//Find the minimum data in a tree (recursive method)
		T findMaximumRecursive(treeNode<T>* node)
		{
			if (node == nullptr) {
				std::cout << "Tree is empty!" << endl;
				return -1;
			}
			else if (node->right == NULL) {
				return node->data;
			}

			//search in right subtree
			return findMaximumRecursive(node->right);
		}

		//Height of tree: number of edges in longest path 
		//from root to a leaf node
		//Height of tree = Height of root
		//Height of tree with 1 node = 0
		int findHeight(treeNode<T>* node)
		{
			if (node == nullptr)
				return -1;

			return max(findHeight(node->left), findHeight(node->right)) + 1;
		}

		//Depth of a node = number of edges in path from root to that node
		//			 10  (H = 1, Depth = 0)
		//		   /   \	
		//        3    12  (H = 0, Depth = 1)
		
		//Tree traversal: process of visiting(reading/processing data) 
		//each node in the tree exactly once in some order
		//1. Breath-First traversal( level order from root)
		void levelOrderHelper(treeNode<T>* node) const
		{
			if (node == nullptr)
				return;

			std::queue<treeNode<T>*> queues;

			queues.push(node);
			
			//while there is at least one discovered node
			while (!queues.empty()) {
				treeNode<T>* current = queues.front();
				std::cout << current->data << " ";

				if (current->left != nullptr)
					queues.push(current->left);

				if (current->right != nullptr)
					queues.push(current->right);

				//removing the element at front
				queues.pop();
			}

			cout << endl;
		}


		//2. Depth-First traversal: PreOrder, InOrder, PostOrder
		//<root><left><right>	: process root first->process left subtree->process right subtree
		void preOrderHelper(treeNode<T>* node) const
		{
			if (node != nullptr) {
				std::cout << node->data << ' '; //process node
				preOrderHelper(node->left);		//traverse left subtree
				preOrderHelper(node->right);	//traverse right subtree
			}
		}

		//<left><root><right>	: process left first->process root subtree->process right subtree
		void inOrderHelper(treeNode<T>* node) const
		{
			if (node != nullptr) {
				inOrderHelper(node->left);		//traverse left subtree
				std::cout << node->data << ' ';	//process node;
				inOrderHelper(node->right);		//traverse right subtree
			}
		}

		//<left><right><root>	: process left first->process right subtree->process root subtree
		void postOrderHelper(treeNode<T>* node) const
		{
			if (node != nullptr) {
				postOrderHelper(node->left);    //traverse left subtree
				postOrderHelper(node->right);   //traverse right subtree
				std::cout << node->data << ' '; //process node
			}
		}
		
		void destroyTree(treeNode<T>** node)
		{
			if ((*node) != nullptr) {
				destroyTree(&(*node)->left);
				destroyTree(&(*node)->right);

				delete (*node);
			}

		}

		//Check if the tree is a binary search tree
		//Method 1: recursively loop to check if each node
		//left and right subtree is less/greater than the root value
		//This is very expensive operation
		bool isBinarySearchTreeHelper(treeNode<T>* node)
		{
			//base case to exit recursion
			if (node == nullptr)
				return true;

			if (isSubtreeLesser(node->left, node->data) &&
				isSubtreeGreater(root->right, node->data) &&
				isBinarySearchTree(root->left) &&
				isBinarySearchTree(root->right))
				return true;
			else
				return false;
		}
		
		//Method 2: use lower and upper bound value to check if the
		//node value at left and right subtree is within the range
		//if yes, they are binary subtree else they're not
		bool isBinarySearchTreeHelper(treeNode<T>* node, const T& minValue, const T& maxValue)
		{
			//base case to exit recursion
			if (node == nullptr)
				return true;

			if (node->data > minValue &&
				node->data < maxValue &&
				isBinarySearchTreeHelper(root->left, minValue, node->data) &&
				isBinarySearchTreeHelper(root->right, node->data, maxValue))
				return true;
			else
				return false;
		}

		bool isSubtreeLesser(treeNode<T>* node, const T& value)
		{
			//base case to exit recursion
			if (node == nullptr)
				return true;

			if (node->data <= value &&
				isSubtreeLesser(node->left, value) &&
				isSubtreeLesser(node->right, value))
				return true;
			else
				return false;
		}

		bool isSubtreeGreater(treeNode<T>* node, const T& value)
		{
			//base case to exit recursion
			if (node == nullptr)
				return true;

			if (node->data >= value &&
				isSubtreeGreater(node->left, value) &&
				isSubtreeGreater(node->right, value))
				return true;
			else
				return false;
		}

		bool searchHelper(treeNode<T>* node, const T& value)
		{
			if (node == nullptr)
				return false;

			if (value == node->data)
				return true;
			else if (value < node->data)
				return searchHelper(node->left, value);
			else
				return searchHelper(node->right, value);
		}

		treeNode<T>* searchNodeHelper(treeNode<T>* node, const T& value)
		{
			if (node == nullptr)
				return node;

			if (value == node->data)
				return node;
			else if (value < node->data)
				return searchNodeHelper(node->left, value);
			else
				return searchNodeHelper(node->right, value);
		}

		//Function to find successor in a Binary search tree
		T getSuccessorHelper(treeNode<T>* node, T data)
		{
			//Search the node - O(h) h: height of tree
			treeNode<T>* current = searchNode(data);

			if (current == nullptr)
				return current->data;

			//Case 1: node has right subtree  - O(h) h: height of tree
			if (current->right != nullptr) {
				return findMinimumIterative(current->right);
			}
			//Case 2: no right subtree - O(h) h: height of tree
			else {
				treeNode<T>* successor = nullptr;
				treeNode<T>* ancestor = node;	//traverse from root node

				while (ancestor != current) {
					if (current->data < ancestor->data) {
						successor = ancestor;
						ancestor = ancestor->left;
					}
					else {
						ancestor = ancestor->right;
					}
				}

				return successor->data;
			}
		}

		//Function to find successor in a Binary search tree
		treeNode<T>* getSuccessorNodeHelper(treeNode<T>* node, T data)
		{
			//Search the node - O(h) h: height of tree
			treeNode<T>* current = search(data);
		
			if (current == nullptr)
				return null;
		
			//Case 1: node has right subtree  - O(h) h: height of tree
			//Go deep to the leftmost node in right subtree
			//find minimum in right subtree
			if (current->right != nullptr) {
				return findMinimumNode(current->right);
			}
			//Case 2: no right subtree - O(h) h: height of tree
			//Go to the nearest ancestor for which given node would
			//be in the left subtree
			else {
				treeNode<T>* successor = nullptr;
				treeNode<T>* ancestor = node;	//traverse from root node
		
				while (ancestor != current) {
					if (current->data < ancestor->data) {
						successor = ancestor;
						ancestor = ancestor->left;
					}
					else {
						ancestor = ancestor->right;
					}
				}
		
				return successor;
			}
		}

		T getPredecessorHelper(treeNode<T>* node, const T& data)
		{
			treeNode<T>* current = searchNode(data);

			if (current == nullptr)
				return current->data;

			//Case 1: node has left subtree
			//Go deep to the rightmost node in left subtree
			//find maximum in right subtree
			if (current->left != nullptr) {
				return findMaximumIterative(current->left);
			}
			//Case 2: no left subtree - O(h) h: height of tree
			//Go to the nearest ancestor for which given node would
			//be in the right subtree
			else {
				treeNode<T>* predecessor = nullptr;
				treeNode<T>* ancestor = node;	//traverse from root node

				while (ancestor != current) {
					if (current->data > ancestor->data) {
						predecessor = ancestor;
						ancestor = ancestor->right;
					}
					else {
						ancestor = ancestor->left;
					}
				}

				return predecessor->data;
			}

		}

		treeNode<T>* getPredecessorNode(treeNode<T>* node, const T& data)
		{
			treeNode<T>* current = searchNode(data);

			if (current == nullptr)
				return current;

			//Case 1: node has left subtree
			//Go deep to the rightmost node in left subtree
			//find maximum in right subtree
			if (current->left != nullptr) {
				return findMaximumIterative(current->left);
			}
			//Case 2: no left subtree - O(h) h: height of tree
			//Go to the nearest ancestor for which given node would
			//be in the right subtree
			else {
				treeNode<T>* predecessor = nullptr;
				treeNode<T>* ancestor = node;	//traverse from root node

				while (ancestor != current) {
					if (current->data > ancestor->data) {
						predecessor = ancestor;
						ancestor = ancestor->right;
					}
					else {
						ancestor = ancestor->left;
					}
				}

				return predecessor;
			}
		}
	};

	template<typename T>
	void testTree(Tree<T> tree, int iteration, std::string treeType)
	{
		//initialize random seeds
		srand((unsigned int)time(NULL));

		//Initialize a empty vector to store value
		//And randomly pick one value to do popping operation
		std::vector<T> storage;

		for (int iter = 0; iter < iteration; ++iter) {
			T randomValue = rand() % 100 + 1;
			std::cout << std::fixed << std::setprecision(1) << "Pushing " << randomValue << " into tree" << std::endl;
			tree.push(randomValue);
			storage.push_back(randomValue);
		}

		//Print tree in different traversal method
		std::cout << "\nPreorder traversal\n";
		tree.preOrderTraversal();

		std::cout << "\nInorder traversal\n";
		tree.inOrderTraversal();

		std::cout << "\nPostorder traversal\n";
		tree.postOrderTraversal();

		std::cout << "\nLevelOrder traversal\n";
		tree.levelOrderTraversal();

		//Check if this is a binary search tree
		std::cout << "\nIs this a binary search tree: " << tree.isBinarySearchTree() << std::endl;

		//Test Search function
		T searchValue = storage[rand() % storage.size()];
		std::cout << "\nValue " << searchValue << " found: " << tree.search(searchValue);

		std::cout << "\nValue " << searchValue + 10 << " found: " << tree.search(searchValue + 10) << " \n";

		//Test getSuccessor function
		searchValue = storage[rand() % storage.size()];
		std::cout << "\nSuccessor for value " << searchValue << " is : " << tree.getSuccessor(searchValue) << " \n";
		
		//Test getPredecessor function
		searchValue = storage[rand() % storage.size()];
		std::cout << "\nPredecessor for value " << searchValue << " is : " << tree.getPredecessor(searchValue) << " \n";

		//Pop value
		T popValue = storage[rand() % storage.size()];
		std::cout << "\nPopping value " << popValue << std::endl;
		tree.pop(popValue);

		popValue = storage[rand() % storage.size()];
		std::cout << "Popping value " << popValue << std::endl;
		tree.pop(popValue);

		std::cout << "\nAfter popping...";

		//Print tree in different traversal method
		std::cout << "\nPreorder traversal\n";
		tree.preOrderTraversal();

		std::cout << "\nInorder traversal\n";
		tree.inOrderTraversal();

		std::cout << "\nPostorder traversal\n";
		tree.postOrderTraversal();

		std::cout << "\nLevelOrder traversal\n";
		tree.levelOrderTraversal();
	}
}

#endif