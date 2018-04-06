#include "Samochod.h"
#include "PojazdFrakcyjny.h"

class Trolejbus : public virtual Samochod, public virtual PojazdFrakcyjny {
public:
	Trolejbus (Silnik & silnik, float stan = 0.0): Pojazd (silnik, "czarny metalic", stan, 16) {}





};
