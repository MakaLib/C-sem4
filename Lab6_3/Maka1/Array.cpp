#include "Main.h"
#include <iostream>

int**& CreateArray (const int *size1,const int size2)
{
	int ***new_one = new int **;
	*new_one = new int *[size2 + 1];
	(*new_one)[0] = new int [1];
	(*new_one)[0][0] = size2;
	for(int row = 0; row < size2; row++)
	{
		(*new_one)[row+1] = new int [size1[row] + 1];
		(*new_one)[row+1][0] = size1[row]; 
	}
	
	return *new_one;
	

}

void FillWith(Array firstArray,const int value)
{
	for(int row = 1; row <= firstArray[0][0]; row++)
	{
		for(int column = 1; column <= firstArray[row][0]; column++)
		{
			firstArray[row][column] = value;
		}
	}
}

void Print (Array firstArray)
{
	for(int row = 1; row <= firstArray[0][0]; row++)
	{
		for(int column = 1; column <= firstArray[row][0]; column++)
		{
			std::cout<<firstArray[row][column]<<" ";
		}
		std::cout<<"\n";
	}
}

void SetElement(const int row,const int column, Array *firstArray,const int value)
{
	if(row < (*firstArray)[0][0] && column < (*firstArray)[row+1][0])
	{
		(*firstArray)[row+1][column+1] = value;
	}
	else std::cout<<"Index out of bounds\n";
}

void  PrintMax (Array firstArray)
{
	std::cout<<"Maximum\n";
	int global = firstArray[1][1];
	for(int row = 1; row <= firstArray[0][0]; row++)
	{
		int local = firstArray[row][1];
		for(int column = 2; column <= firstArray[row][0]; column++)
		{
			if(local < firstArray[row][column]) local = firstArray[row][column];
		}
		std::cout<<"Maximum "<<row-1<<": "<<local<<"\n";
		if(global < local) global = local;
	}
	std::cout<<"Global Maximum: "<<global<<"\n";

}

void Clear (Array &firstArray)
{
	int ammount_of_rows = firstArray[0][0];
	for(int row = 0; row <= ammount_of_rows; row++)
	{
		delete [] firstArray[row];
	}
	delete [] firstArray;
	delete &firstArray;

}