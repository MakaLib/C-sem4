#ifndef FRACTION_ARRAY_H
#define FRACTION_ARRAY_H
#include <iostream>
#include "Fraction.h"

class FractionArray
{
public:
	FractionArray(const int);
	Fraction Sum();
	void Print();
	void AddFration(const int, const int);
	~FractionArray();

private:
	Fraction **array;
	int how_many;

};

#endif