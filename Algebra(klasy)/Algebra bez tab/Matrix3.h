#pragma once

class VectorTrans3D;
class Vector3D;

class Matrix3
{
public:
	void Print();
	VectorTrans3D Times(const VectorTrans3D &vector);
	Matrix3 Times(const Matrix3 &matrix);
	void Set(const Vector3D x, const Vector3D y, const Vector3D z);
	int Get(const int row, const int column) const;



private:
	Vector3D *Qvector_one;
	Vector3D *Qvector_two;
	Vector3D *Qvector_three;

};