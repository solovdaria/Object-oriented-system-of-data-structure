#pragma once
#include "pch.h"
#include "node.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "N_aryTree.h"
using namespace std;

/*!
\brief Class of the dice

This class works with dice, it's values and probabilities of each value. Contains such functions
as searching for the biggest amount on two dice, creating arrays with probabilitis for dice, and
addition of the array of probabilities to the tree
*/
class Dice
{
	int brinksNum; ///< Quantity of brinks
	double MS;
	//int sum; ///< Amount of all but last value in the array
	double* arrProbability; ///< Array of probabilities
	//double* arr2; ///< Second dice array
	//double* arr_sum; ///< Created array which contains probabilities for each amount of dice
public:
	Dice() ///< Constructor by default
	{
		MS = 0;
	}

	//~Dice()
	//{
	//	delete[] arrProbability;
	//}

	void GenerateProb();
	double GetMS();
	void SetMS(double MS);
	void SetBrinksNum(int brinksNum);
	int GetBrinksNum();
	double CountMS();
	void PrintProb();

	/*	~Dice() ///< Destructor, deletes arrays
		{
			delete[] arr1;
			delete[] arr2;
			delete[] arr_sum;
		}*/
		/*int AllSum(int N1, int N2);
		void SumArr(int size1, int size2);
		void Arrays(int N1, int N2);
		void SumToBinarySearchTree(BinarySearchTree<double>* my, Dice cybic, int N1, int N2);
		void SumToBinaryTree(BinaryTree<double>* my, Dice cybic, int N1, int N2);
		void SumToN_aryTree(N_aryTree<double>* my, Dice cybic, int N1, int N2);*/
};

