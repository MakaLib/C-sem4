#pragma once

#include "Pojazd.h"

class Motorower : public Pojazd{
public:
	//konstruktor domyślny
	Motorower () = default;

	//konstruktor ustawiający dane silnika pochodzące z przekazanego obiektu, kolor, stan oraz wartość pola m_kola dla tej klasy
	Motorower(Silnik &silnik, std::string kolor, float stan): Pojazd (silnik, kolor, stan, 2) {}
};
