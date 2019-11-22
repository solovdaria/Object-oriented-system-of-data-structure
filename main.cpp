// Object oriented system.cpp 
#include <iostream>
#include "pch.h"
#include "node.h"
#include "Dice.h"
#include "SetOfDice.h"
#include "BinarySearchTree.h"
#include "N_aryTree.h"
#include <list>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

/*!
\brief Demonstration of working with string

Shows strings in all trees, deletes node and finds node
\param str String
\param n Number of string
\param r1, r2, r3 Levels int the trees
*/
void StringDemonstration(BinarySearchTree<string> bst, BinaryTree<string> bt, N_aryTree<string> nt)
{
	N_aryTree<string> nt_new;
	string str;
	int n;
	cout << "Enter number of strings: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter string: ";
		cin >> str;
		bst.Input(bst.GetTree(), i, str, 0);
		bt.Input(bt.GetTree(), i, str);
		nt.AddLast(nt.GetList(), i, str);
	}
	if (n > 1)
		nt.Sort(nt, nt_new, n);
	else nt_new = nt;
	cout << "---------------Binary search tree----------------" << endl;
	bst.PrintTree(bst.GetTree(), 0);
	cout << endl << "---------------Binary tree-----------------" << endl;
	bt.PrintTree<string>(bt.GetTree(), 0);
	cout << endl << "-------------N-ary tree in the list form-----------------" << endl;
	nt_new.Output<string>();
	cout << endl << "----Find object------" << endl;
	string f;
	cout << "Enter int to find: ";
	cin >> f;
	int r1, r2, r3;
	r1 = bst.SearchRecursion(bst.GetTree(), f, 1);
	r2 = bt.Search(bt.GetTree(), f, 1);
	cout << "Level in binary search tree: " << r1 << endl << "Level in binary tree: " << r2 << endl;
	cout << "Level in n-ary tree: ";
	nt_new.Search(nt_new.GetList(), f);
	cout << endl << "----Deleting object------" << endl;
	string g;
	cout << "Enter string to delete: ";
	cin >> g;
	bst.DeleteNode(bst.GetTree(), g);
	bt.SetTree(bt.deletion(bt.GetTree(), g));
	nt_new.Delete(nt_new.GetList(), g);
	cout << "---------------New binary search tree----------------" << endl;
	bst.PrintTree(bst.GetTree(), 0);
	cout << endl << "---------------New binary tree-----------------" << endl;
	bt.PrintTree<string>(bt.GetTree(), 0);
	cout << endl << "---------------New n-ary tree in the list form-----------------" << endl;
	nt_new.Output<string>();
}

/*!
\brief Demonstration of working with integers

Shows integers in all trees, deletes node and finds node
\param a Integer
\param n Number of integers
\param r1, r2, r3 Levels in the trees
*/
void IntDemonstration(BinarySearchTree<int> bst, BinaryTree<int> bt, N_aryTree<int> nt)
{
	N_aryTree<int> nt_new;
	int a;
	int n;
	cout << "Enter number of ints: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a = 1 + rand() % 100;
		bst.Input(bst.GetTree(), i, a, 0);
		bt.Input(bt.GetTree(), i, a);
		nt.AddLast(nt.GetList(), i, a);
	}
	if (n > 1)
		nt.Sort(nt, nt_new, n);
	else nt_new = nt;
	cout << "---------------Binary search tree----------------" << endl;
	bst.PrintTree(bst.GetTree(), 0);
	cout << endl << "---------------Binary tree-----------------" << endl;
	bt.PrintTree<int>(bt.GetTree(), 0);
	cout << endl << "---------------N-ary tree in the list form-----------------" << endl;
	nt_new.Output<int>();
	cout << endl << "----Find object------" << endl;
	int f;
	cout << "Enter int to find: ";
	cin >> f;
	int r1, r2, r3;
	r1 = bst.SearchLoop(bst.GetTree(), f);
	r2 = bt.Search(bt.GetTree(), f, 1);
	cout << "Level in binary search tree: " << r1 << endl << "Level in binary tree: " << r2 << endl;
	cout << "Level in n-ary tree: ";
	nt_new.Search(nt_new.GetList(), f);
	cout << endl << "----Deleting object------" << endl;
	int g;
	cout << "Enter int to delete: ";
	cin >> g;
	bst.DeleteNode(bst.GetTree(), g);
	bt.SetTree(bt.deletion(bt.GetTree(), g));
	nt_new.Delete(nt_new.GetList(), g);
	cout << "---------------New binary search tree----------------" << endl;
	bst.PrintTree(bst.GetTree(), 0);
	cout << endl << "---------------New binary tree-----------------" << endl;
	bt.PrintTree<int>(bt.GetTree(), 0);
	cout << endl << "---------------New n-ary tree in the list form-----------------" << endl;
	nt_new.Output<int>();

}

/*!
\brief Demonstration of working with doubles

Shows doubles in all trees, deletes node and finds node
\param a Double
\param n Number of doubles
\param r1, r2, r3 Levels in the trees
*/
void DoubleDemonstration(BinarySearchTree<double> bst, BinaryTree<double> bt, N_aryTree<double> nt)
{
	N_aryTree<double> nt_new;
	double a;
	int n;
	cout << "Enter number of doubles: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a = (1 + rand() % 100)*0.01;
		bst.Input(bst.GetTree(), i, a, 0);
		bt.Input(bt.GetTree(), i, a);
		nt.AddLast(nt.GetList(), i, a);
	}
	if (n > 1)
		nt.Sort(nt, nt_new, n);
	else nt_new = nt;
	cout << "---------------Binary search tree----------------" << endl;
	bst.PrintTree(bst.GetTree(), 0);
	cout << endl << "--------------Binary tree-----------------" << endl;
	bt.PrintTree<double>(bt.GetTree(), 0);
	cout << endl << "--------------N-ary tree in the list form-----------------" << endl;
	nt_new.Output<double>();
	cout << endl << "----Find object------" << endl;
	double f;
	cout << "Enter double to find: ";
	cin >> f;
	int r1, r2, r3;
	r1 = bst.SearchLoop(bst.GetTree(), f);
	r2 = bt.Search(bt.GetTree(), f, 1);
	cout << "Level in binary search tree: " << r1 << endl << "Level in binary tree: " << r2 << endl;
	cout << "Level in n-ary tree: ";
	nt_new.Search(nt_new.GetList(), f);
	cout << endl << "----Deleting object------" << endl;
	double g;
	cout << "Enter int to delete: ";
	cin >> g;
	bst.DeleteNode(bst.GetTree(), g);
	bt.SetTree(bt.deletion(bt.GetTree(), g));
	nt_new.Delete(nt_new.GetList(), g);
	cout << "---------------New binary search tree----------------" << endl;
	bst.PrintTree(bst.GetTree(), 0);
	cout << endl << "---------------New binary tree-----------------" << endl;
	bt.PrintTree<double>(bt.GetTree(), 0);
	cout << endl << "---------------New n-ary tree in the list form-----------------" << endl;
	nt_new.Output<double>();
}

/*!
\brief Demonstration of working with vectors

Shows vectors in all trees, deletes node and finds node
\param vec Vector
\param n Number of vectors
\param r1, r2, r3 Levels in the trees
*/
void VectorDemonstration(BinarySearchTree<vector<int>> bst, BinaryTree<vector<int>> bt, N_aryTree<vector<int>> nt)
{
	N_aryTree<vector<int>> nt_new;
	int n;
	cout << "Enter number of vectors: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int> vec;
		for (int j = 0; j < 3; j++)
			vec.push_back(1 + rand() % 100);
		bst.Input<vector<int>>(bst.GetTree(), i, vec, 0);
		bt.Input<vector<int>>(bt.GetTree(), i, vec);
		nt.AddLast(nt.GetList(), i, vec);
	}
	if (n > 1)
		nt.Sort(nt, nt_new, n);
	else nt_new = nt;	cout << "---------------Binary search tree----------------" << endl;
	bst.PrintTree<vector<int>>(bst.GetTree(), 0);
	cout << endl << "--------------Binary tree-----------------" << endl;
	bt.PrintTree<vector<int>>(bt.GetTree(), 0);
	cout << endl << "--------------N-ary tree in the list form-----------------" << endl;
	nt_new.Output<vector<int>>();
	vector<int> v;
	cout << "----Find object------" << endl;
	for (int j = 0; j < 3; j++)
	{
		int k;
		cout << "Input element " << j + 1 << " : ";
		cin >> k;
		v.push_back(k);
	}
	cout << "Level int the binary search tree: " << bst.SearchRecursion<vector<int>>(bst.GetTree(), v, 1) << endl;
	cout << "Level int the binary tree: " << bt.Search<vector<int>>(bt.GetTree(), v, 1) << endl;
	cout << "Level in the n-ary tree : ";
	nt_new.Search(nt_new.GetList(), v);
	cout << endl;
	cout << "----Deleting object------" << endl;
	vector<int> v_delete;
	for (int j = 0; j < 3; j++)
	{
		int k;
		cout << "Input element " << j + 1 << " : ";
		cin >> k;
		v_delete.push_back(k);
	}
	bst.DeleteNode<vector<int>>(bst.GetTree(), v_delete);
	bt.deletion<vector<int>>(bt.GetTree(), v_delete);
	nt_new.Delete<vector<int>>(nt_new.GetList(), v_delete);

	cout << "---------------Binary search tree----------------" << endl;
	bst.PrintTree<vector<int>>(bst.GetTree(), 0);
	cout << endl << "--------------Binary tree-----------------" << endl;
	bt.PrintTree<vector<int>>(bt.GetTree(), 0);
	cout << endl << "--------------N-ary tree in the list form-----------------" << endl;
	nt_new.Output<vector<int>>();

}

/*!
Input last array to the BST 

\param my Is a variable of class BinarySearchTree
\param arr Array of elements of class Dice
\paran n Size of array
\param i Index
*/
void ToBinarySearchTree(BinarySearchTree<SetOfDice>* my, SetOfDice arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		my->Input(my->GetTree(), i, arr[i], 0);
	}
}

/*!
Input last array to the BT 

\param my Is a variable of class BinaryTree
\param arr Array of elements of class Dice
\paran n Size of array
\param i Index
*/
void ToBinaryTree(BinaryTree<SetOfDice>* my, SetOfDice arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		my->Input(my->GetTree(), i, arr[i]);
	}
}

/*!
Input last array to the N-ary tree

\param my Is a variable of class N_aryTree
\param arr Array of elements of class Dice
\paran n Size of array
\param i Index
*/
void ToN_aryTree(N_aryTree<SetOfDice>* my, SetOfDice arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		my->AddLast(my->GetList(), i, arr[i]);
	}
}


/*!
\brief Menu

MENU:
1)Enter types
  1)Integer
  2)Double
  3)Vector
  4)String
2)Binary search tree
  1)Print binary search tree
  2)Recursive search
  3)Non-recursive search
  4)Find minimal
  5)Delete node
3)Binary tree
  1)Print binary tree
  2)Search
  3)Delete node
4)N-ary tree
  1)Print n-ary tree
  2)Search
  3)Delete node
\param n Quantity of dice
\param arr Array of elments of class Dice
\param BST Binary search tree
*/
void Menu(int n, SetOfDice arr[], BinarySearchTree<SetOfDice> BST, BinaryTree<SetOfDice> BT, N_aryTree<SetOfDice> NT)
{
	do {
		system("cls");
		cout << "MENU:\n1)Enter types\n2)Binary search tree\n3)Binary tree\n4)N-ary tree\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "1)Integer\n2)Double\n3)Vector\n4)String\n";
			int cho;
			cin >> cho;
			switch (cho)
			{
			case 1:
			{
				system("cls");
				cout << "Integer:" << endl;
				BinarySearchTree<int> BSTint;
				BinaryTree<int> BTint;
				N_aryTree<int> NTint;
				IntDemonstration(BSTint, BTint, NTint);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Double:" << endl;
				BinarySearchTree<double> BSTd;
				BinaryTree<double> BTd;
				N_aryTree<double> NTd;
				DoubleDemonstration(BSTd, BTd, NTd);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			}
			case 3:
			{
				system("cls");
				cout << "Vector:" << endl;
				BinarySearchTree<vector<int>> BSTvec;
				BinaryTree<vector<int>> BTvec;
				N_aryTree<vector<int>> NTvec;
				VectorDemonstration(BSTvec, BTvec, NTvec);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			}
			case 4:
			{
				system("cls");
				cout << "String:" << endl;
				BinarySearchTree<string> BSTstr;
				BinaryTree<string> BTstr;
				N_aryTree<string> NTstr;
				StringDemonstration(BSTstr, BTstr, NTstr);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2:
			system("cls");
			cout << "Menu\n1)Print binary search tree\n2)Recursive search\n3)Non-recursive search\n4)Find minimal\n5)Delete node\n";
			int choice1;
			cin >> choice1;
			switch (choice1)
			{
			case 1:
			{
				system("cls");
				cout << "Binary search tree:" << endl;
				BST.PrintTree<SetOfDice>(BST.GetTree(), 0);
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				double a;
				int res;
				cout << "Enter value to search: ";
				cin >> a;
				SetOfDice D;
				D.SetAmountMS(a);
				res = BST.SearchRecursion<SetOfDice>(BST.GetTree(), D, 1);
				cout << res << endl;
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
			}
			case 3:
			{
				system("cls");
				double a;
				int res;
				cout << "Enter value to search: ";
				cin >> a;
				SetOfDice D;
				D.SetAmountMS(a);
				res = BST.SearchLoop<SetOfDice>(BST.GetTree(), D);
				cout << res << endl;
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else break;
			}
			case 4:
			{
				system("cls");
				cout << BST.MinOutput(BST.GetTree()) << endl;
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			}
			case 5:
			{
				system("cls");
				double a;
				cout << "Enter value to delete: ";
				cin >> a;
				SetOfDice D;
				D.SetAmountMS(a);
				BST.DeleteNode<SetOfDice>(BST.GetTree(), D);
				cout << "\n0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else
					system("cls");
				break;
			}
			default:
				break;
			}
			break;
		case 3:
		{
			system("cls");
			cout << "Menu\n1)Print binary tree\n2)Search\n3)Delete node\n";
			int choice2;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
			{
				system("cls");
				cout << "Binary tree:" << endl << "--------Tree output-------" << endl;
				BT.PrintTree<SetOfDice>(BT.GetTree(), 0);
				cout << endl << "---------Inorder output----------" << endl;
				BT.PrintInorder(BT.GetTree());
				cout << endl << "---------Preorder output----------" << endl;
				BT.PrintPreorder(BT.GetTree());
				cout << endl << "---------Postorder output----------" << endl;
				BT.PrintPostorder(BT.GetTree());
				cout << endl;
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else break;
			}
			case 2:
			{
				system("cls");
				int res;
				double a;
				cout << "Input value to find: ";
				cin >> a;
				SetOfDice D;
				D.SetAmountMS(a);
				res = BT.Search<SetOfDice>(BT.GetTree(), D, 1);
				cout << endl << res << endl;
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else break;
			}
			case 3:
			{
				system("cls");
				double a;
				cout << "Input value to delete: ";
				cin >> a;
				SetOfDice D;
				D.SetAmountMS(a);
				BT.SetTree(BT.deletion<SetOfDice>(BT.GetTree(), D));
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else break;
			}
			default:
				break;
			}
		case 4:
		{
			system("cls");
			cout << "Menu\n1)Print n-ary tree\n2)Search\n3)Delete node\n";
			int choise4;
			cin >> choise4;
			switch (choise4)
			{
			case 1:
			{
				system("cls");
				cout << "N-ary tree:" << endl;
				NT.Output<SetOfDice>();
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else break;
			}
			case 2:
			{
				system("cls");
				double a;
				cout << "Input value to find: ";
				cin >> a;
				SetOfDice D;
				D.SetAmountMS(a);
				NT.Search<SetOfDice>(NT.GetList(), D);
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else break;
			}
			case 3:
			{
				system("cls");
				SetOfDice D;
				double a;
				cout << "Input value to delete: ";
				cin >> a;
				D.SetAmountMS(a);
				NT.Delete<SetOfDice>(NT.GetList(), D);
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else break;
			}
			default:
				break;
			}
			break;
		}
		}
		}
	} while (1);
}

int main()
{
	int n;
	cout << "Enter quantity of sets: ";
	cin >> n;
	SetOfDice*cybic=new SetOfDice[n];
	for (int i = 0; i < n; i++)
	{
		int a = 1 + rand() % 10;
		cybic[i].SetNumOfDice(a);
	}
	
	cout << endl;
	system("pause");
	BinarySearchTree<SetOfDice> myBST;
	BinaryTree<SetOfDice> myBT;
	N_aryTree<SetOfDice> myNT;
	ToBinarySearchTree(&myBST, cybic, n);
	ToBinaryTree(&myBT, cybic, n);
	ToN_aryTree(&myNT, cybic, n);
	Menu(n, cybic, myBST, myBT, myNT);

}
