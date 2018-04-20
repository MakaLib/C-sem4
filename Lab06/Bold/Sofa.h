#pragma once
#include "Mebel.h"

class Sofa : public virtual Mebel
{
public:
	Sofa(const int sz, const int wys, const int dl, const int sied)
	:Mebel(sz,wys,dl),S_siedzisko(sied)
	{

	};


	virtual std::ostream& wypisz(std::ostream& out) const
	{
		out<<"Sofa: ";
		Mebel::wypisz(out);
		out<<" siedzisko: "<<S_siedzisko;
		return out;
	}

	~Sofa()
	{
		std::cout<<"~Sofa\n";
	}

protected:
	int S_siedzisko;
};