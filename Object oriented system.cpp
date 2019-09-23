// Object oriented system.cpp 

/*Лабораторна робота №1

Реалізувати у вигляді об’єктно-орієнтованої системи структури даних та
алгоритми з інших предметів (Список 1). Реалізовані структури даних мають
підтримувати роботу з даними різних типів. Продемонструвати роботу
системи на примітивних типах (int, double), бібліотечних типах (string,
vector), а також реалізованих класах (Список 2). Для всіх структур даних
реалізувати методи отримання текстового подання (наприклад, з метою
виводу на екран), а також генерації відповідних структур даних.
6. (**) Дерева з довільною кількістю дітей (на основі зв’язного списку та
бібліотечних засобів для списку), бінарні дерева, дерева бінарного
пошуку. Додавання елементів, видалення елементів (за батьківським
вузлом та індексом, за значенням), пошук за значенням.
a. +* за різні варіанти обходу дерев, пошук за шляхом в дереві;
b. +* за підтримку різних механізмів видалення, що якось
обробляють елементи з видалених під-дерев.
6. (***) «Нечесні» гральні кості з кількістю граней N=2, 4, 6, 8, 10, 12, 20.
Грані помічено числами від 1 до N. Для кожної грані задається
ймовірність випадіння (число від 0 до 1). Обчислення всіх можливих
сум для заданого набору костей(набір може містити довільну кількість
костей з однаковими чи різними гранями та однаковими чи різними
ймовірностями) та ймовірність випадіння кожної з них.
a. +* порівняння двох наборів за очікуваною сумою значень граней.*/

#include "pch.h"
#include <iostream>
using namespace std;

template <typename type, typename type1>
class MyTree
{
private:
	class node
	{
	public:
		node()
		{
			this->right = nullptr;
			this->left = nullptr;
		}
		type index;
		type1 info;
		node*right;
		node*left;
	};
	node*tree;
public:
	node*GetTree()
	{
		return tree;
	}

	MyTree()
	{
		tree = nullptr;
	}

	MyTree(const MyTree &copy)
	{
		this->tree = copy.tree;
	}

	void Input(node*curr,type i, type1 a)
	{
		if (tree == nullptr)
		{
			tree = new node();
			tree->index = i;
			tree->info = a;
			tree->left = tree->right = nullptr;
		}

		if (curr == nullptr)
		{
			curr = new node();
			curr->index = i;
			curr->info = a;
			curr->left = curr->right = nullptr;
		}
		if (a < curr->info)
			if (curr->left != nullptr) Input(curr->left, i, a);
			else
			{
				curr->left = new node();
				curr->left->left = curr->left->right = nullptr;
				curr->left->index = i;
				curr->left->info = a;
			}
		if (a > curr->info)
			if (curr->right != nullptr) Input(curr->right, i, a);
			else
			{
				curr->right = new node();
				curr->right->left = curr->right->right = nullptr;
				curr->right->index = i;
				curr->right->info = a;
			}
	}

	void Output(node*curr)
	{
		if (curr != nullptr)
		{
			Output(curr->left);
			cout <<"("<< curr->index+1<<" : "<< curr->info<<")"<<endl;
			Output(curr->right);
		}
	}

	void PrintTree(node*curr, int level)
	{
		if (curr)
		{
			PrintTree(curr->right, level + 1);
			for (int i = 0; i < level; i++) cout << "         ";
			cout << "(" << curr->index + 2 << ":" << curr->info << ")" << endl;
			PrintTree(curr->left, level + 1);
		}
	}

	int Search(node*curr, type1 v, int counter=1) //поиск значения
	{
		if (curr == NULL) return -1;
		if (curr->info == v) return counter;

		if (v <= curr->info)
		{
			if (curr->left != NULL)
				return Search(curr->left, v, ++counter);
			else return -1;
		}
		else
		{
			if (v > curr->info)
			{
				if (curr->right != NULL)
					return Search(curr->right, v, ++counter);
				else return -1;
			}
		}
	}

	node*Min(node*curr)
	{
		node*c = curr;
		while (c && c->left != nullptr) c = c->left;
		return c;
	}

	int MinOutput(node*curr)
	{
		node*c = curr;
		while (c && c->left != nullptr) c = c->left;
		return c->index+2;
	}

	node*DeleteNode(node*curr, type v)
	{
		if (curr == nullptr) return curr;
		if (v < curr->info) curr->left = DeleteNode(curr->left, v);
		else if (v > curr->info) curr->right = DeleteNode(curr->right, v);
		else
		{
			if (curr->left == nullptr)
			{
				node*tmp = curr->right;
				free(curr);
				return tmp;
			}
			else if (curr->right == nullptr)
			{
				node*tmp = curr->left;
				free(curr);
				return tmp;
			}
			node*tmp = Min(curr->right);
			curr->info = tmp->info;
			curr->index = tmp->index;
			curr->right = DeleteNode(curr->right, tmp->info);
		}
		return curr;
	}
};

class Dice
{
private:
	int maxSum; 
	int size;
	int sum;
	double*arr1;
	double*arr2;
	double*arr_sum;
public:
	Dice()
	{
		Dice*cybic;
	}

	int AllSum(int N1, int N2)
	{
		maxSum = N1 + N2;
		return maxSum;
	}
	
	void SumArr(int size1, int size2)
	{
		size = size1 + size2 - 1;
		arr_sum = new double[size];
		for (sum = 0; sum < size; sum++) arr_sum[sum] = 0;
		for (sum = 0; sum < size; sum++)
		{
			for (int i = 0; i <= sum && i < size1; i++)
			{
				for (int j = 0; j <= sum && j < size2; j++)
				{
					if (sum == i + j) arr_sum[sum] += arr1[i] * arr2[j];
				}
			}
		}
		for (sum = 0; sum < size; sum++)
		{
			cout << "Probability of summ " << sum + 2 << " = " << arr_sum[sum] << endl;
		}
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				if (i == j)
				{
					if (arr1[i] > arr2[j]) cout << "Probability of " << i + 1 << " on first > than probability of " << j+1<<" on second"<<endl;
					else if (arr1[i] < arr2[j]) cout << "Probability of " << i + 1 << " on first < than probability of " << j+1 << " on second" <<endl;
					else cout << "Probability of " << i + 1 << " on first = probability of " << j+1 << " on second" <<endl;
				}
			}
		}
	}

	void Arrays(int N1, int N2)
	{
		double summa = 0;
		arr1 = new double[N1];
		arr2 = new double[N2];
		for (int i = 0; i < N1 - 1; i++)
		{
			cout << "Enter probability of " << i + 1 << ": ";
			cin >> arr1[i];
			summa += arr1[i];
		}
		arr1[N1 - 1] = 1 - summa;
		cout << "Probability of " << N1 << " = " << arr1[N1 - 1] << endl;
		summa = 0;
		for (int j = 0; j < N2 - 1; j++)
		{
			cout << "Enter probability of " << j + 1 << ": ";
			cin >> arr2[j];
			summa += arr2[j];
		}
		arr2[N2 - 1] = 1 - summa;
		cout << "Probability of " << N2 << " = " << arr2[N2 - 1] << endl;
		SumArr(N1, N2);
	}

	void SumToTree(MyTree<int, double>* my, Dice cybic, int N1, int N2)
	{
		for (int k = 0; k < N1+N2-1; k++)
		{
			my->Input(my->GetTree(), k, cybic.arr_sum[k]);
		}
	}
};

void Menu(MyTree<int, double> my, Dice cybic)
{
	int N1, N2;
	cout << "Input max number on dice:" << endl;
	cout << "Enter N1: ";
	cin >> N1;
	cout << endl;
	cout << "Enter N2: ";
	cin >> N2;
	cout << endl;
	while (true)
	{
		system("cls");
		cout << "MENU:\n1)Enter tree, get probabilities of all amounts and show the tree\n2)Show all possible amounts\n3)Delete node\n4)Show minimum value of the tree\n5)Find value\n6)Show the tree\n";
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
			my.PrintTree(my.GetTree(), level=0);
			cout << "0)Back\n";
			cin >> choice;
			if (choice == 2)
				break;
			else
				system("cls");
			break;
		case 3:
			system("cls");
			int v;
			cout << "Enter value (index) to delete: ";
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
			result=my.Search(my.GetTree(), a, c=1);
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
			my.PrintTree(my.GetTree(), l=0);
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

