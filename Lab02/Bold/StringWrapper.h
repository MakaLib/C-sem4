#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H
#include "Wrapper.h"
#include <string>

class StringWrapper : public Wrapper
{
public:
	StringWrapper(const std::string text);
	void print(std::ostream& output) const;

private:
	std::string SW_text;
};
#endif