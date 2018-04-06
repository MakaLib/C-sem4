#pragma once
#include "Punkt.h"

class Kwadrat : public Punkt
{
public:
	Kwadrat(int bok);
	void wypisz(const std::ostream &output) const;
	double polePow() const;

private:
};
