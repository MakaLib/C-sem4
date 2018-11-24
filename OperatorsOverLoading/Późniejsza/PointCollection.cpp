#include "PointCollection.h"
#include "Point3D.h"

PointCollection::PointCollection(const int size):PC_size(size)
{
	PC_array = new Point3D *[size];
}

PointCollection::~PointCollection()
{
	for(int row = 0; row < PC_size; row++)
	{
		delete PC_array[row];
	}
	delete [] PC_array;
	PC_size = 0;
}

PointCollection::PointCollection(const PointCollection& PC)
{
	PC_size = PC.PC_size;
	PC_array = new Point3D *[PC_size];
	for(int row = 0; row < PC_size; row++)
	{
		PC_array[row] = new Point3D(PC.PC_array[row]->GetX(), PC.PC_array[row]->GetY(), PC.PC_array[row]->GetZ());
	}
}

void PointCollection::Print() const
{
	for(int row = 0; row < PC_size; row++)
	{
		std::cout<< *PC_array[row]<<"\n";
	}
}

Point3D*& PointCollection::operator[](const int value) const
{
	return PC_array[value];
}
