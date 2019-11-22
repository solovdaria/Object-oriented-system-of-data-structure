#pragma once
#include "Dice.h"

class SetOfDice 
{
	int numOfDice;
	Dice*arrDice;
	double amountMS=0;
	int amount = 0;
public:
	SetOfDice();
	~SetOfDice();
	Dice*GetSetOfDice();
	void SetNumOfDice(int numOfDice);
	int GetNumOfDice();
	double GetAmountMS();
	void SetAmountMS(double amountMS);
	void GenerateDice();
	void CountAmountMS();
	void Amounts();
};
