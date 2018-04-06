#ifndef MOTOROWER_H
#define MOTOROWER_H
#include "CPojazd.h"

class CMotorower: public CPojazd, public CSilnik
{
public:
	friend std::ostream& operator <<(std::ostream &wyjscie, const CMotorower &motor);
	CMotorower(const CSilnik &silnik,const std::string color, const float przebieg);
protected:
	int MOTOROWER_kola;
};
#endif