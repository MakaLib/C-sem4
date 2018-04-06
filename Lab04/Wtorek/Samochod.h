#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include "Pojazd.h"

class Samochod : public Pojazd
{
public:
	Samochod(){};
	Samochod(const Silnik &silnik, const std::string kolor,const float licznik,const int kola = 4)
	:Pojazd(silnik,kolor,licznik,kola)
	{

	};
	//virtual void Przebieg(const float nowy);
};
#endif