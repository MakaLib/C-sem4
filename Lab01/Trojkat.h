#pragma once
#include "Punkt.h"

class Trojkat: public Punkt
{
public:
	Trojkat(int x, int y, int z);
	void wypisz(const std::ostream &output) const;
	double polePow() const;

private:
	int P_y;
	int P_z;
};