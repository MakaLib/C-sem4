#ifndef URZADZENIA_H
#define URZADZENIA_H
class Urzadzenie
{
public:
	Urzadzenie(const char znak):typ(znak){};
	char ZwrocZnak() const
		{
			return typ;
		}
protected:
	char typ;
};

#endif