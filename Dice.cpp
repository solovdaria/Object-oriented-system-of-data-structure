//#include "pch.h"
#include <iostream>
#include "Dice.h"


Dice::Dice() ///< Constructor by default
{
	MS = 0;
}

/*!
\brief Function for counting mathematic expectation
\param MS Mathematic expectation
\return Mathematic expectation
*/
void Dice::CountMS()
{
	for (int i = 0; i < brinksNum; i++)
	{
		MS += (i+1) * arrProbability[i];
	}
}

/*!
\brief Function for the outputing probabilities
*/
void Dice::PrintProb()
{
	for (int i = 0; i < brinksNum; i++)
	{
		cout << i + 1 << " : " << arrProbability[i] << "  ";
	}
	cout << endl;
}

/*!
\brief Function for generating probabilities
\param arrProbability Array with probabilities
\param sum Parametr that need to count last brink probability
*/
void Dice::GenerateProb()
{
	arrProbability = new double[brinksNum];
	double sum = 0;
	for (int i = 0; i < brinksNum; i++)
	{
		arrProbability[i] = (1 + rand() % (100 / brinksNum)) * 0.01;
		sum += arrProbability[i];
	}
	if (sum >= 1) arrProbability[brinksNum - 1] = 0;
	else arrProbability[brinksNum - 1] = 1 - sum;
}

double Dice::GetMS() ///< Getter for MS
{
	return MS;
}

void Dice::SetMS(double MS) ///< Setter for MS
{
	this->MS = MS;
}

void Dice::SetBrinksNum(int brinksNum) ///< Setter for BrinksNum
{
	this->brinksNum = brinksNum;
}

int Dice::GetBrinksNum() ///< Getter for BrinksNum
{
	return brinksNum;
}



/*!
\brief The biggest possible amount on two dice
Summarizes array sizes
\param N1 Size of first array, that means the biggest value on the first dice
\param N2 Size of second array, that means the biggest value on the second dice
\return Maximal possible amount on dice
*/
/*int Dice::AllSum(int N1, int N2)
{
	maxSum = N1 + N2;
	return maxSum;
}*/

//void shit()
//{
//	int n;
//	cin >> n;
//	int *arrN = new int[n];
//	double **arr = new double*[n];
//	for (size_t i = 0; i < n; i++)
//	{
//		int k;
//		cin >> k;
//		arrN[i] = k;
//		arr[i] = new double[k];
//		for (size_t j = 0; j < k; j++)
//		{
//			arr[i][j] = 1 / (rand() % 10 + 1);
//		}
//	}
//
//}

/*!
\brief From two arrays of dice's values probabilities creates array, which indexes + 2
means amount of arrays, and values means probability of it's amount
First step is inputing multiplication of two values (probabilities) in arrays in case amount of
it's indeces = index of created array. Second step is comparisom of two values in arrays (probabilities
on dice) and output received
\param size1 Size of first array (biggest value on dice)
\param size2 Size of second array (biggest value on dice)
\param size Size of created array (size1 + size2 - 1)
*/
/*void Dice::SumArr(int size1, int size2)
{
	size = size1 + size2 - 1;
	arr_sum = new double[size]; ///< Creating array
	for (sum = 0; sum < size; sum++) arr_sum[sum] = 0; ///< Input 0 into the created array
	for (sum = 0; sum < size; sum++)
	{
		for (int i = 0; i <= sum && i < size1; i++)
		{
			for (int j = 0; j <= sum && j < size2; j++)
			{
				if (sum == i + j) arr_sum[sum] += arr1[i] * arr2[j];
			}
		}
	}
	for (sum = 0; sum < size; sum++)
	{
		cout << "Probability of summ " << sum + 2 << " = " << arr_sum[sum] << endl;
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (i == j)
			{
				if (arr1[i] > arr2[j]) cout << "Probability of " << i + 1 << " on first > than probability of " << j + 1 << " on second" << endl;
				else if (arr1[i] < arr2[j]) cout << "Probability of " << i + 1 << " on first < than probability of " << j + 1 << " on second" << endl;
				else cout << "Probability of " << i + 1 << " on first = probability of " << j + 1 << " on second" << endl;
			}
		}
	}
}*/

/*!
Creating two arrays, values in which are responsible for probabilities of values on dice.
Using function SumArr to work with them
\param N1 Size of first array (maximal value on dice)
\param N2 Size of second array (maximal value on dice)
\param summa Is amount of all but last value
*/
/*void Dice::Arrays(int N1, int N2)
{
	double summa = 0;
	arr1 = new double[N1];
	arr2 = new double[N2];
	for (int i = 0; i < N1 - 1; i++)
	{
		cout << "Enter probability of " << i + 1 << ": ";
		cin >> arr1[i];
		summa += arr1[i];
	}
	if (summa > 1) summa = 1;
	arr1[N1 - 1] = 1 - summa;
	cout << "Probability of " << N1 << " = " << arr1[N1 - 1] << endl;
	summa = 0;
	for (int j = 0; j < N2 - 1; j++)
	{
		cout << "Enter probability of " << j + 1 << ": ";
		cin >> arr2[j];
		summa += arr2[j];
	}
	if (summa > 1) summa = 1;
	arr2[N2 - 1] = 1 - summa;
	cout << "Probability of " << N2 << " = " << arr2[N2 - 1] << endl;
	SumArr(N1, N2);
}
*/
/*!
Input last array to the BST tree
\param my Is a variable of class BinarySearchTree
\param cybic Is a variable of class Dice
\paran N1 Size of first array
\param N2 Size of second array
\param k Index
*/
/*void Dice::SumToBinarySearchTree(BinarySearchTree<double>* my, Dice cybic, int N1, int N2)
{
	for (int k = 0; k < N1 + N2 - 1; k++)
	{
		my->Input(my->GetTree(), k, cybic.arr_sum[k]);
	}
}*/

/*!
Input last array to the BT tree
\param my Is a variable of class BinaryTree
\param cybic Is a variable of class Dice
\paran N1 Size of first array
\param N2 Size of second array
\param k Index
*/
/*void Dice::SumToBinaryTree(BinaryTree<double>* my, Dice cybic, int N1, int N2)
{
	for (int k = 0; k < N1 + N2 - 1; k++)
	{
		my->Input(my->GetTree(), k, cybic.arr_sum[k]);
	}
}*/

/*!
Input last array to the n-ary tree
\param my Is a variable of class N_aryTree
\param cybic Is a variable of class Dice
\paran N1 Size of first array
\param N2 Size of second array
\param k Index
*/
/*void Dice::SumToN_aryTree(N_aryTree<double>* my, Dice cybic, int N1, int N2)
{
	for (int k = 0; k < N1 + N2 - 1; k++)
	{
		my->AddLast(my->GetList(), k, cybic.arr_sum[k]);
	}
}*/
