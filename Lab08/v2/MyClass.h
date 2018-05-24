#pragma once
#include <iostream>


class MyClass
{
public:
	MyClass(const std::string &str);
	MyClass(const MyClass &my);


	void Set(const std::string &str);
	~MyClass();

	static int ilosc;


private:
	std::string MC_string;

};