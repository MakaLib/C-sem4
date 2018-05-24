#include "Pomieszczenie.h"

Pomieszczenie::Pomieszczenie(const std::string &nazwa)
:P_nazwa(nazwa)
{
	std::cout<<"Tworze pomieszczenie: "<<nazwa<<std::endl;
}

void Pomieszczenie::zetrzyj_kurze() const
{
	std::cout<<"Scieram kurze w pomieszczeniu: "<<P_nazwa<<std::endl;
}

void Pomieszczenie::umyj_podloge() const
{
	std::cout<<"Myje podloge w pomieszczeniu: "<<P_nazwa<<std::endl;
}

void Pomieszczenie::odkurz() const
{
	std::cout<<"Odkurzam pomieszczenie: "<<P_nazwa<<std::endl;
}

std::string Pomieszczenie::Get() const
{
	return P_nazwa;
}