#include "Vector.h"
#include "VectorTrans.h"

Vector::Vector(const int size)
{
	V_size = size;
	V_array = new int [size];
}

Vector::Vector(const Vector& vec)
{
	V_size = vec.V_size;
	V_array = new int [V_size];
	for(int i = 0; i < V_size; i++)
	{
		V_array[i] = vec.V_array[i];
	}
}

int& Vector::operator[](const int row)
{
	return V_array[row];
}

int Vector::operator[](const int row) const
{
	return V_array[row];
}

int Vector::operator* (const VectorTrans& trans) const
{
	int sum = 0;
	for(int i = 0; i < V_size; i++)
	{
		sum += V_array[i] * trans[i];
	}
	return sum;
}

Vector::~Vector()
{
	V_size = 0;
	delete [] V_array;
}

Vector& Vector::operator=(const Vector& vector)
{
	if(this == &vector) return *this;
	delete [] V_array;
	V_size = vector.V_size;
	V_array = new int [V_size];
	for(int i = 0; i < V_size; i++)
	{
		V_array[i] = vector.V_array[i];
	}
	return *this;
}

std::ostream& operator<< (std::ostream& output, const Vector& vec)
{
	output<<"[";
	for(int i = 0; i < vec.V_size; i++)
	{	
		if(i < vec.V_size - 1)
			output<<vec.V_array[i]<<", ";
		else
			output<<vec.V_array[i];

	}
	output<<"]";
	return output;
}