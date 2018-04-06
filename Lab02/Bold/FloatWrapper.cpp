#include "FloatWrapper.h"

FloatWrapper::FloatWrapper(const float value):FW_value(value)
{

}

void FloatWrapper::print (std::ostream& output) const
{
	output<<FW_value;
}