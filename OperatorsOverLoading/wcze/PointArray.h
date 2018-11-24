#pragma once
#include "Point3D.h"

class PointArray
{
public:
	PointArray (const int size, const Point3D& point);
	PointArray (const PointArray& array);
	void Print() const;
	Point3D*& operator[](const int row);
	bool operator==(const PointArray& array) const;
	PointArray& operator=(const PointArray& array);

private:
	Point3D **PA_array;
	int PA_size;
};