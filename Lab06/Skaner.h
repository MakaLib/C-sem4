#pragma once
#include "Urzadzenie.h"


class Skaner : public virtual Urzadzenie
{
public: 
	Skaner(const Rozdzielczosc &roz)
	:Urzadzenie("Skaner"),S_roz(roz)
	{

	};

	/*std::string rodzaj() const
	{
		return U_nazwa;
	};*/

	/*virtual*/  std::string rozdzielczosc() const
	{
		return std::to_string(S_roz.Get_sz()) + "x" + std::to_string(S_roz.Get_wy());
	};
private:
	Rozdzielczosc S_roz;
};
