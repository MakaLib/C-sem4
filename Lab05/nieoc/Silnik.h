#pragma once

#include <string>

class Silnik {
public:
	//konstruktor inicjalizujacy wartosci m_moc, m_pojemnosc i m_paliwo na domyślne lub podane
	Silnik (int moc, float pojemnosc, std::string paliwo): m_moc(moc), m_pojemnosc(pojemnosc), m_paliwo (paliwo) {}
	//konstruktor typu elektrycznego
	Silnik (int moc = 0): m_moc(moc), m_pojemnosc(0.0), m_paliwo("brak") {}

protected:
	//pole przechowujace informacje o mocy obiektu
	int m_moc;

	//pole przechowujace informacje o pojemnosci obiektu
	float m_pojemnosc;

	//pole przechowujace informacje o typie paliwa obiektu
	std::string m_paliwo;
};
