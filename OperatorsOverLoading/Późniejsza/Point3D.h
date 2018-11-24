#pragma once
#include <iostream>


class Point3D
{
public:
	friend std::ostream& operator<< (std::ostream& output, const Point3D& point);
	Point3D(const double xPoint, const double yPoint, const double zPoint);
	double GetX() const;
	double GetY() const;
	double GetZ() const;

	enum count {X ,Y, Z};
	double operator[](const count choose) const;
	double& operator[](const count choose);
	
 	




private:
	double P_point[3];

};

