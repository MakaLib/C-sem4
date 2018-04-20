#pragma once
#include "Urzadzenie.h"
#include "Papierozerne.h"

class Drukarka : public virtual Urzadzenie, public virtual Papierozerne
{
public:
	Drukarka(const Rozdzielczosc &roz)
	:Urzadzenie("Drukarka"), Papierozerne(), D_roz(roz)
	{

	};

	/*virtual std::string rodzaj() const
	{
		return U_nazwa;
	};*/

	/*virtual*/ std::string rozdzielczosc() const
	{
		return std::to_string(D_roz.Get_sz()) + "x" + std::to_string(D_roz.Get_wy());
	};
private:
	Rozdzielczosc D_roz;
};