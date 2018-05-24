#include "OutOfRange.h"
#include "Number.h"


OutOfRange::OutOfRange(const float &start, const float &end, const std::string &name, const float &value)
:Range_start(start),Range_end(end),Range_name(name),Range_value(value)
{

}


std::ostream& operator<<(std::ostream& output, const OutOfRange &range)
{
	output<<"Number named: "<< range.Range_name<<" has value " <<range.Range_value
	<<" which is outside of the allowed range: ["<<range.Range_start<<", "<<range.Range_end<<"]";
	return output;
}

OutOfRange::~OutOfRange()
{
	Number::Clean();
}
