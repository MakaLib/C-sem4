#include "StringWrapper.h"

StringWrapper::StringWrapper(const std::string text):SW_text(text)
{

}

void StringWrapper::print(std::ostream& output) const
{
	output<<SW_text;
}