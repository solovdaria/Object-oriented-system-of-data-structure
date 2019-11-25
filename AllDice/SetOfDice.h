#pragma once
#include "Dice.h"
#include <vector>

class SetOfDice
{
//	const int numOfDice = 5;
	Dice*arrDice;
	double amountMS = 0;
	int amount = 0;
public:
	SetOfDice();
	Dice* GetSetOfDice();
	double GetAmountMS();
	void SetAmountMS(double amountMS);
	void GenerateDice();
	double CountAmountMS();
	void Amounts();
};
