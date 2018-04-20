#pragma once
#include "Lozko.h"

class Lozko : public virtual Mebel
{
public:
	Lozko(const int sz, const int wys, const int dl, const int spac)
	:Mebel(sz,wys,dl), L_spanie(spac)
	{

	};

	virtual std::ostream& wypisz(std::ostream& out) const
	{
		out<<"Lozko: ";
		Mebel::wypisz(out);
		out<<" sz.spania: "<<L_spanie;
		return out;
	}

	~Lozko()
	{
		std::cout<<"~Lozko\n";
	}

protected:
	int L_spanie;
};