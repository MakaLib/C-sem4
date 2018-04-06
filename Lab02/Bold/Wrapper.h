#ifndef WRAPPER_H
#define WRAPPER_H
#include <iostream>

class Wrapper
{
public:
	virtual void print(std::ostream& output) const = 0;
	virtual ~Wrapper();

};
#endif