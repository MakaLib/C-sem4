#ifndef PROPERTY_FLOAT_H
#define PROPERTY_FLOAT_H
#include "Property.h"

class Property_Float : public virtual Property
{
public:
	Property_Float(const float value)
	:PF_value(value)
	{

	};

	void Print(std::ostream& output) const
	{
		output<<PF_value<<"f";
	};

	void inverse()
	{
		PF_value = 1.0/PF_value;
	};

	Property_Float* Get() const
	{
		return new Property_Float(PF_value);
	}



protected:
	float PF_value;

};

#endif