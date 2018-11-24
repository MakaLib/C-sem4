#pragma once
#include <iostream>

class ComplexNumber;

class Register
{
public:
	static void Clear();
	
	static Register& Retrieve();
	
	void Print();
	void Write(ComplexNumber const &number);
	ComplexNumber Read(); 
	void Set(const int real_part, const int imagine_part) ;

private:
	static bool check;
	int real; 
	int imagine;
	static Register *head;
	
};