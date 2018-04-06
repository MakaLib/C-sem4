#ifndef CPOJAZD_H
#define CPOJAZD_H
#include "CSilnik.h"

class CPojazd
{
public:
	CPojazd();
	CPojazd(const std::string kolor, const float przebieg);
	//CPojazd(const CPojazd &pojazd);
protected:
	std::string POJAZD_kolor;
	float POJAZD_przebieg;


};

#endif