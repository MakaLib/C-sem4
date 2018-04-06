#ifndef MOTOROWER_H
#define MOTOROWER_H
#include "Pojazd.h"

class Motorower : public Pojazd
{
public:
	Motorower(){};
	Motorower(const Silnik &silnik,const std::string &kolor,const float &licznik,const int kola = 2)
	:Pojazd(silnik,kolor,licznik,kola)
	{

	};
	//virtual void Przebieg(const float nowy);
};
#endif