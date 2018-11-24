#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


class Fraction
{
	friend class FractionArray;
public:
	Fraction( const int, const int);
	void Print();
	Fraction Add(Fraction);
	

private:
	int up;
	int down;
};

#endif