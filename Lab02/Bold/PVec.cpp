#include "PVec.h"

std::ostream& operator<<(std::ostream& output, const PVec& vec)
{
	for(int i = 0; i < vec.PV_current_size; i++)
	{
		vec.PV_Wrapper_table[i]->print(std::cout);
		output<<" ";
	}
	return output;
}

PVec::PVec(const int place, const int size)
{
	PV_current_size = place;
	PV_max_size = size;
	PV_Wrapper_table = new Wrapper *[size];
}

PVec& PVec::push_back(Wrapper* wrap)
{
	if(PV_current_size < PV_max_size)
	{
		PV_Wrapper_table[PV_current_size] = wrap;
		PV_current_size++;
	}
	return *this;
}

PVec& PVec::operator << (Wrapper *wrap)
{
	push_back(wrap);
	return *this;
}

Wrapper& PVec::operator[](const int place) const
{
	return *(PV_Wrapper_table[place]);
}

PVec::~PVec()
{
	for(int i = 0; i < PV_current_size; i++)
	{
		delete PV_Wrapper_table[i];
	}
	delete [] PV_Wrapper_table;
	PV_current_size = 0;
}