#pragma once
#include "pch.h"
#include <iostream>


/*!
\brief Class of the list


This class is responsible for the list, it's nodes, and values in the node
\param next Next nodes
\param prev Previous nodes
\param info Template value in the node, which is responsible for the main value
\param index Template value in the node, which is responsible for the index
*/
template <typename type, typename type1>
class NodeList
{
public:
	NodeList*next;
	NodeList*prev;
	type index;
	type1 info;
	NodeList()
	{
		this->next = nullptr;
		this->prev = nullptr;
	}
};
