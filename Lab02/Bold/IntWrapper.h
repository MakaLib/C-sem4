#ifndef INTWRAPPER_H
#define INTWRAPPER_H
#include "Wrapper.h"
class IntWrapper : public Wrapper
{
public:
	IntWrapper(const int value);
	void print(std::ostream& output) const;

private:
	int IW_value;
};

#endif