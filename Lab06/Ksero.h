#pragma once
#include "Urzadzenie.h"
#include "Papierozerne.h"

class Ksero : public virtual Urzadzenie, public virtual Papierozerne
{
public:
	Ksero(const Rozdzielczosc &roz)
	:Urzadzenie("Ksero"),Papierozerne(), K_roz(roz)
	{

	};

	/*virtual std::string rodzaj() const
	{
		return U_nazwa;
	};*/

	/*virtual*/ std::string rozdzielczosc() const
	{
		return std::to_string(K_roz.Get_sz()) + "x" + std::to_string(K_roz.Get_wy());
	};
private:
	Rozdzielczosc K_roz;

}; 