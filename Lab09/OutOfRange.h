#pragma once
#include <iostream>

class OutOfRange
{
public:
	friend std::ostream& operator<<(std::ostream& output, const OutOfRange &range);
	OutOfRange(const float &start, const float &end, const std::string &name, const float &value);
	~OutOfRange();

private:
	float Range_start;
	float Range_end;
	std::string Range_name;
	float Range_value;



};


