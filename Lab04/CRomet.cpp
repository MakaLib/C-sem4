#include "CRomet.h"

CRomet::CRomet(const CSilnik &silnik, const float przebieg)
:CMotorower(silnik,"czerwony metalic", przebieg)
{

}

std::ostream& operator <<(std::ostream &wyjscie, const CRomet &romet)
{
	wyjscie<<"\nLiczba kol "<< romet.MOTOROWER_kola<<"\n";
	wyjscie<<"Stan licznika "<< romet.POJAZD_przebieg<<" [km]\n";
	wyjscie<<"Kolor "<<romet.POJAZD_kolor<<"\n";
	return wyjscie;
}
