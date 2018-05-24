#pragma once
#include <iostream>


class Pomieszczenie
{
public:
	Pomieszczenie(const std::string &nazwa);
	void zetrzyj_kurze() const;
	void umyj_podloge() const;
	void odkurz() const;

	template<typename T> void wstaw(const T &typ) const
	{
		std::cout<<"Wstawiam "<<typ<<" do pomieszczenia: "<<P_nazwa<<std::endl;
	};

	std::string Get() const;


private:
	std::string P_nazwa;
};