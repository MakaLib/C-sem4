#ifndef DVD_H
#define DVD_H
#include "Urzadzenia.h"

class OdtwarzaczDVD : public Urzadzenie
{
public:
	OdtwarzaczDVD(const char znak):Urzadzenie(znak){};
};
#endif