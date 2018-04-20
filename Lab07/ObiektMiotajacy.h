#pragma once
#include "typ2.h"

class ObiektMiotajacy
{
public:
	void Rzuc()
	{
		delete this;
		
		throw new typ2;
	};
};


