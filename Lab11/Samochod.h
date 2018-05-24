#pragma once

#include <iostream>

class Samochod
{
public:
	Samochod(){};
	Samochod(const std::string &nazwa, const std::string &model)
	:S_nazwa(nazwa), S_model(model)
	{

	};

	void print() const
	{
		std::cout<<S_nazwa<<" "<<S_model<<"\n";
	};

private:
	std::string S_nazwa;
	std::string S_model;

};