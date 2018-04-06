#ifndef CMERCEDES_H
#define CMERCEDES_H
#include "CSamochod.h"

class CMercedes : public CSamochod
{
public:
	friend std::ostream& operator <<(std::ostream &wyjscie, const CMercedes &merc);
	CMercedes(const CSilnik &silnik, const float &przebieg);
	CMercedes(const CMercedes &merc);
};

#endif