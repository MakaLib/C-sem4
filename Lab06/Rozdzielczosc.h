#pragma once


class Rozdzielczosc
{
public:
	Rozdzielczosc(const int szer, const int wys)
	:R_szerokosc(szer), R_wysokosc(wys)
	{

	};

	int Get_sz() const
	{
		return R_szerokosc;
	}

	int Get_wy() const
	{
		return R_wysokosc;
	}



private:
	int R_szerokosc;
	int R_wysokosc;
};











































































//Copyright Mateusz Libirt :D