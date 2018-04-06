#include "CMercedes.h"

CMercedes::CMercedes(const CSilnik &silnik, const float &przebieg)
:CSamochod(silnik,"czarny metalic", przebieg)
{

}

CMercedes::CMercedes(const CMercedes &merc)
{
	SAMOCHOD_kola = merc.SAMOCHOD_kola;
	POJAZD_kolor = merc.POJAZD_kolor;
	POJAZD_przebieg = 0;
}

std::ostream& operator <<(std::ostream &wyjscie, const CMercedes &merc)
{
	/*Mercedes:
Liczba kol 4
Stan licznika 19808 [km]
Kolor czarny metalic*/
	wyjscie<<"\nLiczba kol "<< merc.SAMOCHOD_kola<<"\n";
	wyjscie<<"Stan licznika "<< merc.POJAZD_przebieg<<" [km]\n";
	wyjscie<<"Kolor "<<merc.POJAZD_kolor<<"\n";
	return wyjscie;
}