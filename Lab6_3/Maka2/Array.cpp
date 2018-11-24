#include "Main.h"
#include <iostream>

Array& CreateArray (const int *size1,const int size2)
{
	Array *start = new Array;
	start->str_rows = size2;
	start->wsk = new int *[size2];
	start->str_columns = new int [size2];
	for(int row = 0; row<size2; row++)
	{
		start->wsk[row] = new int [size1[row]];
		start->str_columns[row] = size1[row];
	}
	return *start;

	
}

void FillWith(Array firstArray,const int value)
{
	for(int row = 0; row < firstArray.str_rows; row++)
	{
		for(int column = 0; column < firstArray.str_columns[row]; column++)
		{
			firstArray.wsk[row][column] = value;
		}
	}
	
}

void Print (Array firstArray)
{
	for(int row = 0; row < firstArray.str_rows; row++)
	{
		for(int column = 0; column < firstArray.str_columns[row]; column++)
		{
			std::cout<<firstArray.wsk[row][column]<<" ";
		}
		std::cout<<"\n";
	}
}

void SetElement(const int row,const int column, Array *firstArray,const int value)
{
	if(row < (firstArray)->str_rows && column < (firstArray)->str_columns[row])
	{
		(firstArray)->wsk[row][column] = value;
	}
	else std::cout<<"Index out of bounds\n";
}

void  PrintMax (Array firstArray)
{
		std::cout<<"Maximum\n";
	int global = firstArray.wsk[0][0];
	for(int row = 0; row < firstArray.str_rows; row++)
	{
		int local = firstArray.wsk[row][0];
		for(int column = 1; column < firstArray.str_columns[row]; column++)
		{
			if(local < firstArray.wsk[row][column]) local = firstArray.wsk[row][column];
		}
		std::cout<<"Maximum "<<row<<": "<<local<<"\n";
		if(global < local) global = local;
	}
	std::cout<<"Global Maximum: "<<global<<"\n";	

}

void Clear (Array &firstArray)
{
	int check = firstArray.str_rows;
	for(int rows = 0; rows < check; rows++)
	{
		delete [] firstArray.wsk[rows];
	}
	delete [] firstArray.str_columns;
	delete [] firstArray.wsk;
	delete &firstArray;
}