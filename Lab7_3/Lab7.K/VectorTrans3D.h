#pragma once
#include <iostream>
#include "Vector3D.h"
#include "Matrix3.h"


class Matrix3;
class Vector3D;
class VectorTrans3D{

friend class Vector3D;
friend class Matrix3;
 public:

  VectorTrans3D(int x, int y, int z);
  VectorTrans3D(){};
  void Print();
  Matrix3 Times(Vector3D  vector);
  
 private:
  
  int _x;
  int _y;
  int _z;

};
