#ifndef MONITOR_H
#define MONITOR_H
#include "Ekran.h"
#include "Urzadzenia.h"

class Monitor : public Ekran
{
public:
	Monitor(const int sz, const int wys);
	void Wyswietl(const Urzadzenie &urz) const;
};

#endif