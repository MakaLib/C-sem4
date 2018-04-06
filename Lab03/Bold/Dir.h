#ifndef DIR_H
#define DIR_H
#include "File.h"
#include <iostream>
#include <string>
#include <vector>

class Dir
{
public:
	friend std::ostream& operator<<(ostream& output,const Dir& dire);
	void operator +=(const Dir& dire);
	void operator += (const File& file);
	Dir(const std::string str);
	Dir* get(const std::string str);

private:
	std::string D_name;
	std::vector<Dir> D_dir;
	int D_sized;
	std::vector<File> D_files;
	int D_sizef;
};

#endif