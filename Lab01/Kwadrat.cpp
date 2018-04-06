#include "Kwadrat.h"
#include <iostream>
#include <cmath>

Kwadrat::Kwadrat(int bok):Punkt(bok)
{

}

void Kwadrat::wypisz(const std::ostream &output) const
{
	std::cout<<"Kwadrat o boku: "<<Zwroc()<<"\n";
}

double Kwadrat::polePow() const
{
	return Zwroc() * Zwroc();
}