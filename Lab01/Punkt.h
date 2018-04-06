#pragma once
#include <iostream>

class Punkt
{
public:
	Punkt(int x);
	int Zwroc() const;
	virtual ~Punkt();
	virtual void wypisz(const std::ostream &output) const  = 0;
	virtual double polePow() const = 0;  
private:
	int P_x;
};

void wypisz(const Punkt *object);
void wypisz(const Punkt &object); 