#include "FractionArray.h"

FractionArray::FractionArray(const int size)
{
	array = new Fraction *[size+1];
	how_many = 0;


}
FractionArray::~FractionArray()
{	
	delete array[how_many];
	delete [] array;
	how_many = 0;
}
Fraction FractionArray::Sum()
{
	array[how_many] = new Fraction (1,1);
	int nominator = array[0]->up;
	int denominator = array[0]->down;
	int count;
	for(count = 1; count < how_many; count++)
	{
		nominator = nominator * array[count]->down + denominator * array[count]->up;
		denominator = denominator * array[count]->down;
	}
	array[how_many]->up = nominator;
	array[how_many]->down = denominator;
	return *array[how_many];
}

void FractionArray::Print()
{
	for(int row = 0; row < how_many; row++)
	{
		std::cout<<row<<":  ";
		array[row]->Print();
	}
}
void FractionArray::AddFration(Fraction &first)
{

	array[how_many] = &first;
	how_many++;
}