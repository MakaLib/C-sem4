#pragma once

class Matrix3;
class Vector3D;

class VectorTrans3D
{
public:
	VectorTrans3D(const int x, const int y, const int z);
	void Print();
	Matrix3 Times(const Vector3D &vector);
	int Get(const int x) const;
	void Set(const int row,const int value);

private:
	int Qvector[3];

};
