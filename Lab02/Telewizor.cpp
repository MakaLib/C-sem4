#include "Telewizor.h"
#include <iostream>

TelewizorLCD::TelewizorLCD(const int sz, const int wys):Ekran(sz,wys)
{

}

void TelewizorLCD::Wyswietl(const Urzadzenie &urz) const
{
	if(urz.ZwrocZnak() == 'K') std::cout<<"\nPolaczono telewizor i komputer\n";
	if(urz.ZwrocZnak() == 'D') std::cout<<"\nPolaczono telewizor i DVD\n";
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < szerokosc; j++) std::cout<<"_";
		std::cout<<"\n";
	}
	for(int i = 0; i < wysokosc; i++)
	{
		for(int j = 0; j < szerokosc; j++) std::cout<<urz.ZwrocZnak();
		std::cout<<std::endl;
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < szerokosc; j++) std::cout<<"_";
		std::cout<<"\n";
	}
}