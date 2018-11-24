#include "Vector3D.h"


Vector3D::Vector3D(){



}


Vector3D::Vector3D(int x, int y, int z){

  _x = x;
  _y = y;
  _z = z;

}


void Vector3D::Print(){

  std::cout<<"("<<_x<<", "<<_y<<", "<<_z<<")"<<std::endl;

}


int Vector3D::Times(VectorTrans3D vector){

  int sum = 0;

  sum += _x * vector._x;
  sum += _y * vector._y;
  sum += _z * vector._z;
  return sum;
}
