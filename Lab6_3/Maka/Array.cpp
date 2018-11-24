#include "Main.h"


void CreateArray (Array*& firstArray, const int *size1,const int size2)
{
	

	firstArray = new int **;
	(*firstArray) = new int *[size2+1];
	(*firstArray)[0] = new int [1];
	(*firstArray)[0][0] = size2; 
	for(int rows = 0; rows < size2; rows++)
	{
		(*firstArray)[rows+1] = new int [size1[rows] + 1];
		(*firstArray)[rows+1][0] = size1[rows];
		
	}
	


}

void FillWith(Array*& firstArray, const int value)
{
	
	
	for(int rows = 1; rows <= (*firstArray)[0][0]; rows++)
	{
		for(int columns = 1; columns <= (*firstArray)[rows][0]; columns++)
		{
			(*firstArray)[rows][columns] = value;
		}
		
	}


}

void Print (Array firstArray)
{
	for(int rows = 1; rows <= firstArray[0][0]; rows++)
	{
		for(int columns = 1; columns <= firstArray[rows][0]; columns++)
		{
			std::cout<<firstArray[rows][columns]<<" ";
		}
		std::cout << "\n";
	}

}

void PrintMax (Array *firstArray)
{
	int global = (*firstArray)[1][1];
	std::cout<<"Maximum\n";
	for(int rows = 1; rows <= (*firstArray)[0][0]; rows++)
	{
		int local = (*firstArray)[rows][1];
		for(int columns = 2; columns<= (*firstArray)[rows][0]; columns++ )
		{
			if(local < (*firstArray)[rows][columns]) local = (*firstArray)[rows][columns];
		}
		std::cout<<"Maxiumum "<<rows-1<<": "<<local<<"\n";
		if(global < local) global = local;
	}
	std::cout<<"Global Max: "<<global<<"\n";

}

void SetElement(const int row, const int column, Array **firstArray, const int value)
{
	if(row < (**firstArray)[0][0] && column < (**firstArray)[row+1][0])
	{
		(**firstArray)[row+1][column+1] = value;	
	}
	else std::cout<<"Index out of bounds\n";
	
}

void Clear (Array **firstArray)
{
	int check = (**firstArray)[0][0];
	for(int rows = 0; rows <= check; rows++)
	{
		delete [] (**firstArray)[rows];
	}
	delete [] (**firstArray);
	delete *firstArray;
}