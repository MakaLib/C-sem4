#ifndef SILNIK_H
#define SILNIK_H
#include <string>
#include <iostream>

class Silnik
{
public:
	Silnik(){};
	Silnik(const int moc, const float pojemnosc, std::string paliwo)
	:SILNIK_moc(moc),SILNIK_pojemnosc(pojemnosc),SILNIK_paliwo(paliwo)
	{

	};

	Silnik(const Silnik &silnik)
	{
		SILNIK_moc = silnik.SILNIK_moc;
		SILNIK_pojemnosc = silnik.SILNIK_pojemnosc;
		SILNIK_paliwo = silnik.SILNIK_paliwo;
	};

protected:
	int SILNIK_moc;
	float SILNIK_pojemnosc;
	std::string SILNIK_paliwo;

};

#endif