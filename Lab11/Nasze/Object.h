#pragma once
#include <iostream>

//klasa Objekt przechowujaca informacje o nazwie obiektu
class Object
{
public:
	//Konstrukotr klasy Object ustwiajacay nazwe
	Object(const std::string &name)
	:O_name(name){};

	//Metoda wypisujaca nazwe obiektu
	void Print() const
	{
		std::cout<<"name: \""<<O_name<<"\".\n";
	}

private:
	//Nazwa obiektu
	std::string O_name;
};

//Przeladowanie operatora<< dla klasy Object
std::ostream& operator<<(std::ostream& out, const Object &obj)
{
	obj.Print();
	return out;
}