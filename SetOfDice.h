#pragma once
#include "Dice.h"

class SetOfDice 
{
	const int numOfDice=5;
	Dice*arrDice;
	double amountMS=0;
	int amount = 0;
public:
	SetOfDice();
	~SetOfDice();
	Dice*GetSetOfDice();
	double GetAmountMS();
	void SetAmountMS(double amountMS);
	void GenerateDice();
	void CountAmountMS();
	void Amounts();
};
