#ifndef ROMET_H
#define ROMET_H
#include "Motorower.h"

class Romet : public Motorower
{
public:
	Romet(){};
	Romet(const Silnik &silnik,const float przebieg, const std::string kolor = "czerwony metalic",const int kola = 2)
	:Motorower(silnik,kolor,przebieg,kola)
	{

	};
	/*void Przebieg(const float nowy)
	{
		POJAZD_licznik = nowy;
	};*/

};

#endif