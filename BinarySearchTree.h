#pragma once
#include "pch.h"
#include <iostream>
#include "node.h"
using namespace std;


/*!
\brief Subclass of class node

This subclass works with binary search tree and it's functions. Such as input values,
recursive and non-recursive output values, output in tree form, do recursive and non-recursive search,
delete tree nodes and search minimal values.*/

template <typename type, typename type1>
class BinarySearchTree:public node<int, double>
{
private:
	node<int, double>* tree; ///< Tree node
public:
	node<int, double>* GetTree() ///< Tree getter
	{
		return tree;
	}

	BinarySearchTree() ///< Constructor by default
	{
		tree = nullptr;
	}

	/*!
	\brief Function for the binary search tree input

	\param curr Node
	\param i, a Are responsible for index and main value in the node
	*/
	void Input(node<int, double>* curr, type i, type1 a)
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
	/*!
	\brief Function for outputing tree

	Recursive outputing index and main values by main values from smallest to the biggest
	\param curr Node
	*/
	void Output(node<int, double>* curr)
	{
		if (curr != nullptr)
		{
			Output(curr->left);
			cout << "(" << curr->index + 1 << " : " << curr->info << ")" << endl;
			Output(curr->right);
		}
	}
	/*!
	\brief Outputs tree in the tree in the tree form

	Left (smaller) values are higher, right (bigger) values are lower
	\param curr Node
	\param level Is responsible for value level in the tree
	*/
	void PrintTree(node<int, double>* curr, int level)
	{
		if (curr)
		{
			PrintTree(curr->right, level + 1);
			for (int i = 0; i < level; i++) cout << "         ";
			cout << "(" << curr->index + 2 << ":" << curr->info << ")" << endl;
			PrintTree(curr->left, level + 1);
		}
	}
	/*!
	\brief Recursive search for value

	\param curr Node
	\param v Searched value
	\param counter Counts level of the searched value
	\return Level of the searched value in case it was in the tree
	*/
	int SearchRecursion(node<int, double>* curr, type1 v, int counter = 1)
	{

		if (curr == NULL) return -1;
		int tmp = curr->info * 1000;
		double value;
		if (tmp % 10 > 5)
			value = double((tmp + 1) / 1000.0);
		else
			value = double(tmp / 1000.0);
		if (value == v) return counter;
		if (v <= value)
		{
			if (curr->left != NULL)
				return Search(curr->left, v, ++counter);
			else return -1;
		}
		else
		{
			if (v > value)
			{
				if (curr->right != NULL)
					return Search(curr->right, v, ++counter);
				else return -1;
			}
		}
	}

	/*!
	\brief Non-recursive search for the value

	\param curr Node
	\param v Searched value
	\param counter Counts level of the searched value
	\return Level of the searched value in case it was in the tree
	*/
	int SearchLoop(node<int, double>* curr, type1 v, int counter = 1)
	{
		while (curr != nullptr)
		{
			int tmp = curr->info * 1000;
			double value;
			if (tmp % 10 > 5)
				value = double((tmp + 1) / 1000.0);
			else
				value = double(tmp / 1000.0);
			if (value == v)
				return counter;
			counter++;
			curr = value > v ? curr->left : curr->right;
		}
		return -1;
	}

	/*!
	\brief Finds minimal value in the tree and returns it's node

	Used for the deleting value function
	\param curr Node
	\param c Node which searches for minimal value
	\return Node with minimal value
	*/
	node<int, double>* Min(node<int, double>* curr)
	{
		node* c = curr;
		while (c && c->left != nullptr) c = c->left;
		return c;
	}

	/*!
	\brief Finds minimal value in the tree and returns it

	Used for the outputing minimal value
	\param curr Node
	\param c Node which searches for minimal value
	\return Minimal value
	*/
	int MinOutput(node<int, double>* curr)
	{
		node* c = curr;
		while (c && c->left != nullptr) c = c->left;
		return c->index + 2;
	}

	/*!
	\brief Delets node with inputed value

	\param curr Node
	\param v Value which must be deleted
	\param tmp_ Variable which contains node's value multiplied for 1000, as searching doesn't works with doubles
	\param tmp Node which contains descent value of the deleted node and node with the smallest value after the deleted node
	*/
	node<int, double>* DeleteNode(node<int, double>* curr, type1 v)
	{
		if (curr == nullptr)
			return curr;
		int tmp_ = curr->info * 1000;
		double value;
		if (tmp_ % 10 > 5)
			value = double((tmp_ + 1) / 1000.0);
		else
			value = double(tmp_ / 1000.0);
		if (v < value)
			curr->left = DeleteNode(curr->left, v);
		else if (v > value)
			curr->right = DeleteNode(curr->right, v);
		else
		{
			if (curr->left == nullptr)
			{
				node* tmp = curr->right;
				free(curr);
				return tmp;
			}
			else if (curr->right == nullptr)
			{
				node* tmp = curr->left;
				free(curr);
				return tmp;
			}
			node* tmp = Min(curr->right);
			curr->info = tmp->info;
			curr->index = tmp->index;
			curr->right = DeleteNode(curr->right, tmp->info);
		}
		return curr;
	}
};