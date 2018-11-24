#include "VectorTrans.h"

VectorTrans::VectorTrans(const int size)
{
	VT_size = size;
	VT_array = new int [size];

}

int& VectorTrans::operator[](const int row)
{
	return VT_array[row];
}

int VectorTrans::operator[] (const int row) const
{
	return VT_array[row];
}

VectorTrans::~VectorTrans()
{
	delete [] VT_array;
}

Matrix VectorTrans::operator*(const Vector& vector)
{
	Matrix matrix(VT_size);
	for(int i = 0; i < VT_size; i++)
	{
		Vector new_vector(VT_size);
		for(int k = 0; k < VT_size; k++)
		{
			new_vector[k] = vector[k] * VT_array[i];

		}

		matrix.M_array[i] = new_vector;
	}
		return matrix;

}

std::ostream& operator<< (std::ostream& output, const VectorTrans& trans)
{
	for(int i = 0; i < trans.VT_size; i++)
	{
		output <<"["<<trans.VT_array[i]<<"]\n";
	}
	return output;
}