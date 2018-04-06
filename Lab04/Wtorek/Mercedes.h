#ifndef MARCEDES_H
#define MARCEDES_H
#include "Samochod.h"

class Mercedes : public Samochod
{
public:
	Mercedes(){};
	Mercedes(const Silnik &silnik,const float przebieg, const std::string kolor = "czarny metalic",const int kola = 4)
	:Samochod(silnik,kolor,przebieg,kola)
	{

	};
	//dziala tez bez
	Mercedes(const Mercedes &merc)
	{
		POJAZD_silnik = merc.POJAZD_silnik;
		POJAZD_kolor = merc.POJAZD_kolor;
		POJAZD_licznik = merc.POJAZD_licznik;
		POJAZD_kola = merc.POJAZD_kola;
	};

	/*void Przebieg(const float nowy)
	{
		POJAZD_licznik = nowy;
	};*/
};
#endif