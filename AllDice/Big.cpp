#include <iostream>
#include "Big.h"
#include "SetOfDice.h"

Big::Big() {
	int mas[4] = { 8, 10, 12, 20 };

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