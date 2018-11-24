#pragma once
#include <iostream>

class Point3D
{
public:
	friend std::ostream& operator<< (std::ostream& wyjscie, const Point3D& point);

	Point3D(const int x, const int y, const int z);
	int GetX() const;
	int GetY() const;
	int GetZ() const;
private:
	int P_x;
	int P_y;
	int P_z;
};

std::ostream& operator<<(std::ostream& wyjscie, const Point3D& point)
{
	return wyjscie<<"("<<point.P_x<<", "<<point.P_y<<", "<<point.P_z<<")";
}