#include "Angle.h"
#include <iostream>
#include <cmath>

// Zamiana radianow na stopnie:
// radian = stopnie * PI / 180

// Zamiana stopni na radiany:
// stopnie = radian * 180 / PI

Angle::Angle(double deg, double rad)
{
	while(deg > 360) deg-=360;
	while(deg < 0) deg += 360;

	while(rad > 2 * M_PI) rad -= 2 * M_PI;
	while(rad < 0) rad += 2 * M_PI;

	radian = rad;
	degree = deg;
}

double Angle::toRad() const
{
	return radian;
}

double Angle::toDeg() const
{
	return degree;
}

Angle& Angle::add(double deg)
{
	this->degree += deg;
	while(degree > 360) degree -=360;
	while(degree < 0) degree += 360;

	this->radian = degree * M_PI/ 180;

	return *this;

}

Angle::operator double() const
{
	return degree;
}

Angle Angle::distance(const double angl1, const double angl2)
{
	if(angl1 < angl2)
	{
		Angle third(angl1 - angl2, (angl1 - angl2) * M_PI / 180);
		return third;
	}
	else
	{
		Angle third(angl2-angl1,(angl2 - angl1) * M_PI / 180);
		return third;
	}
}
Angle Angle::fromRadians(const double angl)
{
	double rad = angl;
		while(rad > 2*M_PI) rad -= 2*M_PI;
		while(rad < 0) rad += 2 * M_PI;
	Angle new_one(rad * 180 /M_PI, rad);
	return new_one;
}
Angle Angle::fromDegrees(const double angl)
{
	double rad = angl;
	
		
		while(rad > 360) rad -= 360;
	
	
		
		while(rad < 0) rad += 360;
	
	Angle new_one(rad, rad * M_PI / 180);
	return new_one;

}