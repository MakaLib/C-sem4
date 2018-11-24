#include "Array.h"
#include <iostream>


MyArray::MyArray(const int SIZE):size(Csize)
{
	Carray = new int [SIZE];
	Csize = SIZE;
	for(int row = 0; row < SIZE; row++)
	{
		Carray[row] = 0;
	}
}

MyArray::MyArray(const MyArray &array):size(Csize)
{
	Carray = new int[array.size];
	Csize = array.size;
	for(int row = 0; row < Csize; row++)
	{
		Carray[row] = array.Carray[row];
	}

}

int& MyArray::at(const int number) const
{
	return Carray[number];
}

void MyArray::print()
{
	std::cout<<"Array content:\n";
	for(int row = 0; row < Csize; row++)
	{
		std::cout<<"array["<<row<<"] = "<<Carray[row]<<"\n";
	}
}

void MyArray::resize(const int number)
{
	int *tab = new int [number];
	for(int row = 0; row < number; row++)
	{
		tab[row] = 0;
	}
	for(int row = 0; row < Csize; row++)
	{
		tab[row] = Carray[row];
	}
	delete [] Carray;
	Csize = number;
	Carray = tab;

}
MyArray::~MyArray()
{
	delete [] Carray;
}