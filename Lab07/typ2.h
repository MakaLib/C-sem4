#pragma once

#include <iostream>
#include "typ4.h"

class typ2
{
public:
	void PrzedstawSie()
	{
		std::cout<<"Nazywam sie 2\n";
	};
};


void Przetworz( typ2 *wyjatek)
{
	std::cout<<"Przetworz - wyjatek typu 1 o adresie: "<<wyjatek<<"\n";
	

	throw reinterpret_cast<typ4 *>(wyjatek);
}