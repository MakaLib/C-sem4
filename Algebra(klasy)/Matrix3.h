#pragma once

class VectorTrans3D;


class Matrix3
{
public:
	void Print();
	VectorTrans3D Times(const VectorTrans3D &vector);
	Matrix3 Times(const Matrix3 &matrix);
	void Set(const int x, const int y, const int value);
	int Get(const int row, const int column) const;


private:
	int Qmatrix[3][3];

};