#include "Kolo.h"
#include <iostream>

Kolo::Kolo(int x):Punkt(x)
{

}

void Kolo::wypisz(const std::ostream &output) const
{
	std::cout<<"Kolo o promienu: "<< Zwroc()<<"\n";
}

double Kolo::polePow() const
{
	return Zwroc() * Zwroc() * 3.1415;
}