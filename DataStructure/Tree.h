
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

		std::cout << "\nPreorder traversal\n";
		tree.preOrderTraversal();

		std::cout << "\nInorder traversal\n";
		tree.inOrderTraversal();

		std::cout << "\nPostorder traversal\n";
		tree.postOrderTraversal();

		std::cout << "\nLevelOrder traversal\n";
		tree.levelOrderTraversal();

		T popValue = storage[rand() % storage.size()];
		std::cout << "\nPopping value " << popValue << std::endl;
		tree.pop(popValue);

		popValue = storage[rand() % storage.size()];
		std::cout << "\nPopping value " << popValue << std::endl;
		tree.pop(popValue);

		std::cout << "\nAfter popping...\n";

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