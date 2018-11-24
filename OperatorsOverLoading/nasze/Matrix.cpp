#include "Matrix.h"

std::ostream& operator<< (std::ostream& output, const Matrix& array)
{
	for(int i = 0; i < array.M_size; i++)
	{
		output << array.M_array[i]<<"\n";
	}
	return output;
}

Matrix::Matrix(const int size)
{
	M_size = size;
	M_array = new Vector [size];
	
}


Matrix::~Matrix()
{
	delete [] M_array;
}