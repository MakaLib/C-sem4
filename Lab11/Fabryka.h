#pragma once
#include "Samochod.h"

class Fabryka
{
public:

	template <typename T> void prototyp(const T &i) const
	{
		 zwroc(i, true);
	}

	template <typename T> T& produkuj() const
	{
		return zwroc(T(), false);
	}
private:
	template<typename T> T& zwroc(const T& i, bool test) const
	{
		static T wartosc;
		if(test) wartosc = i;
		return wartosc;
	}
};
