#pragma once

class Angle
{
public:
	explicit Angle(const double rad);
	double rad() const;
	double deg() const;
	double& deg();
	operator double() const;
	static Angle distance(double first, double second);

private:
	double deg_angle;
	

};