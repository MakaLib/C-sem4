#pragma once
#include <iostream>


class MyClass
{
public:
	MyClass(const std::string &str);
	MyClass(const MyClass &my);

	void Set(const std::string &str);
	~MyClass();


private:
	std::string MC_string;

};