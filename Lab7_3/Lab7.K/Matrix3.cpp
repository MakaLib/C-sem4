#include "Matrix3.h"


Matrix3::~Matrix3(){

   delete _vector3DTab[0];
   delete _vector3DTab[1];
   delete _vector3DTab[2];
   delete[] _vector3DTab;
}


void Matrix3::Setter(Vector3D ** vector_tab1){

  _vector3DTab = vector_tab1;


}


void Matrix3::Print(){

  _vector3DTab[0]->Print();
  _vector3DTab[1]->Print();
  _vector3DTab[2]->Print();


}



VectorTrans3D Matrix3::Times(VectorTrans3D vector){

  VectorTrans3D temp_vector;
  temp_vector._x = _vector3DTab[0]->_x * vector._x + _vector3DTab[0]->_y * vector._y + _vector3DTab[0]->_z * vector._z  ;
  temp_vector._y = _vector3DTab[1]->_x * vector._x + _vector3DTab[1]->_y * vector._y + _vector3DTab[1]->_z * vector._z  ;
  temp_vector._z = _vector3DTab[2]->_x * vector._x + _vector3DTab[2]->_y * vector._y + _vector3DTab[2]->_z * vector._z  ;
  return temp_vector;

}


Matrix3 Matrix3::Times(Matrix3 matrix){

  Matrix3 result;
  Vector3D** vectortab = new Vector3D*[3];
  Vector3D* vector1 = new Vector3D;
  Vector3D* vector2 = new Vector3D;
  Vector3D* vector3 = new Vector3D;
  vectortab[0] = vector1;
  vectortab[1] = vector2;
  vectortab[2] = vector3;
  result.Setter(vectortab);

  for(int i=0; i<3; ++i){
    
    vectortab[i]->_x = _vector3DTab[i]->_x * matrix._vector3DTab[0]->_x + _vector3DTab[i]->_y * matrix._vector3DTab[1]->_x + _vector3DTab[i]->_z * matrix._vector3DTab[2]->_x;
    vectortab[i]->_y = _vector3DTab[i]->_x * matrix._vector3DTab[0]->_y + _vector3DTab[i]->_y * matrix._vector3DTab[1]->_y + _vector3DTab[i]->_z * matrix._vector3DTab[2]->_y;
    vectortab[i]->_z = _vector3DTab[i]->_x * matrix._vector3DTab[0]->_z + _vector3DTab[i]->_y * matrix._vector3DTab[1]->_z + _vector3DTab[i]->_z * matrix._vector3DTab[2]->_z;
  }



  return result;
}
