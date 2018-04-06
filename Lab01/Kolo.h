#pragma once
#include "Punkt.h"

class Kolo: public Punkt
{
public:
	Kolo(int x);
	void wypisz(const std::ostream &output) const;
	double polePow() const;
};