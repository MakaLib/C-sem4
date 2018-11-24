#include "Fraction.h"

Fraction::Fraction(const int x, const int y)
{
	up = x;
	down = y;
}

void Fraction::Print()
{
	int times = up/down;
	if(times == 0)
	{
		std::cout <<up<<"/"<<down;
	}
	else 
	{
		std::cout<<times<<" "<<up%down<<"/"<<down;
	}
	std::cout<<"\n";
}

Fraction Fraction::Add(Fraction first)
{
	first.up = first.up * down + up * first.down;
	first.down = down * first.down;
	return first;

}