//#include "pch.h"
#include <iostream>
#include "Dice.h"
#include "SetOfDice.h"

SetOfDice::SetOfDice() ///<Constructor by default
{
	arrDice = new Dice[5];
}

double SetOfDice::GetAmountMS() ///< Maths expectation getter
{
	return amountMS;
}

void SetOfDice::SetAmountMS(double amountMS) ///< Maths expectation setter
{
	this->amountMS = amountMS;
}

/*!
\brief Dice generation

Generate dice in the set
\param mas Array of probable quantities of bricks
*/
void SetOfDice::GenerateDice()
{
	int mas[7] = { 2, 4, 6, 8, 10, 12, 20 };

	for (int i = 0; i < 5; i++)
	{
		int a = rand() % 7;
		arrDice[i].SetBrinksNum(mas[a]);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Dice " << i + 1 << endl;
		arrDice[i].GenerateProb();
		arrDice[i].PrintProb();
	}
}

double SetOfDice::CountAmountMS() ///< Counts amount of maths expectation for set
{
		for (int i = 0; i < 5; i++)
		{
			arrDice[i].CountMS();
		}
		for (int i = 0; i < 5; i++) amountMS += arrDice[i].GetMS();
	return amountMS;
}

/*!
\brief Amount on n dice

Summarizes array sizes
\param amount Amount
*/
void SetOfDice::Amounts()
{
	for (int i = 0; i < 5; i++)
		amount += arrDice[i].GetBrinksNum();

	/* double* arr = new double[amount-4];

	for (int i = 0; i < amount-4; i++)
	{
		arr[i] = (arrDice[0].GetProb(0)) * (arrDice[1].GetProb(0)) * (arrDice[2].GetProb(0)) *
			(arrDice[3].GetProb(0)) * (arrDice[4].GetProb(i+5));
	}*/
	for (int i = 0; i < amount-4; i++)
		cout << i+5 <<" ";
}