#ifndef CROMET_H
#define CROMET_H
#include "CMotorower.h"

class CRomet : public CMotorower
{
public:
	friend std::ostream& operator <<(std::ostream &wyjscie, const CRomet &romet);
	CRomet(const CSilnik &silnik, const float przebieg);
};

#endif