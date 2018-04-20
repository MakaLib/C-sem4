#pragma once
#include "Rozdzielczosc.h"
#include <string>
#include <iostream>


class Urzadzenie
{
public:
	Urzadzenie(const std::string &nazwa)
	:U_nazwa(nazwa)
	{

	};

	std::string rodzaj() const 
	{
		return U_nazwa;
	};

	virtual ~Urzadzenie()
	{

	};



protected:
	std::string U_nazwa;
};