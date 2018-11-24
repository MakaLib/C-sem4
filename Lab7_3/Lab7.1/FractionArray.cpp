#include "FractionArray.h"

FractionArray::FractionArray(const int size)
{
	array = new Fraction *[size];
	how_many = 0;
}

void FractionArray::AddFration(const int x, const int y)
{
	array[how_many] = new Fraction(x,y);
	how_many++;

}

Fraction FractionArray::Sum()
{
	Fraction sums(1,1);
	
	int numerator = array[0]->up;
	int denominatr = array[0]->down;

	for(int row = 1; row < how_many; row++)
	{
		numerator = numerator * array[row]->down + denominatr * array[row]->up;
		denominatr = denominatr * array[row]->down;
	}

	sums.up = numerator;
	sums.down = denominatr;

	return sums;
}

void FractionArray::Print()
{
	for(int row = 0; row < how_many; row++)
	{
		std::cout<<row<<": ";
		array[row]->Print();
	}
}

FractionArray::~FractionArray()
{
	for(int row = 0; row < how_many; row++)
	{
		delete array[row];
	}
	delete [] array;
	how_many = 0;
}
