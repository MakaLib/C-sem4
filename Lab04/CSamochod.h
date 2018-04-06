#ifndef CSAMOCHOD_H
#define CSAMOCHOD_H
#include "CPojazd.h"

class CSamochod : public CPojazd, public CSilnik
{
public:
	friend std::ostream& operator <<(std::ostream &wyjscie, const CSamochod &samochod);
	CSamochod();
	CSamochod(const CSilnik &silnik, const std::string color,const float przebieg);
	//CSamochod(CSamochod &samochod);
protected:
	int SAMOCHOD_kola;
};

#endif