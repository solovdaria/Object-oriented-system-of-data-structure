// Object oriented system.cpp 


#include <iostream>
#include "pch.h"
#include "Dice.h"
#include "MyTree.h"

/*!
\brief Menu provides easy and fast work

Includes such opportunities as:
1. Enter tree, get probabilities of all amounts and show the tree in the tree form
2. Show all possible amounts
3. Delete node
4. Show minimal value of the tree
5. Find value non-recursive
6. Show the tree in the tree form
\param my Is a variable of class MyTree
\param cybic Is a variable of class Dice
\paran N1 Maximal value on the first dice
\param N2 Maximal value on the second dice
\throw system("pause") In case N1 or N2 > 20 or <2
*/
void Menu(MyTree<int, double> my, Dice cybic)
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
		cout << "MENU:\n1)Enter tree, get probabilities of all amounts and show the tree\n2)Show all possible amounts\n3)Delete node\n4)Show minimal value of the tree\n5)Find value\n6)Show the tree\n";
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
			cybic.SumToTree(&my, cybic, N1, N2);
			my.PrintTree(my.GetTree(), level = 0);
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
			my.DeleteNode(my.GetTree(), v);
			cout << "\n0)Back\n";
			cin >> choice;
			if (choice == 0)
				break;
			else
				system("cls");
			break;
		case 4:
			system("cls");
			cout << my.MinOutput(my.GetTree()) << endl;
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
			result = my.SearchLoop(my.GetTree(), a, c = 1);
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
			my.PrintTree(my.GetTree(), l = 0);
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
	}
}

int main()
{
	MyTree<int, double> my;
	Dice cybic;
	Menu(my, cybic);
	system("pause");
}
