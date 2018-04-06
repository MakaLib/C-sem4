#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include <string>

class Property
{
public:
	Property()
	{
		P_value = "EMPTY";
	};
	virtual void Print(std::ostream &output) const
	{
		output << P_value;
	};

	virtual Property* Get() const
	{
		return new Property();
	}

	virtual ~Property()
	{

	};

protected:
	std::string P_value;


};

std::ostream &operator<<(std::ostream &output,const Property &obj)
{
	obj.Print(output);
	return output;
}


#endif