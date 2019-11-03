// Object oriented system.cpp 


#include <iostream>
#include "pch.h"
#include "node.h"
#include "Dice.h"
#include "BinarySearchTree.h"
#include "N_aryTree.h"
#include <list>
using namespace std;

/*!
\brief Menu provides easy and fast work

Includes such opportunities as:
1. Binary search tree
    1. Enter tree, get probabilities of all amounts and show the tree in the tree form
    2. Show all possible amounts
    3. Delete node
    4. Show minimal value of the tree
    5. Find value non-recursive
    6. Show the tree in the tree form
2. Binary tree
    1. Enter binary tree get probabilities of all amounts and show the tree
    2. Show all possible amounts
    3. Delete binary tree node
    4. Find value in the binary tree
    5. Show the binary tree (preorder, postorder, inorder)\n";
3. N-ary tree
    1. Enter binary tree get probabilities of all amounts and show the tree
    2. Show all possible amounts
    3. Delete N-ary tree node
    4. Find value in the N-ary tree
    5. Show the N-ary tree\n";
\param myBST Is a variable of class BinarySearchTree
\param myBT Is a variable of class BinaryTree
\param myNT Is a variable of class N_aryTree
\param cybic Is a variable of class Dice
\paran N1 Maximal value on the first dice
\param N2 Maximal value on the second dice
\throw system("pause") In case N1 or N2 > 20 or <2
*/
void Menu(BinarySearchTree<int, double> myBST, BinaryTree<int, double> myBT, N_aryTree<int, double> myNT, Dice cybic)
{
	int N1, N2;
	cout << "Input max number on dice:" << endl;
	cout << "Enter N1: ";
	cin >> N1;
	if ((N1 > 20) || (N1 < 2))
	{
		cout << "Max number must be  bigger than 1 and smaller than 21" << endl;
		system("pause");
	}
	cout << endl;
	cout << "Enter N2: ";
	cin >> N2;
	if ((N2 > 20) || (N2 < 2))
	{
		cout << "Max number must be  bigger than 1 and smaller than 21" << endl;
		system("pause");
	}
	cout << endl;
	while (true)
	{
		system("cls");
		cout << "MENU:\n1)Binary search tree\n2)Binary tree\n3)Tree\n";
		int choice1;
		cin >> choice1;
		switch (choice1)
		{
		case 1:
			system("cls");
			cout << "MENU:\n1)Enter binary search tree, get probabilities of all amounts and show the tree\n2)Show all possible amounts\n3)Delete binary search tree node\n4)Show minimal value of the binary search tree\n5)Find value int the binary search tree\n6)Show the binary search tree\n";
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 2:
				system("cls");
				while (true)
				{
					for (int i = 2; i < cybic.AllSum(N1, N2) + 1; i++)
						cout << i << endl;
					int choice;
					cout << "0)Back\n";
					cin >> choice;
					if (choice == 0)
						break;
					else
						system("cls");
				}
				system("cls");
				break;
			case 1:
				system("cls");
				int level;
				cybic.Arrays(N1, N2);
				cybic.SumToBinarySearchTree(&myBST, cybic, N1, N2);
				myBST.PrintTree(myBST.GetTree(), level = 0);
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 2)
					break;
				else
					system("cls");
				break;
			case 3:
				system("cls");
				double v;
				cout << "Enter value (probability) to delete: ";
				cin >> v;
				myBST.DeleteNode(myBST.GetTree(), v);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			case 4:
				system("cls");
				cout << myBST.MinOutput(myBST.GetTree()) << endl;
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			case 5:
				system("cls");
				double a; int result, c;
				cout << "Enter value (probability) to find: ";
				cin >> a;
				result = myBST.SearchLoop(myBST.GetTree(), a, c = 1);
				cout << result;
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			case 6:
				system("cls");
				int l;
				myBST.PrintTree(myBST.GetTree(), l = 0);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			default:
				system("cls");
				break;
			}
		case 2:
			system("cls");
			cout << "1)Enter binary tree get probabilities of all amounts and show the tree\n2)Show all possible amounts\n3)Delete binary tree node\n4)Find value in the binary tree\n5)Show the binary tree (preorder, postorder, inorder)\n"; 
			int choice2;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				system("cls");
				cybic.Arrays(N1, N2);
				cybic.SumToBinaryTree(&myBT, cybic, N1, N2);
				myBT.PrintTree(myBT.GetTree(), 0);
				cout << endl << "0)Back\n";
				cin >> choice;
				if (choice == 2)
					break;
				else
					system("cls");
				break;
			case 2:
				system("cls");
				while (true)
				{
					for (int i = 2; i < cybic.AllSum(N1, N2) + 1; i++)
						cout << i << endl;
					int choice;
					cout << "0)Back\n";
					cin >> choice;
					if (choice == 0)
						break;
					else
						system("cls");
				}
				system("cls");
				break;
			case 3:
				system("cls");
				double v;
				cout << "Enter value (probability) to delete: ";
				cin >> v;
				myBT.DeleteNode(myBT.GetTree(), v);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			case 4:
				system("cls");
				double a; int result, c;
				cout << "Enter value (probability) to find: ";
				cin >> a;
				result = myBT.Search(myBT.GetTree(), a, c = 1);
				cout << result;
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			case 5:
				system("cls");
				cout << "Inorder print: " << endl;
				myBT.PrintInorder(myBT.GetTree());
				cout << endl<<"Postorder print: " << endl;
				myBT.PrintPostorder(myBT.GetTree());
				cout << endl<<"Inorder print: " << endl;
				myBT.PrintInorder(myBT.GetTree());
				cout << endl << endl;
				myBT.PrintTree(myBT.GetTree(), 0);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			default:
				system("cls");
				break;
			}
		case 3:
			system("cls");
			cout << "1)Enter binary tree get probabilities of all amounts and show the tree\n2)Show all possible amounts\n3)Delete N-ary tree node\n4)Find value in the N-ary tree\n5)Show the N-ary tree\n";
			int choice4;
			cin >> choice4;
			switch (choice4)
			{
			case 1:
				system("cls");
				cybic.Arrays(N1, N2);
				cybic.SumToN_aryTree(&myNT, cybic, N1, N2);
				myNT.Output();
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			default:
				break;
			case 2:
				system("cls");
				while (true)
				{
					for (int i = 2; i < cybic.AllSum(N1, N2) + 1; i++)
						cout << i << endl;
					int choice;
					cout << "0)Back\n";
					cin >> choice;
					if (choice == 0)
						break;
					else
						system("cls");
				}
				system("cls");
				break;
			case 3:
				system("cls");
				double v;
				cout << "Enter value (probability) to delete: ";
				cin >> v;
				myNT.Delete(v);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			case 4:
				system("cls");
				double a; 
				cout << "Enter value (probability) to find: ";
				cin >> a;
				myNT.Search(a);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			case 5:
				system("cls");
				N_aryTree<int, double> t;
				myNT.sort(myNT, t);
				t.Output();
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			}
		}
	}
}

int main()
{
	BinarySearchTree<int, double> myBST;
	BinaryTree<int, double> myBT;
	N_aryTree<int, double> myNT;
	Dice cybic;
	Menu(myBST, myBT, myNT, cybic);
	system("pause");
}
