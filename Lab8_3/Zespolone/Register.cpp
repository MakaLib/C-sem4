#include "Complex.h"
#include "Register.h"
#include <iostream>

Register* Register::head = 0;
bool Register::check;

void Register::Clear()
	{
		if(check)
		{
		check = false;
		delete head;
		}

	}
Register& Register::Retrieve()
{
	if(!check)
	{
		std::cout<<"Creating register\n";
		head = new Register;
	}
	return *head;
		

}
void Register::Print()
{
	if(check)
	{
	std::cout<<"Register stores number: "<<real<<" + "<<imagine<<"i\n";
	}
	else std::cout<<"Register is empty\n";
}
void Register::Write(ComplexNumber const &number)
{
	check = true;
	real = number.GetReal();
	imagine = number.GetImagine();

}
ComplexNumber Register::Read()
{
	ComplexNumber complex;
	complex.SetReal(real).SetImaginary(imagine);
	return complex;
	
}


void Register::Set(const int real_part, const int imagine_part)
{
	real = real_part;
	imagine = imagine_part;
}
