#ifndef KOMPUTER_H
#define KOMPUTER_H
#include "Urzadzenia.h"

class Komputer: public Urzadzenie
{
public:
	Komputer(const char znak):Urzadzenie(znak){};
};
#endif