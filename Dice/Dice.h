#pragma once
#include "pch.h"
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
	double* arrProbability; ///< Array of probabilities
public:
	Dice() ///< Constructor by default
	{
		MS = 0;
	}

	void GenerateProb();
	double GetMS();
	void SetMS(double MS);
	void SetBrinksNum(int brinksNum);
	int GetBrinksNum();
	double CountMS();
	void PrintProb();
};

