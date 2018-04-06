#ifndef PVec_H
#define PVec_H
#include "Allclasses.h"

class PVec
{
public:
	friend std::ostream& operator<<(std::ostream& output, const PVec& vec); 
	PVec(const int place = 0, const int size = 15);
	PVec& push_back(Wrapper* wrap);
	PVec& operator << (Wrapper *wrap);
	Wrapper& operator[](const int place) const;
	~PVec();


private:
	Wrapper **PV_Wrapper_table;
	int PV_current_size;
	int PV_max_size;
};

#endif