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
			cout << curr->index<<" : ";
			cout << curr->info <<endl;
			Output(curr->right);
		}
	}

	int Search(node*curr, type v, int counter = 1) //поиск значения
	{
		if (curr == nullptr) return -1;
		if (curr->info == v) return counter;

		if (v <= curr->info)
		{
			if (curr->left != nullptr)
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
	void AllSum(int N1, int N2)
	{
		int maxSum = N1 + N2;
	}

	double*arr_sum;
	void Arrays(int N1, int N2)
	{
		double summa = 0;
		double*arr1 = new double[N1];
		double*arr2 = new double[N2];
		arr_sum = new double[N1 * N2];
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
		int k = 0;
		for (int i = 0; i < N1; i++)
		{
			for (int j = 0; j < N2; j++)
			{
				arr_sum[k] = arr1[i] * arr2[j];
				cout << "Probability of summ " << i + 1 << "*" << j + 1 << " = " << arr_sum[k] << endl;
				k++;
			}
			
		}
	}

	void SumToTree(MyTree<int, double>* my, Dice cybic, int N1, int N2)
	{
		//MyTree<int, double> my;
		for (int k = 0; k < N1*N2; k++)
		{
			my->Input(my->GetTree(), k, cybic.arr_sum[k]);
		}
	}

};


int main()
{
	MyTree<int, double> my;
	Dice cybic;
	int N1, N2;
	cout << "Enter N1: ";
	cin >> N1;
	cout << endl;
	cout << "Enter N2: ";
	cin >> N2;
	cout << endl;
	cybic.Arrays(N1, N2);
	cybic.SumToTree(&my, cybic, N1, N2);
	my.Output(my.GetTree());
	/*MyTree<int> my;
	int n, data, v;
	cout << "Enter number of nodes: ";
	cin >> n;
	cout << "Enter v: ";
	cin >> v;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter int " << i << ": ";
		cin >> data;
		my.Input(my.GetTree(), data);
	}
	my.Output(my.GetTree());
	cout << endl;*/
	//count = my.Search(my.GetTree(), v, c = 1);
	//if (count < 0) cout << "Tree don't have v!" << endl;
	//else cout << count << endl;
	//my.DeleteNode(my.GetTree(), v);
	//my.Output(my.GetTree());
	system("pause");
}

