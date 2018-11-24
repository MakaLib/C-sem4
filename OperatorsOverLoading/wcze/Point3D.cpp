#include "Point3D.h"

Point3D::Point3D(const int x, const int y, const int z)
{
	P_x = x;
	P_y = y;
	P_z = z;
}

int Point3D::GetX() const
{
	return P_x;
}

int Point3D::GetY() const
{
	return P_y;
}

int Point3D::GetZ() const
{
	return P_z;
}
