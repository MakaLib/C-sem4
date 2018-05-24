#pragma once
#include "Pomieszczenie.h"

template <void (Pomieszczenie::*metoda)()const> void Lokaj(Pomieszczenie &miejsce)
{
	(miejsce.*metoda)();
}

template <void (Pomieszczenie::*metoda)()const> void Lokaj (const Pomieszczenie &miejsce)
{
	std::cout<<"Pomieszczenie: "<<miejsce.Get()<<" jest zamkniete\n";
}

template <int T> void Lokaj(Pomieszczenie miejsce)
{
	std::cout<<"Nic nie robie\n";
} 