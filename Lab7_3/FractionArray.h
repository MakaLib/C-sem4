#ifndef FRACTION_ARRAY_H
#define FRACTION_ARRAY_H
#include <iostream>
#include "Fraction.h"

class FractionArray
{
public:
	FractionArray(const int = 0);
	Fraction Sum();
	void Print();
	void AddFration(Fraction&);
	~FractionArray();

private:
	Fraction **array;
	int sum_up;
	int sum_down;
	int how_many;

};

#endif