// Object oriented system.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
//		this->info = copy.info;
		//this->index = copy.index;
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

	int Search(node*curr, type v, int counter = 1) //поиск значения
	{
		if (curr == nullptr) return -1;
		if (curr->index == v) return counter;

		if (v <= curr->index)
		{
			if (curr->left != nullptr)
				return Search(curr->left, v, ++counter);
			else return -1;
		}
		else
		{
			if (v > curr->index)
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

	node*DeleteNode(node*curr, type1 v)
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
			curr->right = DeleteNode(curr->right, tmp->info);
		}
		return curr;
	}

	//node* my1;
};

class Dice
{
private:
	int N; //максимальное значение на костях
	int quantity; //кол-во костей
	double prob; //вероятность для грани
	int sum; //возможные суммы
	double prob_sum; //вероятность суммы
public:
	Dice()
	{
		Dice*cybic;
	}

	int AllSum(int N1, int N2)
	{
		int maxSum = N1 + N2;
		return maxSum;
	}

	/*bool ErrorIndex(int k, int u)
	{
		bool tmp=false;
		for (u = 0; u < k; u++)
		{
			if (u = k) tmp = true;
		}
		return tmp;
	}*/

	double*arr_sum;
	void Arrays(int N1, int N2)
	{
		double summa = 0;
		double*arr1 = new double[N1];
		double*arr2 = new double[N2];
		arr_sum = new double[N1+N2-1];
		for (int i = 0; i < N1-1; i++)
		{
			cout << "Enter probability of " << i+1 << ": ";
			cin >> arr1[i];
			//cout << endl;
			summa+= arr1[i];
		}
		arr1[N1 - 1] = 1 - summa;
		cout << "Probability of " << N1 << " = " << arr1[N1 - 1]<<endl;
		summa = 0;
		for (int j = 0; j < N2-1; j++)
		{
			cout << "Enter probability of " << j+1 << ": ";
			cin >> arr2[j];
			//cout << endl;
			summa += arr2[j];
		}
		arr2[N2 - 1] = 1 - summa;
		cout << "Probability of " << N2 << " = " << arr2[N2 - 1] << endl;
		int sum;
		for (sum = 0; sum < N1 + N2 - 1; sum++) arr_sum[sum] = 0;
		for (sum = 0; sum < N1 + N2 - 1; sum++)
		{
			for (int i = 0; i <= sum && i<N1; i++)
			{
				for (int j = 0; j <= sum && j<N2; j++)
				{
					if (sum == i+j) arr_sum[sum] += arr1[i] * arr2[j];
				}
			}
		}
		for (sum = 0; sum < N1 + N2 - 1; sum++)
		{
			cout << "Probability of summ " <<sum+2<<" = "<< arr_sum[sum] << endl;
		}
	}

	void SumToTree(MyTree<int, double>* my, Dice cybic, int N1, int N2)
	{
		//MyTree<int, double> my;
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
		cout << "MENU:\n1)Enter tree and show all amounts\n2)Get probabilities of all amounts and show the tree\n3)Delete node\n4)Show minimum value of the tree\n5)Find value\n6)Show the tree\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			while (true)
			{
				for (int i = 2; i < cybic.AllSum(N1, N2) + 1; i++)
					cout << i << endl;
				int choice;
				cout << "1)Add one more\n2)Back\n";
				cin >> choice;
				if (choice == 2)
					break;
				else
					system("cls");
			}
			system("cls");
			break;
		case 2:
			system("cls");
			int level;
			cybic.Arrays(N1, N2);
			cybic.SumToTree(&my, cybic, N1, N2);
			my.PrintTree(my.GetTree(), level=0);
			cout << "1)Add one more\n2)Back\n";
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
			my.Min(my.GetTree());
			cout << "0)Back\n";
			cin >> choice;
			if (choice == 0)
				break;
			else
				system("cls");
			break;
		case 5:
			system("cls");
			int a, count, result;
			cout << "Enter value (amount) to find: ";
			cin >> a;
			result=my.Search(my.GetTree(), a, count=1);
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
	//cybic.Arrays(N1, N2);
	//cybic.SumToTree(&my, cybic, N1, N2);
	//my.Output(my.GetTree());
	system("pause");
}

