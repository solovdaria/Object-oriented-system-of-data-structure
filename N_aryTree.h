#pragma once
#include "pch.h"
#include <iostream>
#include "NodeList.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/*!
\brief Subclass of class NodeList

This subclass works with n-ary tree and it's functions. Such as input values, create n-ary tree
output values, do search, delete tree nodes.*/
template <typename type, typename type1>
class N_aryTree:public NodeList<int, double>
{
private:
	NodeList<int, double>*nodes; ///< Tree node
	NodeList<int, double>*head; ///< List head
	NodeList<int, double>*tail; ///< List tail
public:
	N_aryTree() ///< Constructor by default
	{
		head = nullptr;
		tail = nullptr;
	}

	NodeList<int, double>*GetList() ///< List getter
	{
		return nodes;
	}

	NodeList<int, double>* GetHead() ///< Head getter
	{ 
		return head;
	}

	/*!
	\brief Function for the n-ary tree list add to the end of the list

	\param element Node
	\param i, a Are responsible for index and main value in the node
	*/
	void AddLast(NodeList<int, double>*element, type i, type1 a) 
	{
		element = new NodeList<int, double>;
		element->info = a;
		element->index = i;
		element->next = nullptr;
		if (head == nullptr)
		{
			element->prev = nullptr;
			head = tail = element;
		}
		else
		{
			tail->next = element;
			element->prev = tail;
			tail = tail->next;
		}
	}

	/*!
	\brief Search for value

	\param current Node
	\param a Searched value
	\return Index of the searched value in case it was in the list
	*/
	void Search(type1 a) 
	{
		NodeList*current = head;
		while (current != nullptr)
		{
			if (current->info == a)
			{
				cout << current->index << " ";
				current = current->next;
			}
			else current = current->next;
		}
	}

	/*!
	\brief Function for outputing list

	Outputing index and main values 
	\param current Node
	\param head Head of the list
	*/
	void Output()
	{
		NodeList<int, double>*current = head;
		while (current != nullptr)
		{
			cout << current->index+2 << ":"<<current->info<<" ";
			current = current->next;
		}
		cout << endl;
	}

	/*!
	\brief Delets node with inputed value

	\param current Node
	\param need Value which must be deleted
	\param head Head of the list
	*/
	void Delete(type1 need)
	{
		NodeList<int, double>*current = head, *prev = head;
		while (current != nullptr)
		{
			if (current->info == need)
			{
				if (current == head) 
				{
					head = head->next;
					delete current;
					break;
				}
				else 
				{
					prev->next = current->next;
					delete current; 
					break;
				}
			}
			else { prev = current; current = current->next; }
		}
	}

	/*!
	\brief Sorts list in the n-ary tree form

	\param a List, which we are working with
	\param b Created list in the n-ary tree form
	*/
	void Sort(N_aryTree<int, double> &a, N_aryTree<int, double> &b, int n) {
		vector<double> c, d;
		NodeList<int, double>* head = a.GetHead();
		while (head != nullptr) {
			c.push_back(head->info);
			head = head->next;
		}
		head = a.GetHead();
		vector<double> c1;
		//----------------------------------------------------
		sort(c.begin(), c.end());
		if (!c.empty()) {
			int p = 1;
			while (p + n < c.size()) reverse(&c[p], &c[p + n]), p += n;
			reverse(&c[p], (&c[c.size() - 1] + 1));
			int N = n;
			c1.push_back(c[0]);
			p = 1;
			static auto j = c1.begin();
			while (p != c.size())
			{
				while ((N--) && (p != c.size())) j = c1.insert(j, c[p++]);
				N = n;
				if (p != c.size()) {
					while (N--) j++;
					if (++j == c1.end()) j = c1.begin();
				}
				N = n;
			}
		}
		//----------------------------------------------------
		int j = 0;
		for (auto i : c1) {
			b.AddLast(head, j++, i);
			if (head)head = head->prev;
		}
	}
};

