#ifndef FILE_H
#define FILE_H
#include "Dir.h"

class File
{
public:
	friend std::ostream& operator << (ostream& output, const File &file);
	File(const std::string str);


private:
	std::string F_name;
};

#endif