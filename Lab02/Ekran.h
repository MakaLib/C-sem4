#ifndef EKRAN_H
#define EKRAN_H
#include "Urzadzenia.h"

class Ekran
{
public:
	Ekran(const int sz, const int wys):szerokosc(sz),wysokosc(wys){};
	virtual void Wyswietl(const Urzadzenie &urzadzenie) const = 0 ;
protected:
	int szerokosc;
	int wysokosc;

};

#endif