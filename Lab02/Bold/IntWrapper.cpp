#include "IntWrapper.h"

IntWrapper::IntWrapper(const int value):IW_value(value)
{

}

void IntWrapper::print(std::ostream& output) const
{
	output<<IW_value;
}