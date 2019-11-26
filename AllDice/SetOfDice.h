#pragma once
#include "Dice.h"
#include <vector>

class SetOfDice
{
	Dice*arrDice; ///< Array of dice in set
	double amountMS = 0; ///< Amount of maths expectations
	int amount = 0; ///< Amount of brinks 
public:
	SetOfDice();
	Dice* GetSetOfDice();
	double GetAmountMS();
	void SetAmountMS(double amountMS);
	void GenerateDice();
	double CountAmountMS();
	void Amounts();
};
