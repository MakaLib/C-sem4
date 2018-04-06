#include "CMotorower.h"

CMotorower::CMotorower(const CSilnik &silnik,const std::string color, const float przebieg)
:CPojazd(color,przebieg),CSilnik(silnik)
{
	MOTOROWER_kola = 2;
}

std::ostream& operator <<(std::ostream &wyjscie, const CMotorower &motor)
{
	/*Ogolny typ motorower:
Liczba kol 2
Stan licznika 0 [km]
Kolor Czarny*/
	wyjscie<<"\nLiczba kol "<< motor.MOTOROWER_kola<<"\n";
	wyjscie<<"Stan licznika "<< motor.POJAZD_przebieg<<" [km]\n";
	wyjscie<<"Kolor "<<motor.POJAZD_kolor<<"\n";
	return wyjscie;
}