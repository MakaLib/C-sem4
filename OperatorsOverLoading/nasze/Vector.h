#pragma once
#include <iostream>
class VectorTrans;

class Vector
{
public:
	friend std::ostream& operator<<(std::ostream& output, const Vector& vec);
	friend class VectorTrans;
	Vector(const int size = 3);
	Vector(const Vector& vec);
	int operator[](const int row) const;
	int& operator[](const int row);
	int operator* (const VectorTrans& trans) const;
	Vector& operator=(const Vector& vector);
	~Vector();

private:
	int *V_array;
	int V_size;
};

