//#include "pch.h"
#include <iostream>
#include "Dice.h"
#include "SetOfDice.h"

SetOfDice::SetOfDice()
{
	arrDice = new Dice[5];
}


Dice* SetOfDice::GetSetOfDice()
{
	return arrDice;
}

double SetOfDice::GetAmountMS()
{
	return amountMS;
}

void SetOfDice::SetAmountMS(double amountMS)
{
	this->amountMS = amountMS;
}

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

double SetOfDice::CountAmountMS()
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
\param n Quantity of dice
\param amount Amount
*/
void SetOfDice::Amounts()
{
	for (int i = 0; i < 5; i++)
		amount += arrDice[i].GetBrinksNum();
	for (int i = 5; i <= amount; i++)
		cout << i << " ";
}