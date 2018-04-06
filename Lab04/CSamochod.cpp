#include "CSamochod.h"


CSamochod::CSamochod()
{

}

CSamochod::CSamochod(const CSilnik &silnik, const std::string color,const float przebieg)
:CPojazd(color,przebieg),CSilnik(silnik)
{
	SAMOCHOD_kola = 4;
}
/*
CSamochod::CSamochod(CSamochod &samochod)
{
	POJAZD_kolor = samochod.POJAZD_kolor;
	POJAZD_przebieg = samochod.POJAZD_przebieg;
}*/

std::ostream& operator<<(std::ostream &wyjscie, const CSamochod &samochod)
{
	/*Ogolny typ samochod:
	Liczba kol 4
	Stan licznika 0 [km]
	Kolor Czarny*/

	wyjscie<<"\nLiczba kol "<< samochod.SAMOCHOD_kola<<"\n";
	wyjscie<<"Stan licznika "<< samochod.POJAZD_przebieg<<" [km]\n";
	wyjscie<<"Kolor "<<samochod.POJAZD_kolor<<"\n";
	return wyjscie;
}