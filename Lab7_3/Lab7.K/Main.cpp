#include "Main.h"

#include<iostream>

int main ()
{
  Vector3D first (1, 2, 3);
  VectorTrans3D second (10, 20, 30);

  std::cout<<"second:\n";
  second.Print();  // 10
                   // 20
                   // 30

  std::cout<<"first = ";
  first.Print();  // (1, 2, 3)

  const int scalar = first.Times(second);
  std::cout<<"vector x vector transposed = "<<scalar<<"\n"; // vector x vector transposed = 140

  Matrix3 product = second.Times(first);
  std::cout<<"\nvector transposed x vector\n";
  product.Print(); // (10, 20, 30)
                   // (20, 40, 60)
                   // (30, 60, 90)

  std::cout<<"Matrix x vector transposed\n";
  product.Times(second).Print(); // 1400
                                 // 2800
                                 // 4200

  std::cout<<"Matrix x matrix\n";
  product.Times(product).Print(); // (1400, 2800, 4200)
                                  // (2800, 5600, 8400)
                                  // (4200, 8400, 12600)

  return 0;
}
/* wynik dzialania programu:
second:
10
20
30
first = (1, 2, 3)
vector x vector transposed = 140

vector transposed x vector
(10, 20, 30)
(20, 40, 60)
(30, 60, 90)
Matrix x vector transposed
1400
2800
4200
Matrix x matrix
(1400, 2800, 4200)
(2800, 5600, 8400)
(4200, 8400, 12600)
*/
