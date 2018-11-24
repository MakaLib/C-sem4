#pragma once
#include <iostream>
#include "VectorTrans3D.h"

class VectorTrans3D;
class Vector3D{

  friend class VectorTrans3D;
  friend class Matrix3;
 public:

  Vector3D();
  Vector3D(int x, int y, int z);
  void Print();
  int Times(VectorTrans3D vector);
 private:
  
  int _x;
  int _y;
  int _z;

};
