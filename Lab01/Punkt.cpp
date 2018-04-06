#include "Punkt.h"


void wypisz(const Punkt *object)
{
	object->wypisz(std::cout);
}

void wypisz(const Punkt &object)
{
	object.wypisz(std::cout);
}

Punkt::Punkt(int x):P_x(x)
{

}

int Punkt::Zwroc() const
{
	return P_x;
}

Punkt::~Punkt()
{
	
}