#pragma once
#include "Vector.h"

class Matrix
{
public:
	friend std::ostream& operator<< (std::ostream& output, const Matrix& array);
	friend class VectorTrans;
	Matrix(const int size);
	~Matrix();
private:
	int M_size;
	Vector *M_array;
};

