#include <iostream>
#include "Small.h"
#include "SetOfDice.h"


Small::Small() {
	int mas[3] = { 2, 4, 6 };

	for (int i = 0; i < 5; i++)
	{
		int a = rand() % 7;
		arrDice[i].SetBrinksNum(mas[a]);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Dice " << i + 1 << endl;
		arrDice[i].GenerateProb();
	}
}