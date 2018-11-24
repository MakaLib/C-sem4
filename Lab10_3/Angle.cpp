#include "Angle.h"
#include <iostream>



Angle::Angle(const double rad)
{

		double rad_change = rad;
		while(rad_change > 2 * M_PI ) rad_change -= 2*M_PI;
		while(rad_change < 0) rad_change += 2*M_PI;
		angle = rad_change * 180 / M_PI;
}



double Angle::GetAngle() const
{
	return angle;
}

Angle Angle::fromRadians(const double rad)
{

	Angle first(rad);
	return first;
}

Angle Angle::fromDegrees(const double deg)
{
	Angle first(deg * M_PI /180);
	return first;
}

Angle::operator double() const
{
	return angle;
}

Angle& Angle::add(double deg)
{
	this->angle += deg;
	if(angle > 360)
	{
		while(angle > 360) angle -= 360;
	}

	return *this;
}

double Angle::toDeg() const
{
	
	return angle;
}

double Angle::toRad() const
{
	
	return angle * M_PI / 180;
}

Angle Angle::distance(double first, double second)
{
	if(first<second) 
		{
			Angle third((first - second) * M_PI / 180);
			return third;
		}
	else 
		{
			Angle third((second - first) * M_PI / 180);
			return third;
		}
		
	
}
