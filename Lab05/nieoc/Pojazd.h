#pragma once

#include <iostream>
#include "Silnik.h"
#include "Timer.h"

class Pojazd : public Silnik {
public:
	//konstruktor domyślny
	Pojazd() = default;

	//konstruktor ustawiający dane silnika pochodzące z przekazanego obiektu, wartości pól m_kolor, m_stan oraz m_kola
	Pojazd (Silnik &silnik, std::string kolor, float stan, int kola = 0): Silnik(silnik), m_kolor (kolor), m_stan(stan), m_kola(kola) {m_timer = new TimerDigital;}

	//konstruktor kopiujący, zmienia tylko wartość licznika na 0
	Pojazd (Pojazd & pojazd) {*this = pojazd;}

	//operator przypisania, zmienia tylko wartość licznika na 0
	void operator=(Pojazd &pojazd);

	virtual ~Pojazd () {delete m_timer;}

	//funkcja ustawiająca wartość stanu licznika na podaną
	void Przebieg (float stan) {m_stan = stan;}

	//funkcja zwracajaca wartosc m_kolor
	std::string Kolor () {return m_kolor;}

	//funkcja zwracajaca wartosc m_kola
	int Kola () {return m_kola;}

	//funkcja zwracajaca wartosc pola m_stan
	float Stan () {return m_stan;}

	int Timer_start() {return m_timer->Get_Start();}

	Timer* Get_Timer() {return m_timer;}

	virtual Pojazd* Clone () = 0;

	
	
protected:
	//pole przechowujace informacje o kolorze obiektu
	std::string m_kolor;

	//pole przechowujace informacje o stanie licznika obiektu
	float m_stan;

	//pole przechowujace informacje o ilosci kół obiektu
	int m_kola;
	TimerDigital * m_timer;

};

//funckja przeładowania operatora do wypisywania informacji na temat obiektu
std::ostream &operator<< (std::ostream &stream, Pojazd &pojazd);



