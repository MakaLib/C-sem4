#pragma once

#include "Pojazd.h"

class Samochod : public virtual Pojazd{
public:
	//konstruktor domyślny
	Samochod() = default;

	//konstruktor ustawiający dane silnika pochodzące z przekazanego obiektu, kolor, stan oraz wartość pola m_kola dla tej klasy
	Samochod(Silnik &silnik, std::string kolor = "brak", float stan = 0.0): Pojazd (silnik, kolor, stan, 4) {}

	Pojazd* Clone ();
private:
	Samochod (const Samochod& samochod);
};

