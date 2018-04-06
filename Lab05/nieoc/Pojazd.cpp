#include "Pojazd.h"

void Pojazd::operator=(Pojazd &pojazd){
	m_kolor = pojazd.m_kolor;
	m_stan = 0;
	m_kola = pojazd.m_kola;
	m_moc = pojazd.m_moc;
	m_pojemnosc = pojazd.m_pojemnosc;
	m_paliwo = pojazd.m_paliwo;
	m_timer = new TimerDigital ();
}


std::ostream &operator<< (std::ostream &stream, Pojazd &pojazd){
	stream << std::endl;
	stream << "Liczba kol " << pojazd.Kola() << std::endl;
	stream << "Stan licznika " << pojazd.Stan() << " [km]"<< std::endl;
	stream << "Kolor " << pojazd.Kolor() << std::endl;
	stream << "Zegar - start " << pojazd.Timer_start() << std::endl;

	return stream;
}

