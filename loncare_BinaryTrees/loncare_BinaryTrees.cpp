// loncare_BinaryTrees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "EmployeeInfo.h"
using namespace std;

int main()
{
	//variables
	string input;
	BinaryTree<EmployeeInfo> emp_tree;
	BinaryTree<string> input_tree;
	//intitalizing tree
	emp_tree.insertNode(EmployeeInfo(1021, "John Williams"));
	emp_tree.insertNode(EmployeeInfo(1057, "Bill Witherspoon"));
	emp_tree.insertNode(EmployeeInfo(2487, "Jennifer Twain"));
	emp_tree.insertNode(EmployeeInfo(3769, "Sophia Lancaster"));
	emp_tree.insertNode(EmployeeInfo(1017, "Debbie Reece"));
	emp_tree.insertNode(EmployeeInfo(1275, "George McMullen"));
	emp_tree.insertNode(EmployeeInfo(1899, "Ashley Smith"));
	emp_tree.insertNode(EmployeeInfo(4218, "Josh Plemmons"));
	//additional variables
	int main_menu = -1;
	int submenu = -1;
	int search = -1;
	bool found = false;

	//main menu
	while (main_menu != 9) {
		submenu = -1;
		cout << "***** Binary Tree MENU *****" << endl << endl;
		cout << "1. Insert one or more items" << endl;
		cout << "2. Delete one or more items" << endl;
		cout << "3. Display the nodes of the tree" << endl;
		cout << "4. Get the number of nodes in the tree" << endl;
		cout << "5. Get the height of the tree" << endl;
		cout << "6. Get the width of the tree" << endl;
		cout << "7. Get the number of leaves in the tree" << endl;
		cout << "8. Find an employee in the employee tree" << endl;
		cout << "9. Exit" << endl << endl;
		cout << "Your choice, please (1-9) :";
		cin >> main_menu;
		while (main_menu < 1 || main_menu > 9) {
			cout << "Enter a number from 1 to 9 please: ";
			cin >> main_menu;
		}
		// testing input
		switch (main_menu)
		{
		case 1:
			//insert values
			while (input != "00") {
				cout << "Inserting any number or text to the tree or 00 to exit inserting\n";
				cin >> input;
				if (input == "00") {
					break;
				}
				input_tree.insertNode(input);
			}
			input = "0";
			break;
		case 2:
			//deleting values
			while (input != "00") {
				cout << "Delete any number or text to the tree or 00 to exit deleting\n";
				cin >> input;
				if (input == "00") {
					break;
				}
				if (input_tree.searchNode(input)) {
					input_tree.remove(input);
				}
				else {
					cout << "Error: Cannot delete node that does not exist\n\n";
				}
			}
			input = "0";
			break;
		case 3:
			//display content of tree
			//submenu
			while (submenu != 4) {
				cout << "***** Binary Trees display nodes Sub MENU *****\n\n";
				cout << "1. Via Inorder traversal\n";
				cout << "2. Via Preorder traversal\n";
				cout << "3. Via Postorder traversal\n";
				cout << "4. Exit\n\n";
				cout << "Your choice, please (1-4) :";
				cin >> submenu;
				while (submenu < 1 || submenu > 4) {
					cout << "Enter a number from 1 to 4 please: ";
					cin >> main_menu;
				}
				switch (submenu)
				{
					//inorder
				case 1:
					cout << "Now here are the nodes via inorder traversal\n";
					input_tree.displayInOrder();
					break;
				case 2:
					//preorder
					cout << "Now here are the nodes via preorder traversal\n";
					input_tree.displayPreOrder();
					break;
				case 3:
					//postorder
					cout << "Now here are the nodes via postorder traversal\n";
					input_tree.displayPostOrder();
					break;
				default:
					break;
				}
			}
			break;
		case 4:
			//node number
			input_tree.numberofNodes();
			break;
		case 5:
			//height of tree
			input_tree.displayHeight();
			break;
		case 6:
			//width of tree
			input_tree.displayWidth();
			break;
		case 7:
			//leaves of tree
			input_tree.displayLeafNodes();
			break;
		case 8:
			//employee search
			cout << "Here is the workforce:\n\n";
			//prints workforce
			emp_tree.displayInOrder();
			while (search != 0) {
				cout << "Enter an employee number to find or 0 to exit :";
				cin >> search;
				//searches for employee
				found = emp_tree.searchNode(EmployeeInfo(search, ""));
				if (found == false) {
					cout << "That employee was not found\n\n\n";
				}
				else {
					cout << "Employee was found\n";
					//retrieves object
					EmployeeInfo object = emp_tree.searchNodeObject(EmployeeInfo(search, ""));
					cout << object << endl;
				}
			}
			break;
		default:
			break;
		}
	}


    return 0;
}

