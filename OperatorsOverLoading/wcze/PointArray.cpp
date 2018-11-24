#include "PointArray.h"

PointArray::PointArray (const int size, const Point3D& point)
{
	PA_size = size;
	PA_array = new Point3D *[PA_size];
	for(int i = 0; i < PA_size; i++)
	{
		PA_array[i] = new Point3D (point.GetX(), point.GetY(), point.GetY());
	}
}

PointArray::PointArray (const PointArray& array)
{
	PA_size = array.PA_size;
}

void PointArray::Print() const
{

}

Point3D*& PointArray::operator[](const int row)
{
	return *PA_array[row];
}

bool PointArray::operator==(const PointArray& array) const
{

}

PointArray& PointArray::operator=(const PointArray& array)
{

}
