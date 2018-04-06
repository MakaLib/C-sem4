#ifndef PROPERTY_INT_H
#define PROPERTY_INT_H
#include "Property.h"

class Property_Int : public virtual Property
{
public:
	Property_Int(const int value)
	:PI_value(value)
	{

	};
	void Print(std::ostream& output) const
	{
		output<<PI_value<<"i";
	}

	void modulo(const int mod)
	{
		PI_value = PI_value % mod;
	};

	Property_Int* Get () const
	{
		return new Property_Int(PI_value);
	}

protected:
	int PI_value;

};


#endif