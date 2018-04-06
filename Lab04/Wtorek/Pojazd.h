#ifndef POJAZD_H
#define POJAZD_H
#include "Silnik.h"

class Pojazd
{
public:
	friend std::ostream& operator<<(std::ostream &wyjscie, const Pojazd &pojazd);
	Pojazd(){};
	Pojazd(const Silnik &silnik, const std::string &kolor, const float licznik,const int kola = 0)
	:POJAZD_silnik(silnik),POJAZD_kolor(kolor), POJAZD_licznik(licznik),POJAZD_kola(kola)
	{

	};
	//virtual void Przebieg(const float nowy) = 0; ??nie dziala
	void Przebieg(const float nowy)
	{
		POJAZD_licznik = nowy;
	}

protected:
	Silnik POJAZD_silnik;
	std::string POJAZD_kolor;
	float POJAZD_licznik;
	int POJAZD_kola;
};


std::ostream& operator<<(std::ostream &wyjscie, const Pojazd &pojazd)
{
	wyjscie<<"\nLiczba kol "<<pojazd.POJAZD_kola<<"\n";
	wyjscie<<"Stan liczika "<<pojazd.POJAZD_licznik<<" [km]\n";
	wyjscie<<"Kolor "<<pojazd.POJAZD_kolor<<"\n";
	return wyjscie;
}
#endif
