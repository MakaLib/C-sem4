#ifndef FLOATWRAPPER_H
#define FLOATWRAPPER_H
#include "Wrapper.h"

class FloatWrapper : public Wrapper
{
public:
	FloatWrapper(const float value);
	void print (std::ostream& output) const;

private:
	float FW_value;
};

#endif