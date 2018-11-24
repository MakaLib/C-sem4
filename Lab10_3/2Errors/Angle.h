#pragma once


class Angle
{
public:
	Angle(double deg, double rad);
	double toRad() const;
	double toDeg() const;
	Angle& add(double deg);
	operator double() const;

	static Angle distance(const double angl1, const double angl2);
	static Angle fromRadians(const double angl);
	static Angle fromDegrees(const double angl);


private:
	double degree;
	double radian;
	
};