// Nazwa pliku wykonywalnego: Vector

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace wektor (poziomy), wektor
// transposnowany (pionowy) i macierz. Prosze zaimplementowac mnozenie:
// * wektor*wektorTransponowany = liczba
// * wektoTransponowany*wektor = macierz

// UWAGA !!!
// Rozwiazujac zadanie nie wolno korzystac z biblioteki standardowej
// oprocz cout i endl.

// UWAGA !!!
// Wycieki pamieci obnizaja ocene koncowa o 2 punkty.

// Pliku Main.cpp, nie wolno modyfikowac. 

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie podanej na poczatku tego pliku. Program nalezy kompilowac
// z flagami -Wall -Wextra -pedantic -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22


#include "Main.h"
#include "Main.h"

#include <iostream>

int main() 
{
  Vector longVector (6);
  for (int i = 0; i < 6; ++i)
    longVector[i] = i+1 + 100;

  const int vectorSize = 3;
  Vector first (vectorSize);
  for (int i = 0; i < vectorSize; ++i)
    first[i] = i+1;

  VectorTrans second (vectorSize);
  for (int i = 0; i < vectorSize; ++i)
    second[i] = 20 + i;

  const Vector third = first;

  std::cout<<"long = "<<longVector<<"\n\n"; // long = [101, 102, 103, 104, 105, 106]

  std::cout<<"third manual = "<<third[0]<<", "<<third[1]<<", "<<third[2]<<"\n"; // third manual = 1, 2, 3
  std::cout<<"first = "<<first<<"\n"; // first = [1, 2, 3]
  std::cout<<"second = \n"<<second<<"\n";  // second = 
                                           // [20]
                                           // [21]
                                           // [22]

  std::cout<<"\n----- MODIFIED -----\n";

  first[0] = 42;
  std::cout<<"third = "<<third<<"\n"; // third = [1, 2, 3]
  std::cout<<"first = "<<first<<"\n"; // first = [42, 2, 3]
  
  std::cout<<"\n----- PRODUCTS -----\n";
  const double scalar = first*second;
  std::cout<<"Scalar prodcut = "<<scalar<<"\n\n"; // Scalar prodcut = 948

  const Matrix outerProduct = second*first;
  std::cout<<"Outer product\n"<<outerProduct<<"\n";  // Outer product
                                                     // [840, 40, 60]
                                                     // [882, 42, 63]
                                                     // [924, 44, 66]

  std::cout<<"----- EQUAL -----\n";
  longVector = first = first;

  std::cout<<"first = "<<first<<"\n"; // first = [42, 2, 3]
  std::cout<<"longVector = "<<longVector<<"\n"; // longVector = [42, 2, 3]
  
  return 0;
}
/* output
long = [101, 102, 103, 104, 105, 106]

third manual = 1, 2, 3
first = [1, 2, 3]
second = 
[20]
[21]
[22]

----- MODIFIED -----
third = [1, 2, 3]
first = [42, 2, 3]

----- PRODUCTS -----
Scalar prodcut = 948

Outer product
[840, 40, 60]
[882, 42, 63]
[924, 44, 66]

----- EQUAL -----
first = [42, 2, 3]
longVector = [42, 2, 3]
*/
