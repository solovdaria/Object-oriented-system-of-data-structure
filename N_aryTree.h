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
template <typename type1>
class N_aryTree :public NodeList<type1>
{
private:
	NodeList<type1>*nodes; ///< Tree node
	NodeList<type1>*head; ///< List head
	NodeList<type1>*tail; ///< List tail
public:
	N_aryTree() ///< Constructor by default
	{
		head = nullptr;
		tail = nullptr;
	}

	NodeList<type1>*GetList() ///< List getter
	{
		return nodes;
	}

	NodeList<type1>* GetHead() ///< Head getter
	{
		return head;
	}

	/*!
	\brief Function for the n-ary tree list add to the end of the list

	\param element Node
	\param i, a Are responsible for index and main value in the node
	*/
	void AddLast(NodeList<type1>*element, int i, type1 a)
	{
		element = new NodeList<type1>;
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
	template<typename type1>
	void Search(NodeList<type1>*current, type1 a)
	{
		current = head;
		while (current != nullptr)
		{
			if (current->info == a)
			{
				cout << current->index + 1 << " ";
				current = current->next;
			}
			else current = current->next;
		}
	}

	template<>
	void Search<Dice>(NodeList<Dice>*current, Dice a)
	{
		current = head;
		while (current != nullptr)
		{
			int tmp_ = (current->info.GetMS()) * 1000;
			double value;
			if (tmp_ % 10 > 5)
				value = double((tmp_ + 1) / 1000.0);
			else
				value = double(tmp_ / 1000.0);
			if (value == a.GetMS())
			{
				cout << current->index + 1 << " ";
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
	template<typename type1>
	void Output()
	{
		NodeList<type1>*current = head;
		while (current != nullptr)
		{
			cout << current->index + 1 << ":" << current->info << " ";
			current = current->next;
		}
		cout << endl;
	}

	template<>
	void Output<vector<int>>()
	{
		NodeList<vector<int>>*current = head;
		while (current != nullptr)
		{
			for (int i = 0; i < current->info.size(); i++)
				cout << current->info[i] << " ";
			cout << endl;
			current = current->next;
		}
		cout << endl;
	}

	template<>
	void Output<Dice>()
	{
		NodeList<Dice>*current = head;
		while (current != nullptr)
		{
			cout << "A" << current->info.GetBrinksNum() << ":" << current->info.GetMS() << " ";
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
	template<typename type1>
	void Delete(NodeList<type1>*current, type1 need)
	{
		current = head; NodeList<type1>*prev = head;
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

	template<>
	void Delete<vector<int>>(NodeList<vector<int>>*current, vector<int> need)
	{
		current = head; NodeList<vector<int>>*prev = head;
		while (current != nullptr)
		{
			bool b = true;
			for (int i = 0; i < current->info.size(); i++)
			{
				if (current->info[i] != need[i])
				{
					b = false;
				}
			}
			if (b)
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

	template<>
	void Delete<Dice>(NodeList<Dice>*current, Dice need)
	{
		current = head;
		NodeList<Dice>*prev = head;
		while (current != nullptr)
		{
			int tmp_ = (current->info.GetMS()) * 1000;
			double value;
			if (tmp_ % 10 > 5)
				value = double((tmp_ + 1) / 1000.0);
			else
				value = double(tmp_ / 1000.0);
			if (value == need.GetMS())
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
	template<typename type1>
	void Sort(N_aryTree<type1> &a, N_aryTree<type1> &b, int n)
	{
		vector<type1> c, d;
		NodeList<type1>* head = a.GetHead();
		while (head != nullptr)
		{
			c.push_back(head->info);
			head = head->next;
		}
		head = a.GetHead();
		vector<type1> c1;

		sort(c.begin(), c.end());
		if (!c.empty())
		{
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
				if (p != c.size())
				{
					while (N--) j++;
					if (++j == c1.end()) j = c1.begin();
				}
				N = n;
			}
		}

		int j = 0;
		for (auto i : c1)
		{
			b.AddLast(head, j++, i);
			if (head)head = head->prev;
		}
	}


	template<>
	void Sort<Dice>(N_aryTree<Dice> &a, N_aryTree<Dice> &b, int n)
	{
		vector<double> c, d;
		NodeList<Dice>* head = a.GetHead();
		while (head != nullptr)
		{
			c.push_back(head->info.GetMS());
			head = head->next;
		}
		head = a.GetHead();
		vector<double> c1;

		sort(c.begin(), c.end());
		if (!c.empty())
		{
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
				if (p != c.size())
				{
					while (N--) j++;
					if (++j == c1.end()) j = c1.begin();
				}
				N = n;
			}
		}

		int j = 0;
		for (auto i : c1)
		{
			b.AddLast(head, j++, i);
			if (head)head = head->prev;
		}
	}

};


