#include "VectorTrans3D.h"



VectorTrans3D::VectorTrans3D(int x, int y, int z){

  _x = x;
  _y = y;
  _z = z;

}

void VectorTrans3D::Print(){

  std::cout<<_x<<std::endl;
  std::cout<<_y<<std::endl;
  std::cout<<_z<<std::endl;
  
}

Matrix3 VectorTrans3D::Times(Vector3D  vector){

  Matrix3 result;
  Vector3D** vectortab = new Vector3D*[3];
  Vector3D* vector1 = new Vector3D;
  Vector3D* vector2 = new Vector3D;
  Vector3D* vector3 = new Vector3D;
  vectortab[0] = vector1;
  vectortab[1] = vector2;
  vectortab[2] = vector3;
  result.Setter(vectortab);
  
  vectortab[0]->_x = _x * vector._x;
  vectortab[0]->_y = _x * vector._y;
  vectortab[0]->_z = _x * vector._z;

  vectortab[1]->_x = _y * vector._x;
  vectortab[1]->_y = _y * vector._y;
  vectortab[1]->_z = _y * vector._z;

  vectortab[2]->_x = _z * vector._x;
  vectortab[2]->_y = _z * vector._y;
  vectortab[2]->_z = _z * vector._z;
  
  return result;

}
