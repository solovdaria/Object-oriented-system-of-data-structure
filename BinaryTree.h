#pragma once
#include "pch.h"
#include <iostream>
#include "node.h"
#include <queue>
using namespace std;

/*!
\brief Subclass of class node

This subclass works with binary tree and it's functions. Such as input values,
recursive output values, output in tree form, do recursive search,
delete tree nodes.*/

template <typename type, typename type1>
class BinaryTree:public node<int, double>
{
private:
	node<int, double>* tree; ///< Tree node
public:
	node<int, double>* GetTree() ///< Tree getter
	{
		return tree;
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

		if (curr->left == nullptr)
		{
			curr->left = new node();
			curr->left->left = curr->left->right = nullptr;
			curr->left->index = i;
			curr->left->info = a;
		}
		else if (curr->right == nullptr)
		{
			curr->right = new node();
			curr->right->left = curr->right->right = nullptr;
			curr->right->index = i;
			curr->right->info = a;
		}
		else
			Input(curr->left, i, a);
	}
	
	/*!
	\brief Function for the postorder output
	*/
	void PrintPostorder(node<int, double>* curr)
	{
		if (curr == nullptr)
			return;
		PrintPostorder(curr->left);
		PrintPostorder(curr->right);
		cout << curr->index + 2 << ":" << curr->info << " ";
	}

	/*!
	\brief Function for the inorder output
	*/
	void PrintInorder(node<int, double>*curr)
	{
		if (curr == nullptr)
			return;
		PrintInorder(curr->left);
		cout << curr->index + 2 << ":" << curr->info << " ";;
		PrintInorder(curr->right);
	}

	/*!
	\brief Function for the preorder output
	*/
	void PrintPreorder(node<int, double>*curr)
	{
		if (curr == nullptr)
			return;
		cout <<curr->index+2<<":"<< curr->info << " ";
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
	int Search(node<int, double>* curr, type1 v, int counter = 1)
	{
		if (curr == NULL) return -1;
		int tmp = curr->info * 1000;
		double value;
		if (tmp % 10 > 5)
			value = double((tmp + 1) / 1000.0);
		else
			value = double(tmp / 1000.0);

		if (curr->info == v)
			return counter;

		return Search(curr->left, v, ++counter);
		return Search(curr->right, v, ++counter);
	}

	/*!
	\brief Finds deepest value in the tree and returns it's node

	Used for the deleting value function
	\param curr Node
	\param c Node which searches for deepest value
	\return Node with deepest value
	*/
	node*Deepest(node<int, double>* curr)
	{
		node<int, double>* c = curr;
		while (c && c->right != nullptr) c = c->right;
		while (c->left != nullptr) c = c->left;
		return c;
	}

	/*!
	\brief Delets node with inputed value

	\param curr Node
	\param v Value which must be deleted
	\param tmp_ Variable which contains node's value multiplied for 1000, as searching doesn't works with doubles
	\param tmp Node which contains descent value of the deleted node and node with the deepest value in the tree
	*/
	node<int, double>* DeleteNode(node<int, double>*curr, type1 v)
	{
		node<int, double>*root = curr;
		if (curr == nullptr)
			return curr;
		int tmp_ = curr->info * 1000;
		double value;
		if (tmp_ % 10 > 5)
			value = double((tmp_ + 1) / 1000.0);
		else
			value = double(tmp_ / 1000.0);
		if (curr->info==v)
		{
			if (curr->left == nullptr)
			{
				node<int, double>* tmp = curr->right;
				free(curr);
				return tmp;
			}
			else if (curr->right == nullptr)
			{
				node<int, double>* tmp = curr->left;
				free(curr);
				return tmp;
			}
			node<int, double>* tmp = Deepest(root);
			curr->info = tmp->info;
			curr->index = tmp->index;
			DeleteNode(root, tmp->info);
		}
		DeleteNode(root->left, v);
		DeleteNode(root->right, v);
		return curr;
	}

	void deletDeepest(node<int, double>* root, node<int, double>* d_node)
	{
		queue<node<int, double>*> q;
		q.push(root);

		// Do level order traversal until last node 
		node<int, double>* temp;
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			if (temp == d_node) {
				temp = NULL;
				delete (d_node);
				return;
			}
			if (temp->right) {
				if (temp->right == d_node) {
					temp->right = NULL;
					delete (d_node);
					return;
				}
				else
					q.push(temp->right);
			}

			if (temp->left) {
				if (temp->left == d_node) {
					temp->left = NULL;
					delete (d_node);
					return;
				}
				else
					q.push(temp->left);
			}
		}
	}

	node<int, double>* deletion(node<int, double>* root, type1 key)
	{

		//node<int, double>*root = curr;
		if (root == nullptr)
			return root;
		int tmp_ = root->info * 1000;
		double value;
		if (tmp_ % 10 > 5)
			value = double((tmp_ + 1) / 1000.0);
		else
			value = double(tmp_ / 1000.0);
		if (root == NULL)
			return NULL;

		if (root->left == NULL && root->right == NULL) {
			if (root->info == key)
				return NULL;
			else
				return root;
		}

		queue<node<int, double>*> q;
		q.push(root);

		node<int, double>* temp=NULL;
		node<int, double>* key_node = NULL;

		// Do level order traversal to find deepest 
		// node(temp) and node to be deleted (key_node) 
		while (!q.empty()) {
			temp = q.front();
			q.pop();

			if (temp->info == key)
				key_node = temp;

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}

		if (key_node != NULL) {
			int x = temp->info;
			deletDeepest(root, temp);
			key_node->info = x;
		}
		return root;
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
};
