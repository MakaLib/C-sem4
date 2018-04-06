#pragma once

#include "Motorower.h"

class Romet : public Motorower {
public:
	//konstruktor domyślny
	Romet () = default;

	//konstruktor ustawiający dane silnika, stały kolor, oraz stan licznika
	Romet (Silnik & silnik, float stan): Motorower (silnik, "czerwony metalic", stan) {}
};
