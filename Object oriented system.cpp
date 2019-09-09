// Object oriented system.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

template <typename type>
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
		type info;
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
		this->info = copy.info;
	}

	void Input(node*curr, type a)
	{
		if (tree == nullptr)
		{
			tree = new node();
			tree->info = a;
			tree->left = tree->right = nullptr;
		}

		if (curr == nullptr)
		{
			curr = new node();
			curr->info = a;
			curr->left = curr->right = nullptr;
		}
		if (a < curr->info)
			if (curr->left != nullptr) Input(curr->left, a);
			else
			{
				curr->left = new node();
				curr->left->left = curr->left->right = nullptr;
				curr->left->info = a;
			}
		if (a > curr->info)
			if (curr->right != nullptr) Input(curr->right, a);
			else
			{
				curr->right = new node();
				curr->right->left = curr->right->right = nullptr;
				curr->right->info = a;
			}
	}

	void Output(node*curr)
	{
		if (curr != nullptr)
		{
			Output(curr->left);
			cout << curr->info << " ";
			Output(curr->right);
		}
	}

	int Search(node*curr, type v, int counter = 1) //поиск значения
	{
		if
 (curr == nullptr) return -1;
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
};

int main()
{
	MyTree<int> my;
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
	cout << endl;
	//count = my.Search(my.GetTree(), v, c = 1);
	//if (count < 0) cout << "Tree don't have v!" << endl;
	//else cout << count << endl;
	my.DeleteNode(my.GetTree(), v);
	my.Output(my.GetTree());
	system("pause");
}

