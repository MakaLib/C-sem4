#include "Samochod.h"

Samochod::Samochod (const Samochod& samochod){
	m_moc = samochod.m_moc;
	m_pojemnosc = samochod.m_pojemnosc;
	m_paliwo = samochod.m_paliwo;
	m_kolor = samochod.m_kolor;
	m_stan = samochod.m_stan;
	m_kola = samochod.m_kola;
	m_timer = new TimerDigital ();
}

Pojazd* Samochod::Clone (){
	return new Samochod(*this);
}
