#ifndef TELEWIZOR_H
#define TELEWIZOR_H
#include "Ekran.h"
#include "Urzadzenia.h"

class TelewizorLCD : public Ekran
{
public:
	TelewizorLCD(const int sz, const int wys);
	void Wyswietl(const Urzadzenie &urz) const;
};


#endif