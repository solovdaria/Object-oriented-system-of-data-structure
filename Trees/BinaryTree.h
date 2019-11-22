#pragma once
#include "pch.h"
#include <iostream>
#include "Dice/SetOfDice.h"
#include "Dice/Dice.h"
#include "Nodes/node.h"
#include <queue>
#include <string>
#include <vector>
using namespace std;

/*!
\brief Subclass of class node

This subclass works with binary tree and it's functions. Such as input values,
recursive output values, output in tree form, do recursive search,
delete tree nodes.*/

template <typename type1>
class BinaryTree :public node<type1>
{
private:
	node<type1>* tree; ///< Tree node
	/*!
	\brief Finds deepest value in the tree and returns it's node

	Used for the deleting value function
	\param root Node
	\return Node with deepest value
	*/
	void deletBTnode(node<type1> *root, node<type1>* del)
	{
		queue<node<type1>*> q;
		q.push(root);
		node<type1>* temp = nullptr;
		node<type1>* key_node = nullptr;
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			if (temp->left != nullptr && temp->left == del)
			{
				delete temp->left;
				temp->left = nullptr;
				return;
			}
			if (temp->right != nullptr && temp->right == del)
			{
				delete temp->right;
				temp->right = nullptr;
				return;
			}
			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
	}

public:
	node<type1>* GetTree() ///< Tree getter
	{
		return tree;
	}

	void SetTree(node<type1>*tree) ///< Tree setter
	{
		this->tree = tree;
	}

	BinaryTree() ///< Constructor by default
	{
		tree = nullptr;
	}

	/*!
	\brief Function for the binary tree input

	\param curr Node
	\param i, a Are responsible for index and main value in the node
	*/
	template<typename type1>
	void Input(node<type1>* curr, int i, type1 a)
	{
		if (tree == nullptr)
		{
			tree = new node<type1>;
			//			tree->index = i;
			tree->info = a;
			tree->left = tree->right = nullptr;
		}

		if (curr == nullptr)
		{
			curr = new node<type1>;
			//			curr->index = i;
			curr->info = a;
			curr->left = curr->right = nullptr;
		}

		if (curr->left == nullptr)
		{
			curr->left = new node<type1>;
			curr->left->left = curr->left->right = nullptr;
			//			curr->left->index = i;
			curr->left->info = a;
		}
		else if (curr->right == nullptr)
		{
			curr->right = new node<type1>;
			curr->right->left = curr->right->right = nullptr;
			//			curr->right->index = i;
			curr->right->info = a;
		}
		else
			Input(curr->left, i, a);
	}

	template<>
	void Input<vector<int>>(node<vector<int>>* curr, int i, vector<int> a)
	{
		if (tree == nullptr)
		{
			tree = new node<vector<int>>;
			//			tree->index = i;
			tree->info = a;
			tree->left = tree->right = nullptr;
		}

		if (curr == nullptr)
		{
			curr = new node<vector<int>>;
			//		curr->index = i;
			curr->info = a;
			curr->left = curr->right = nullptr;
		}

		if (curr->left == nullptr)
		{
			curr->left = new node<vector<int>>;
			curr->left->left = curr->left->right = nullptr;
			//		curr->left->index = i;
			curr->left->info = a;
		}
		else if (curr->right == nullptr)
		{
			curr->right = new node<vector<int>>;
			curr->right->left = curr->right->right = nullptr;
			//		curr->right->index = i;
			curr->right->info = a;
		}
		else
			Input(curr->left, i, a);
	}

	/*!
	\brief Function for the postorder output
	*/
	template<typename type1>
	void PrintPostorder(node<type1>* curr)
	{
		if (curr == nullptr)
			return;
		PrintPostorder(curr->left);
		PrintPostorder(curr->right);
		cout << curr->info << " ";
	}

	template<>
	void PrintPostorder<SetOfDice>(node<SetOfDice>* curr)
	{
		if (curr == nullptr)
			return;
		PrintPostorder(curr->left);
		PrintPostorder(curr->right);
		cout << "A" << curr->info.GetNumOfDice() << ":" << curr->info.GetAmountMS() << " ";
	}

	/*!
	\brief Function for the inorder output
	*/
	template<typename type1>
	void PrintInorder(node<type1>*curr)
	{
		if (curr == nullptr)
			return;
		PrintInorder(curr->left);
		cout << curr->info << " ";;
		PrintInorder(curr->right);
	}

	template<>
	void PrintInorder<SetOfDice>(node<SetOfDice>*curr)
	{
		if (curr == nullptr)
			return;
		PrintInorder(curr->left);
		cout << "A" << curr->info.GetNumOfDice() << ":" << curr->info.GetAmountMS() << " ";;
		PrintInorder(curr->right);
	}

	/*!
	\brief Function for the preorder output
	*/
	template<typename type1>
	void PrintPreorder(node<type1>*curr)
	{
		if (curr == nullptr)
			return;
		cout << curr->info << " ";
		PrintPreorder(curr->left);
		PrintPreorder(curr->right);
	}

	template<>
	void PrintPreorder<SetOfDice>(node<SetOfDice>* curr)
	{
		if (curr == nullptr)
			return;
		cout << "A" << curr->info.GetNumOfDice() << ":" << curr->info.GetAmountMS() << " ";
		PrintPreorder(curr->left);
		PrintPreorder(curr->right);
	}
	/*!
	\brief Recursive search for value

	\param curr Node
	\param v Searched value
	\param counter Counts level of the searched value
	\return Level of the searched value in case it was in the tree
	*/
	template<typename type1>
	int Search(node<type1>* curr, type1 v, int counter)
	{
		if (curr == NULL) return -1;
		int tmp = curr->info * 1000;
		double value;
		if (tmp % 10 > 5)
			value = double((tmp + 1) / 1000.0);
		else
			value = double(tmp / 1000.0);

		if (value == v)
			return counter;

		if (Search(curr->left, v, counter) != -1)
			return Search(curr->left, v, ++counter);
		if (Search(curr->right, v, counter) != -1)
			return Search(curr->right, v, ++counter);
		return -1;
	}

	template<>
	int Search<string>(node<string>* curr, string v, int counter)
	{
		if (curr == nullptr)
			return -1;
		if (curr->info == v)
			return counter;

		if (Search(curr->left, v, counter) != -1)
			return Search(curr->left, v, ++counter);
		if (Search(curr->right, v, counter) != -1)
			return Search(curr->right, v, ++counter);
		return -1;
	}

	template<>
	int Search<vector<int>>(node<vector<int>>* curr, vector<int> v, int counter)
	{
		if (curr == nullptr)
			return -1;
		bool b = true;
		for (int i = 0; i < curr->info.size(); i++)
		{
			if (curr->info[i] != v[i])
			{
				b = false;
			}
		}
		if (b)
			return counter;

		if (Search(curr->left, v, counter) != -1)
			return Search(curr->left, v, ++counter);
		if (Search(curr->right, v, counter) != -1)
			return Search(curr->right, v, ++counter);
		return -1;
	}

	template<>
	int Search<SetOfDice>(node<SetOfDice>* curr, SetOfDice v, int counter)
	{
		if (curr == NULL) return -1;
		int tmp = curr->info.GetAmountMS() * 1000;
		double value;
		if (tmp % 10 > 5)
			value = double((tmp + 1) / 1000.0);
		else
			value = double(tmp / 1000.0);

		if (value == v.GetAmountMS())
			return --counter;

		if (Search(curr->left, v, ++counter) != -1)
			return Search(curr->left, v, ++counter);
		if (Search(curr->right, v, ++counter) != -1)
			return Search(curr->right, v, ++counter);
		return -1;

	}

	/* function to delete element in binary tree */
	template<typename type1>
	node<type1>* deletion(node<type1>* root, type1 key)
	{
		int tmp_ = root->info * 1000;
		double value;
		if (tmp_ % 10 > 5)
			value = double((tmp_ + 1) / 1000.0);
		else
			value = double(tmp_ / 1000.0);
		if (root == nullptr)
			return nullptr;

		if (root->left == nullptr && root->right == nullptr) {
			if (value == key)
				return nullptr;
			else
				return root;
		}

		queue<node<type1>*> q;
		q.push(root);

		node<type1>* temp = nullptr;
		node<type1>* key_node = nullptr;
		while (!q.empty()) {
			temp = q.front();
			q.pop();

			int tmp1 = temp->info * 1000;
			double value1;
			if (tmp1 % 10 > 5)
				value1 = double((tmp1 + 1) / 1000.0);
			else
				value1 = double(tmp1 / 1000.0);
			if (value1 == key)
				key_node = temp;

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
		if (key_node != temp)
		{
			if (key_node != nullptr) {
				double x = temp->info;
				deletBTnode(root, temp);
				key_node->info = x;
			}
		}
		else deletBTnode(root, temp);
		return root;
	}

	template<>
	node<vector<int>>* deletion(node<vector<int>>* root, vector<int> key)
	{
		if (root == nullptr)
			return nullptr;

		if (root->left == nullptr && root->right == nullptr) {
			bool b = true;
			for (int i = 0; i < root->info.size(); i++)
			{
				if (root->info[i] != key[i])
				{
					b = false;
				}
			}
			if (b)
				return nullptr;
			else
				return root;
		}

		queue<node<vector<int>>*> q;
		q.push(root);

		node<vector<int>>* temp = nullptr;
		node<vector<int>>* key_node = nullptr;
		while (!q.empty()) {
			temp = q.front();
			q.pop();

			bool bs = true;
			for (int i = 0; i < temp->info.size(); i++)
			{
				if (temp->info[i] != key[i])
					bs = false;
			}
			if (bs)
				key_node = temp;
			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
		if (key_node != temp)
		{
			if (key_node != nullptr) {
				vector<int> x = temp->info;
				deletBTnode(root, temp);
				key_node->info = x;
			}
		}
		else
			deletBTnode(root, temp);
		return root;
	}

	template<>
	node<SetOfDice>* deletion(node<SetOfDice>* root, SetOfDice key)
	{

		int tmp_ = root->info.GetAmountMS() * 1000;
		double value;
		if (tmp_ % 10 > 5)
			value = double((tmp_ + 1) / 1000.0);
		else
			value = double(tmp_ / 1000.0);
		if (root == nullptr)
			return nullptr;

		if (root->left == nullptr && root->right == nullptr) {
			if (value == key.GetAmountMS())
				return nullptr;
			else
				return root;
		}

		queue<node<SetOfDice>*> q;
		q.push(root);

		node<SetOfDice>* temp = nullptr;
		node<SetOfDice>* key_node = nullptr;
		while (!q.empty()) {
			temp = q.front();
			q.pop();

			int tmp1 = temp->info.GetAmountMS() * 1000;
			double value1;
			if (tmp1 % 10 > 5)
				value1 = double((tmp1 + 1) / 1000.0);
			else
				value1 = double(tmp1 / 1000.0);
			if (value1 == key.GetAmountMS())
				key_node = temp;

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
		if (key_node != temp)
		{
			if (key_node != nullptr) {
				double x = temp->info.GetAmountMS();
				deletBTnode(root, temp);
				key_node->info.SetAmountMS(x);
			}
		}
		else deletBTnode(root, temp);
		return root;
	}

	template<>
	node<string>* deletion(node<string>* root, string key)
	{

		if (root == nullptr)
			return nullptr;

		if (root->left == nullptr && root->right == nullptr) {
			if (root->info == key)
				return nullptr;
			else
				return root;
		}

		queue<node<string>*> q;
		q.push(root);

		node<string>* temp = nullptr;
		node<string>* key_node = nullptr;
		while (!q.empty()) {
			temp = q.front();
			q.pop();

			if (temp->info == key)
				key_node = temp;

			if (temp->left != nullptr && temp->left->info == key &&
				temp->left->left == nullptr && temp->left->right == nullptr)
			{
				delete temp->left;
				temp->left = nullptr;
			}
			if (temp->right != nullptr && temp->right->info == key &&
				temp->right->left == nullptr && temp->right->right == nullptr)
			{
				delete temp->right;
				temp->right = nullptr;
			}

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
		if (key_node != temp)
		{
			if (key_node != nullptr) {
				string x = temp->info;
				deletBTnode(root, temp);
				key_node->info = x;
			}
		}
		else deletBTnode(root, temp);
		return root;
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
		if (curr)
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

};
