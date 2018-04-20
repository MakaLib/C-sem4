#pragma once
#include "Sofa.h"
#include "Lozko.h"

class Kanapa : public Sofa, public Lozko
{
public:
	Kanapa(const int sz, const int wys, const int dl, const int sofa, const int lozko)
	:Mebel(sz,wys,dl),Sofa(sz,wys,dl,sofa),Lozko(sz,wys,dl,lozko)
	{

	}

	virtual std::ostream& wypisz(std::ostream& out) const
	{
		out<<"jako "; Mebel::wypisz(out); out<<"\n";
		out<<" jako "; Sofa::wypisz(out); out<<"\n";
		out<<" jako "; Lozko::wypisz(out);
		return out;
	}

	~Kanapa()
	{
		std::cout<<"~Kanapa\n";
	}
};