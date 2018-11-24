#include "Point3D.h"


std::ostream& operator<< (std::ostream& output, const Point3D& point)
{
	return output <<"("<<point.P_point[0]<<", "<<point.P_point[1]<<", "<<point.P_point[2]<<")";
}

Point3D::Point3D(const double xPoint, const double yPoint, const double zPoint)
{
	P_point[0] = xPoint;
	P_point[1] = yPoint;
	P_point[2] = zPoint;
}


double Point3D::operator[](const count choose) const
{
	switch(choose)
	{
		case Point3D::X:
			return P_point[0];
		case Point3D::Y:
			return P_point[1];
		case Point3D::Z:
			return P_point[2];
		default: 
			return P_point[0];
	}
}


double& Point3D::operator[](const count choose)
{
	switch(choose)
	{
		case Point3D::X:
			return P_point[0];
		case Point3D::Y:
			return P_point[1];
		case Point3D::Z:
			return P_point[2];
		default: 
			return P_point[0];
	}
}



double Point3D::GetX() const
{
	return P_point[0];
}

double Point3D::GetY() const
{
	return P_point[1];
}

double Point3D::GetZ() const
{
	return P_point[2];
}