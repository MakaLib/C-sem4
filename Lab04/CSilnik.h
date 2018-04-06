#ifndef SILNIK_H
#define SILNIK_H
#include <string>
#include <iostream>

class CSilnik
{
public:
	CSilnik();
	CSilnik(const int moc, const float rozmiar, const std::string paliwo);
	//CSilnik(const CSilnik &silnik);
protected:
	int SILNIK_moc;
	float SILNIK_rozmiar;
	std::string SILNIK_paliwo;
};



#endif