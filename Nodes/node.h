#pragma once


/*!
\brief Class of the tree

This class is responsible for the tree, it's descents, and values in the node
\param right, left Descent pointers
\param info Template value in the node, which is responsible for the main value
\param index Template value in the node, which is responsible for the index
*/
template <typename type1>
class node
{
public:
	node()
	{
		this->right = nullptr;
		this->left = nullptr;
	}
	type1 info;
	node* right;
	node* left;
};

