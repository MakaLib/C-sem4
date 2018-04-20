#pragma once

#include "Drukarka.h"
#include "Ksero.h"
#include "Skaner.h"

class Wielofunkcyjne : public Drukarka, public Ksero, public Skaner
{
public:
	Wielofunkcyjne(const Rozdzielczosc &roz1, const Rozdzielczosc &roz2)
	:Urzadzenie("Wielofunkcyjne"),Drukarka(roz1),Ksero(roz1),Skaner(roz2)
	{

	};


/*	std::string rodzaj() const
	{
		return U_nazwa;
	};*/



};