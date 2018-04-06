#ifndef PROARRAY_H
#define PROARRAY_H
#include "Property.h"
#include "Property_Float.h"
#include "Property_Int.h"

class ProArray : public Property
{
public:
	ProArray(const int size)
	:PA_size(size)
	{
		PA_array = new Property *[size];
		for(int i = 0; i < PA_size; i++)
		{
			PA_array[i] = new Property;
		}
	};

	void set(const int place, const Property &obj)
	{
		if(PA_array[place]) delete PA_array[place];

		PA_array[place] = obj.Get();
	};

	void printAll()
	{
		std::cout<<"{";
		for(int i = 0; i < PA_size; i++)
		{
			std::cout <<*PA_array[i];
			if(i < PA_size - 1) std::cout<<", ";
		}
		std::cout<<"}\n";
	};

	~ProArray()
	{
		for(int i = 0; i < PA_size; i++)
			delete PA_array[i];
		delete [] PA_array;
		PA_size = 0;
	};

protected:
	Property **PA_array;
	int PA_size;



};

#endif