// Object oriented system.cpp 


#include <iostream>
#include "pch.h"
#include "node.h"
#include "Dice.h"
#include "BinarySearchTree.h"
#include "N_aryTree.h"
#include <list>
#include <string>
#include <vector>
#include <ctime>
using namespace std;


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

void ToBinarySearchTree(BinarySearchTree<Dice>* my, Dice arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		my->Input(my->GetTree(), i, arr[i], 0);
	}
}

void ToBinaryTree(BinaryTree<Dice>* my, Dice arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		my->Input(my->GetTree(), i, arr[i]);
	}
}

void ToN_aryTree(N_aryTree<Dice>* my, Dice arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		my->AddLast(my->GetList(), i, arr[i]);
	}
}


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

void Amounts(Dice arr[], int n)
{
	int amount = 0;
	for (int i = 0; i < n; i++)
		amount += arr[i].GetBrinksNum();
	for (int i = n; i <= amount; i++)
		cout << i << " ";
}

void Menu(int n, Dice arr[], BinarySearchTree<Dice> BST, BinaryTree<Dice> BT, N_aryTree<Dice> NT)
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
		//	ToBinarySearchTree(&BST, arr, n);
			cout << "Menu\n1)Print binary search tree\n2)Recursive search\n3)Non-recursive search\n4)Find minimal\n5)Delete node\n";
			int choice1;
			cin >> choice1;
			switch (choice1)
			{
			case 1:
			{
				system("cls");
				cout << "Binary search tree:" << endl;
				BST.PrintTree<Dice>(BST.GetTree(), 0);
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
				Dice D;
				D.SetMS(a);
				res = BST.SearchRecursion<Dice>(BST.GetTree(), D, 1);
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
				Dice D;
				D.SetMS(a);
				res = BST.SearchLoop<Dice>(BST.GetTree(), D);
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
				Dice D;
				D.SetMS(a);
				BST.DeleteNode<Dice>(BST.GetTree(), D);
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
				BT.PrintTree<Dice>(BT.GetTree(), 0);
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
				Dice D;
				D.SetMS(a);
				res = BT.Search<Dice>(BT.GetTree(), D, 1);
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
				Dice D;
				D.SetMS(a);
				BT.SetTree(BT.deletion<Dice>(BT.GetTree(), D));
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
		//	if (!NT.GetList())
		//		ToN_aryTree(&NT, arr, n);
			cout << "Menu\n1)Print n-ary tree\n2)Search\n3)Delete node\n";
			int choise4;
			cin >> choise4;
			switch (choise4)
			{
			case 1:
			{
				system("cls");
				cout << "N-ary tree:" << endl;
				NT.Output<Dice>();
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
				Dice D;
				D.SetMS(a);
				NT.Search<Dice>(NT.GetList(), D);
				cout << "0)Back\n";
				cin >> choice;
				if (choice == 0)
					break;
				else break;
			}
			case 3:
			{
				system("cls");
				Dice D;
				double a;
				cout << "Input value to delete: ";
				cin >> a;
				D.SetMS(a);
				NT.Delete<Dice>(NT.GetList(), D);
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
	cout << "Enter quantity of dice: ";
	cin >> n;

	Dice A2, A4, A6, A8, A10, A12, A20;

	int mas[7] = { 2, 4, 6, 8, 10, 12, 20 };
	A2.SetBrinksNum(2); A4.SetBrinksNum(4); A6.SetBrinksNum(6); A8.SetBrinksNum(8); A10.SetBrinksNum(10);
	A12.SetBrinksNum(12); A20.SetBrinksNum(20);

	Dice*cybic = new Dice[n];
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 7;
		cybic[i].SetBrinksNum(mas[a]);
	}
	for (int i = 0; i < n; i++)
		cybic[i].GenerateProb();
	cout << "Generating probabilities..." << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "A" << cybic[i].GetBrinksNum() << ":" << endl;
		cybic[i].PrintProb();
	}
	cout << endl << "Counting expected value..." << endl;
	for (int i = 0; i < n; i++)
		cybic[i].CountMS();
	for (int i = 0; i < n; i++) cout << "A" << cybic[i].GetBrinksNum() << ": " << cybic[i].CountMS() << endl;
	cout << endl << "All posible amounts:" << endl;
	Amounts(cybic, n);
	cout << endl;
	system("pause");
	BinarySearchTree<Dice> myBST;
	BinaryTree<Dice> myBT;
	N_aryTree<Dice> myNT;
	ToBinarySearchTree(&myBST, cybic, n);
	ToBinaryTree(&myBT, cybic, n);
	ToN_aryTree(&myNT, cybic, n);
	Menu(n, cybic, myBST, myBT, myNT);

}
