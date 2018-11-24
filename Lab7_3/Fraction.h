#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


class Fraction
{
	friend class FractionArray;
public:
	Fraction( const int, const int);
	void Print();
	void Add(Fraction);
	void SetValue(const int, const int);

private:
	int up;
	int down;
};

#endif