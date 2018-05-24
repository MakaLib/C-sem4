#pragma once

#include "MyClass.h"
#include "MyException.h"
#include <exception>

int ReturnValueID;

void MyTerminate()
{
	std::cout<<"--- UWAGA: blad mechanizmu wyjatkow ---\n";
	exit(-1);
}

void Fold3(MyClass my, int i)
{
	std::cout<<"Entering fold level "<< i << "\n";
	my.Set(" F" + std::to_string(i++));
	std::set_terminate(MyTerminate);

	try
	{
		switch(ReturnValueID)
		{
			case 0:
				throw 9.242f;
				break;
			case 1:
				throw -87;
				break;
			case 2:
				throw 16u;
				break;
			case 3:
				throw 3.14157;
				break;
		}
	}

	catch(double fLiczba)
	{
		std::cout<<"Caught an exception of type: double\n";
	}
	catch(int nLiczba)
	{
		std::cout<<"Caught an exception of type: int\n";
	}
	catch(unsigned uLiczba)
	{
		std::cout<<"Caught an exception of type: unsigned\n";
	}
	catch(float fLiczba)
	{
		std::cout<<"Caught an exception of type: float\n";
	}
}

void Fold2(MyClass my, int i)
{
	std::cout<<"Entering fold level "<< i <<"\n";
	my.Set("F" + std::to_string(i++));
	Fold3(my,i);

}


void Fold1(MyClass my, int i)
{
	std::cout<<"Entering fold level "<<i<<"\n";
	my.Set(" F" + std::to_string(i++));
	Fold2(my,i);
	MyException ex;
	throw ex;
}




