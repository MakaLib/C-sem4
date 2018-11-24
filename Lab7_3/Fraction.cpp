#include "Fraction.h"

Fraction::Fraction(const int counter,const int denominator)
{
	up = counter;
	down = denominator;
}

void Fraction::Print()
{
	int times = up / down;
	if(times == 0)
	{
		std::cout<<up<<"/"<<down;
	}
	else 
	{
		std::cout<<times<<" "<<up%down<<"/"<<down;
	}
	std::cout<<"\n";
}

void Fraction::Add(Fraction first)
{
	up = up * first.down + down * first.up;
	down = down * first.down;
}
void Fraction::SetValue(const int nominator, const int denominator)
{
	up = nominator;
	down = denominator;
}