#include "pch.h"
#include "Dice.h"
#include "SetOfDice.h"

SetOfDice::SetOfDice()
{
	arrDice = new Dice[numOfDice];
}

SetOfDice::~SetOfDice()
{
}

Dice* SetOfDice::GetSetOfDice()
{
	return arrDice;
}

void SetOfDice::SetNumOfDice(int numOfDice)
{
	this->numOfDice = numOfDice;
}

int SetOfDice::GetNumOfDice()
{
	return numOfDice;
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

	for (int i = 0; i < numOfDice; i++)
	{
		int a = rand() % 7;
		arrDice[i].SetBrinksNum(mas[a]);
	}
	for (int i = 0; i < numOfDice; i++)
		arrDice[i].GenerateProb();
}

void SetOfDice::CountAmountMS()
{
	for (int i = 0; i < numOfDice; i++)
		arrDice[i].CountMS();
	for (int i = 0; i < numOfDice; i++)
	{
		amountMS += arrDice[i].GetMS();
	}
}

/*!
\brief Amount on n dice

Summarizes array sizes
\param n Quantity of dice
\param amount Amount
*/
void SetOfDice::Amounts()
{
	for (int i = 0; i < numOfDice; i++)
		amount += arrDice[i].GetBrinksNum();
	for (int i = numOfDice; i <= amount; i++)
		cout << i << " ";
}



