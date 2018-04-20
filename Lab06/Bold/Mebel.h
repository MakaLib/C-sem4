#pragma once
#include <iostream>

class Mebel
{
public:
	Mebel(const int sz, const int wys, const int dl)
	:M_sz(sz),M_wys(wys),M_dl(dl)
	{

	};
	
	virtual std::ostream& wypisz(std::ostream& out) const
	{
		out<<"Mebel: sz:"<<M_sz
		<<" wys:"<<M_wys
		<<" dl:"<<M_dl;
		return out;
	}

	virtual ~Mebel()
	{
		std::cout<<"~Mebel\n";
	}

protected:
	int M_sz;
	int M_wys;
	int M_dl;

};

std::ostream& operator<<(std::ostream& out, const Mebel &mebel)
{
	/*out<<"Mebel: sz:"<<mebel.Get_sz()
		<<" wys:"<<mebel.Get_wys()
		<<" dl:"<<mebel.Get_dl();*/

		mebel.wypisz(out);

	return out;
}