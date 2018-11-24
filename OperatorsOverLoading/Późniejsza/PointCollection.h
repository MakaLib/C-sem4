#pragma once
class Point3D;

class PointCollection
{
public:
	PointCollection(const int size);
	PointCollection(const PointCollection& PC);
	~PointCollection();
	void Print() const;
	Point3D*& operator[](const int value) const;
	


private:
	Point3D **PC_array;
	int PC_size;

};