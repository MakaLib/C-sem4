#pragma once

#include "Samochod.h"

class Ford : public Samochod{
public:
	//konstruktor domyślny
	Ford () = default;

	//konstruktor ustawiający dane silnika, stały kolor, oraz stan licznika
	Ford (Silnik & silnik, float stan = 0.0): Pojazd (silnik, "czarny metalic", stan, 4) {}
};
