#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>

template <class T>
class BinaryTree
{
	//variables used to hold data
	private:
		struct TreeNode
		{
			T value;
			TreeNode *left;
			TreeNode *right;
		};
		TreeNode *root;

		//inserts node into binary tree
		void insert(TreeNode *&nodePtr, TreeNode *&newNode) {
			if (nodePtr == nullptr) {
				nodePtr = newNode;
			}
			else if (newNode->value < nodePtr->value) {
				insert(nodePtr->left, newNode);
			}
			else {
				insert(nodePtr->right, newNode);
			}
		}
		//destroys binary tree
		void destroySubtree(TreeNode *nodePtr) {
			if (nodePtr) {
				if (nodePtr->left) {
					destroySubtree(nodePtr->left);
				}
				if (nodePtr->right) {
					destroySubtree(nodePtr->right);
				}
				delete nodePtr;
			}
		}
		//removes node
		void deleteNode(T item, TreeNode *&nodePtr) {
			if (item < nodePtr->value) {
				deleteNode(item, nodePtr->left);
			}
			else if (item > nodePtr->value) {
				deleteNode(item, nodePtr->right);
			}
			else {
				makeDeletion(nodePtr);
			}
		}
		//makes the actual deletion of the node
		void makeDeletion(TreeNode *&nodePtr) {

			TreeNode *tempNodePtr = nullptr;

			if (nodePtr == nullptr) {
				cout << "Cannot delete empty node.\n";
			}
			else if (nodePtr->right == nullptr) {
				tempNodePtr = nodePtr;
				nodePtr = nodePtr->left;
				delete tempNodePtr;
			}
			else if (nodePtr->left == nullptr) {
				tempNodePtr = nodePtr;
				nodePtr = nodePtr->right;
				delete tempNodePtr;
			}
			else {
				tempNodePtr = nodePtr->right;
				while (tempNodePtr->left) {
					tempNodePtr = tempNodePtr->left;
				}
				tempNodePtr->left = nodePtr->left;
				tempNodePtr = nodePtr;

				nodePtr = nodePtr->right;
				delete tempNodePtr;
			}

		}
		//displays tree in specific order
		void displayInOrder(TreeNode *nodePtr) const {
			if (nodePtr) {
				displayInOrder(nodePtr->left);
				cout << nodePtr->value << endl;
				displayInOrder(nodePtr->right);
			}
		}
		//displays tree in specific order
		void displayPreOrder(TreeNode *nodePtr) const {
			if (nodePtr) {
				cout << nodePtr->value << endl;
				displayInOrder(nodePtr->left);
				displayInOrder(nodePtr->right);
			}
		}
		//displays tree in specific order
		void displayPostOrder(TreeNode *nodePtr) const {
			if (nodePtr) {
				displayInOrder(nodePtr->left);
				displayInOrder(nodePtr->right);
				cout << nodePtr->value << endl;
			}
		}
		//returns number of nodes in tree
		int numberofNodes(TreeNode *nodePtr) const {
			int count = 1;

			if (nodePtr == nullptr) {
				return 0;
			}
			else {
				count += numberofNodes(nodePtr->right);
				count += numberofNodes(nodePtr->left);
				return count;
			}
		}

		// returns number of levels in tree
		int displayHeight(TreeNode *nodePtr) const {
			if (nodePtr == nullptr) {
				return 0;
			}
			else {
				int left_height = displayHeight(nodePtr->left);
				int right_height = displayHeight(nodePtr->right);
				return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
			}
		}

		//returns the largest number of nodes on same level
		int displayWidth(TreeNode *nodePtr) const {

			int level, width, largest_width = 0;
			int height = displayHeight(nodePtr);

			for (int i = 1; i <= height; i++) {
				width = findWidth(nodePtr, i);
				if (width > largest_width) {
					largest_width = width;
				}
			}
			return largest_width;
		}
		//finds width of a level
		int findWidth(TreeNode *nodePtr, int level) const {
			if (nodePtr == nullptr) {
				return 0;
			}
			if (level == 1) {
				return 1;
			}
			else if (level > 1) {
				return findWidth(nodePtr->left, level - 1) + findWidth(nodePtr->right, level - 1);
			}
		}
		//finds number of leaf nodes
		int displayLeafNodes(TreeNode *nodePtr) const {

			if (nodePtr == nullptr) {
				return 0;
			}
			if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
				return 1;
			}
			else {
				return displayLeafNodes(nodePtr->left) + displayLeafNodes(nodePtr->right);
			}
		}

	public:
	//counstructor
	BinaryTree() {
		root = nullptr;
	}
	//deconstructor
	~BinaryTree() {
		destroySubtree(root);
	}
	//public function for insert
	void insertNode(T item) {
		TreeNode *newNode = nullptr;

		newNode = new TreeNode;
		newNode->value = item;
		newNode->left = newNode->right = nullptr;

		insert(root, newNode);
	}
	//finds if value is in tree
	bool searchNode(T item) {

		TreeNode *nodePtr = root;
		while (nodePtr) {
			if (nodePtr->value == item) {
				return true;
			}
			else if (item < nodePtr->value) {
				nodePtr = nodePtr->left;
			}
			else {
				nodePtr = nodePtr->right;
			}
		}
		return false;
	}
	//returns object if found in tree
	T searchNodeObject(T item) {
		TreeNode *nodePtr = root;
		while (nodePtr) {
			if (nodePtr->value == item) {
				return nodePtr->value;
			}
			else if (item < nodePtr->value) {
				nodePtr = nodePtr->left;
			}
			else {
				nodePtr = nodePtr->right;
			}
		}
		return nodePtr->value;
	}
	//public for deleting node
	void remove(T item) {

		deleteNode(item, root);
	}
	//public display content of tree
	void displayInOrder() const {
		displayInOrder(root);
	}
	//public display content of tree
	void displayPreOrder() const {
		displayPreOrder(root);
	}
	//public display content of tree
	void displayPostOrder() const {
		displayPostOrder(root);
	}
	//displays number of nodes public function
	void numberofNodes() const {
		int count = numberofNodes(root);
		cout << "Number of Nodes: " << count << endl;
	}
	//displays height public
	void displayHeight() const {
		int height = displayHeight(root);
		cout << "Height: " << height << endl;
	}
	//displays width public
	void displayWidth() const {
		int width = displayWidth(root);
		cout << "Width: " << width << endl;
	}
	//displays leaves public
	void displayLeafNodes() const {
		int leaves = displayLeafNodes(root);
		cout << "Number of Leaf Nodes: " << leaves << endl;
	}
};
#endif

