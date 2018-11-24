#pragma once
#include <iostream>
#include "Vector3D.h"
#include "VectorTrans3D.h"

class VectorTrans3D;
class Vector3D;
class Matrix3{

 public:
  ~Matrix3();
  void Setter(Vector3D ** vector_tab1);
  void Print();
  VectorTrans3D Times(VectorTrans3D vector);
  Matrix3 Times(Matrix3 matrix); 
  

 private:
  
  Vector3D**  _vector3DTab;


};
