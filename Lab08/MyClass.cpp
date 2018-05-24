#include "MyClass.h"

MyClass::MyClass(const std::string &str)
:MC_string(str)
{
	std::cout<<"Created MyClass:"<< MC_string<<"\n";
}


MyClass::MyClass(const MyClass &my)
{
	std::cout<<"Copy created MyClass:"<< my.MC_string<<"\n";
}

void MyClass::Set(const std::string &str)
{
	MC_string = str;
}

MyClass::~MyClass()
{
	std::cout<<"Destroyed MyClass:"<<MC_string<<"\n";
}