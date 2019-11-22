#pragma once
#include "pch.h"
#include <iostream>
#include "Dice.h"
#include "SetOfDice.h"
#include "node.h"
#include <string>
#include <vector>
using namespace std;

/*!
\brief Subclass of class node

This subclass works with binary search tree and it's functions. Such as input values,
recursive and non-recursive output values, output in tree form, do recursive and non-recursive search,
delete tree nodes and search minimal values.*/

template <typename type1>
class BinarySearchTree :public node<type1>
{
private:
	node<type1>* tree; ///< Tree node
	/*!
	\brief Function shows if vectors are equal

	\param a, b Vectors
	*/
	int Equal(vector<int> a, vector<int> b)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] > b[i])
			{
				return 2;
			}
			else if (a[i] < b[i])
			{
				return 3;
			}
		}
		return 1;
	}
	/*!
	\brief Finds minimal value in the tree and returns it's node

	Used for the deleting value function
	\param curr Node
	\param c Node which searches for minimal value
	\return Node with minimal value
	*/
	template<typename type1>
	node<type1>* Min(node<type1>* curr)
	{
		node<type1>* c = curr;
		while (c && c->left != nullptr) c = c->left;
		return c;
	}

	template<>
	node<class SetOfDice>* Min<class SetOfDice>(node<class SetOfDice>* curr)
	{
		node<SetOfDice>* c = curr;
		while (c && c->left != nullptr) c = c->left;
		return c;
	}
public:
	node<type1>* GetTree() ///< Tree getter
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
	template <typename type1>
	void Input(node<type1>* curr, int i, type1 a, int j)
	{
		if (tree == nullptr)
		{
			tree = new node<type1>;
			tree->info = a;
			tree->left = tree->right = nullptr;
		}

		if (curr == nullptr)
		{
			curr = new node<type1>;
			//	curr->index = i;
			curr->info = a;
			curr->left = curr->right = nullptr;
		}
		if (a < curr->info)
			if (curr->left != nullptr) Input(curr->left, i, a, 0);
			else
			{
				curr->left = new node<type1>;
				curr->left->left = curr->left->right = nullptr;
				//		curr->left->index = i;
				curr->left->info = a;
			}
		if (a > curr->info)
			if (curr->right != nullptr) Input(curr->right, i, a, 0);
			else
			{
				curr->right = new node<type1>;
				curr->right->left = curr->right->right = nullptr;
				//		curr->right->index = i;
				curr->right->info = a;
			}
	}

	template<>
	void Input<string>(node<string>* curr, int i, string str, int j)
	{
		int a = str[j];
		if (tree == nullptr)
		{
			tree = new node<string>;
			//		tree->index = i;
			tree->info = str;
			tree->left = tree->right = nullptr;
			return;
		}

		if (curr == nullptr)
		{
			curr = new node<string>;
			//	curr->index = i;
			curr->info = str;
			curr->left = curr->right = nullptr;
			return;
		}
		if (a == curr->info[j])
		{
			j++;
			Input(curr, i, str, j);
			return;
		}
		if (a < curr->info[j])
			if (curr->left != nullptr) Input(curr->left, i, str, 0);
			else
			{
				curr->left = new node<string>;
				curr->left->left = curr->left->right = nullptr;
				//				curr->left->index = i;
				curr->left->info = str;
			}
		if (a > curr->info[j])
			if (curr->right != nullptr) Input(curr->right, i, str, 0);
			else
			{
				curr->right = new node<string>;
				curr->right->left = curr->right->right = nullptr;
				//				curr->right->index = i;
				curr->right->info = str;
			}
	}

	template<>
	void Input<vector<int>>(node<vector<int>>* curr, int i, vector<int> a, int j)
	{
		int b = a[j];
		if (tree == nullptr)
		{
			tree = new node<vector<int>>;
			//	tree->index = i;
			tree->info = a;
			tree->left = tree->right = nullptr;
			return;
		}

		if (curr == nullptr)
		{
			curr = new node<vector<int>>;
			//		curr->index = i;
			curr->info = a;
			curr->left = curr->right = nullptr;
			return;
		}
		if (b == curr->info[j])
		{
			j++;
			Input(curr, i, a, j);
			return;
		}
		if (b < curr->info[j])
			if (curr->left != nullptr) Input(curr->left, i, a, 0);
			else
			{
				curr->left = new node<vector<int>>;
				curr->left->left = curr->left->right = nullptr;
				//				curr->left->index = i;
				curr->left->info = a;
			}
		if (b > curr->info[j])
			if (curr->right != nullptr) Input(curr->right, i, a, 0);
			else
			{
				curr->right = new node<vector<int>>;
				curr->right->left = curr->right->right = nullptr;
				//				curr->right->index = i;
				curr->right->info = a;
			}
	}

	template<>
	void Input<class SetOfDice>(node<class SetOfDice>* curr, int i, SetOfDice a, int j)
	{
		if (tree == nullptr)
		{
			tree = new node<SetOfDice>;
			tree->info = a;
			tree->left = tree->right = nullptr;
		}

		if (curr == nullptr)
		{
			curr = new node<SetOfDice>;
			curr->info = a;
			curr->left = curr->right = nullptr;
		}
		if (a.GetMS() < curr->info.GetAmountMS())
			if (curr->left != nullptr) Input(curr->left, i, a, 0);
			else
			{
				curr->left = new node<SetOfDice>;
				curr->left->left = curr->left->right = nullptr;
				curr->left->info = a;
			}
		if (a.GetMS() > curr->info.GetAmountMS())
			if (curr->right != nullptr) Input(curr->right, i, a, 0);
			else
			{
				curr->right = new node<SetOfDice>;
				curr->right->left = curr->right->right = nullptr;
				curr->right->info = a;
			}
	}

	/*!
	\brief Function for outputing tree

	Recursive outputing index and main values by main values from smallest to the biggest
	\param curr Node
	*/
	template<typename type1>
	void Output(node<type1>* curr)
	{
		if (curr != nullptr)
		{
			Output(curr->left);
			cout << curr->info << endl;
			Output(curr->right);
		}
	}
	template<>
	void Output<class SetOfDice>(node<class SetOfDice>* curr)
	{
		if (curr != nullptr)
		{
			Output(curr->left);
			cout << "(A" << curr->info.GetNumOfDice() << ":" << curr->info.GetAmountMS() << ")" << endl;
			Output(curr->right);
		}
	}

	template<>
	void Output<vector<int>>(node<vector<int>>* curr)
	{
		if (curr != nullptr)
		{
			Output(curr->left);
			for (int i = 0; i < curr->info.size(); i++)
				cout << curr->info[i] << endl;
			Output(curr->right);
		}
	}

	/*!
	\brief Outputs tree in the tree in the tree form

	Left (smaller) values are higher, right (bigger) values are lower
	\param curr Node
	\param level Is responsible for value level in the tree
	*/
	template<typename type1>
	void PrintTree(node<type1>* curr, int level)
	{
		if (curr != nullptr)
		{
			PrintTree(curr->right, level + 1);
			for (int i = 0; i < level; i++) cout << "         ";
			cout << "(" << curr->info << ")" << endl;
			PrintTree(curr->left, level + 1);
		}
	}

	template<>
	void PrintTree<vector<int>>(node<vector<int>>* curr, int level)
	{
		if (curr)
		{
			PrintTree(curr->right, level + 1);
			for (int i = 0; i < level; i++) cout << "         ";
			for (int i = 0; i < curr->info.size(); i++)
				cout << curr->info[i] << " ";
			cout << endl;
			PrintTree(curr->left, level + 1);
		}
	}

	template<>
	void PrintTree<SetOfDice>(node<SetOfDice>* curr, int level)
	{
		if (curr)
		{
			PrintTree(curr->right, level + 1);
			for (int i = 0; i < level; i++) cout << "         ";
			cout << "(A" << curr->info.GetNumOfDice() << ":" << curr->info.GetAmountMS() << ")" << endl;
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
	template<typename type1>
	int SearchRecursion(node<type1>* curr, type1 v, int counter)
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

	template<>
	int SearchRecursion<SetOfDice>(node<SetOfDice>* curr, SetOfDice v, int counter)
	{
		if (curr == NULL) return -1;
		int tmp = curr->info.GetAmountMS() * 1000;
		double value;
		if (tmp % 10 > 5)
			value = double((tmp + 1) / 1000.0);
		else
			value = double(tmp / 1000.0);
		if (value == v.GetAmountMS()) return counter;
		if (v.GetAmountMS() <= value)
		{
			if (curr->left != NULL)
				return SearchRecursion(curr->left, v, ++counter);
			else return -1;
		}
		else
		{
			if (v.GetAmountMS() > value)
			{
				if (curr->right != NULL)
					return SearchRecursion(curr->right, v, ++counter);
				else return -1;
			}
		}
	}

	template<>
	int SearchRecursion<string>(node<string>* curr, string v, int counter)
	{
		if (curr == NULL) return -1;

		if (curr->info == v) return counter;
		if ((v < curr->info) == 1)
		{
			if (curr->left != NULL)
				return SearchRecursion(curr->left, v, ++counter);
			else return -1;
		}
		else
		{
			if ((v > curr->info) == 1)
			{
				if (curr->right != NULL)
					return SearchRecursion(curr->right, v, ++counter);
				else return -1;
			}
		}
	}

	template<>
	int SearchRecursion<vector<int>>(node<vector<int>>* curr, vector<int> v, int counter)
	{
		if (curr == NULL) return -1;

		if (Equal(v, curr->info) == 1) return counter;
		if (Equal(v, curr->info) == 3)
		{
			if (curr->left != NULL)
				return SearchRecursion(curr->left, v, ++counter);
			else return -1;
		}
		else
		{
			if (Equal(v, curr->info) == 2)
			{
				if (curr->right != NULL)
					return SearchRecursion(curr->right, v, ++counter);
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
	template<typename type1>
	int SearchLoop(node<type1>* curr, type1 v)
	{
		int counter = 1;
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

	template<>
	int SearchLoop<SetOfDice>(node<SetOfDice>* curr, SetOfDice v)
	{
		int counter = 1;
		while (curr != nullptr)
		{
			int tmp = curr->info.GetAmountMS() * 1000;
			double value;
			if (tmp % 10 > 5)
				value = double((tmp + 1) / 1000.0);
			else
				value = double(tmp / 1000.0);
			if (value == v.GetAmountMS())
				return counter;
			counter++;
			curr = value > v.GetAmountMS() ? curr->left : curr->right;
		}
		return -1;
	}

	template<>
	int SearchLoop<string>(node<string>* curr, string v)
	{
		int counter = 1;
		while (curr != nullptr)
		{
			if (curr->info == v)
				return counter;
			counter++;
			curr = curr->info > v ? curr->left : curr->right;
		}
		return -1;
	}
	

	/*!
	\brief Finds minimal value in the tree and returns it

	Used for the outputing minimal value
	\param curr Node
	\param c Node which searches for minimal value
	\return Minimal value
	*/
	template<typename type1>
	double MinOutput(node<type1>* curr)
	{
		node<type1>* c = curr;
		while (c && c->left != nullptr) c = c->left;
		return c->info;
	}

	template<>
	double MinOutput<SetOfDice>(node<SetOfDice>* curr)
	{
		node<SetOfDice>* c = curr;
		while (c && c->left != nullptr) c = c->left;
		return c->info.GetAmountMS();
	}
	/*!
	\brief Delets node with inputed value

	\param curr Node
	\param v Value which must be deleted
	\param tmp_ Variable which contains node's value multiplied for 1000, as searching doesn't works with doubles
	\param tmp Node which contains descent value of the deleted node and node with the smallest value after the deleted node
	*/
	template<typename type1>
	node<type1>* DeleteNode(node<type1>* curr, type1 v)
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
				node<type1>* tmp = curr->right;
				free(curr);
				return tmp;
			}
			else if (curr->right == nullptr)
			{
				node<type1>* tmp = curr->left;
				free(curr);
				return tmp;
			}
			node<type1>* tmp = Min(curr->right);
			curr->info = tmp->info;
			curr->right = DeleteNode(curr->right, tmp->info);
		}
		return curr;
	}

	template<>
	node<vector<int>>* DeleteNode(node<vector<int>>* curr, vector<int> v)
	{
		if (curr == nullptr)
			return curr;
		if (Equal(curr->info, v) == 2)
			curr->left = DeleteNode(curr->left, v);
		else if (Equal(curr->info, v) == 3)
			curr->right = DeleteNode(curr->right, v);
		else
		{
			if (curr->left == nullptr)
			{
				node<vector<int>>* tmp = curr->right;
				free(curr);
				return tmp;
			}
			else if (curr->right == nullptr)
			{
				node<vector<int>>* tmp = curr->left;
				free(curr);
				return tmp;
			}
			node<vector<int>>* tmp = Min(curr->right);
			curr->info = tmp->info;
			curr->right = DeleteNode(curr->right, tmp->info);
		}
		return curr;
	}

	template<>
	node<string>* DeleteNode(node<string>* curr, string a)
	{
		if (curr == nullptr)
			return curr;
		if ((a < curr->info) == 1)
			curr->left = DeleteNode(curr->left, a);
		else if ((a > curr->info) == 1)
			curr->right = DeleteNode(curr->right, a);
		else
		{
			if (curr->left == nullptr)
			{
				node<string>* tmp = curr->right;
				free(curr);
				return tmp;
			}
			else if (curr->right == nullptr)
			{
				node<string>* tmp = curr->left;
				free(curr);
				return tmp;
			}
			node<string>* tmp = Min(curr->right);
			curr->info = tmp->info;
			curr->right = DeleteNode(curr->right, tmp->info);
		}
		return curr;
	}

	template<>
	node<SetOfDice>* DeleteNode<SetOfDice>(node<SetOfDice>* curr, SetOfDice v)
	{
		if (curr == nullptr)
			return curr;
		int tmp_ = (curr->info.GetAmountMS()) * 1000;
		double value;
		if (tmp_ % 10 > 5)
			value = double((tmp_ + 1) / 1000.0);
		else
			value = double(tmp_ / 1000.0);
		if (v.GetAmountMS() < value)
			curr->left = DeleteNode(curr->left, v);
		else if (v.GetAmountMS() > value)
			curr->right = DeleteNode(curr->right, v);
		else
		{
			if (curr->left == nullptr)
			{
				node<SetOfDice>* tmp = curr->right;
				free(curr);
				return tmp;
			}
			else if (curr->right == nullptr)
			{
				node<SetOfDice>* tmp = curr->left;
				free(curr);
				return tmp;
			}
			node<SetOfDice>* tmp = Min<SetOfDice>(curr->right);
			curr->info = tmp->info;
			curr->right = DeleteNode(curr->right, tmp->info);
		}
		return curr;
	}
};