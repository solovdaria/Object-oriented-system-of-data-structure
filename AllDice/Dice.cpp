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

void Dice::PrintProb() ///<Function for the outputing probabilities
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

double Dice::GetProb(int i) ///< Getter for probability with i index in the array of prababilities
{
	return arrProbability[i];
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



