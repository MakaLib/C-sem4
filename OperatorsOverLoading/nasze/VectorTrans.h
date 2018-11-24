#pragma once
#include "Vector.h"
#include "Matrix.h"

class VectorTrans
{
public:
	friend std::ostream& operator<< (std::ostream& output, const VectorTrans& trans);
	VectorTrans(const int size);
	int& operator[](const int row);
	int operator[] (const int row) const;
	Matrix operator*(const Vector& vector);
	~VectorTrans();

private:
	int *VT_array;
	int VT_size;
};

