// Nazwa pliku wykonywalnego: Point

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase reprezentujaca punkt w przestrzeni
// trojwymiarowej oraz tablice takich punktow. Rozmiar tablicy jest
// podany w konstruktorze.

// UWAGA !!!
// Rozwiazujac zadanie nie wolno korzystac z biblioteki standardowej oprocz cout i endl.

// UWAGA !!!
// Do rozwiazania zadania nie wolno korzystac ze slowa "static" jego
// uzycie oznacza obnizenie oceny o 4 punkty

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
  const Point3D first (1.2, 2.3, 3.4);
  Point3D second (10, 20, 30);

  std::cout<<"First and second\n";
  std::cout<<second<<"\n"<<first<<"\n"; // (10, 20, 30)
                                        // (1.2, 2.3, 3.4)

  std::cout<<"\nManual first: "<<first[Point3D::X]<<", "<<first[Point3D::Y]<<", "<<first[Point3D::Z]<<"\n"; // Manual first: 1.2, 2.3, 3.4

  std::cout<<"\nModified second\n";
  second[Point3D::X] = 50.5;
  second[Point3D::Y] = 60.5;
  std::cout<<second<<"\n";	// (50.5, 60.5, 30)
  

  PointCollection colFirst (4);
  colFirst[0] = new Point3D (9, 1, 5);
  colFirst[1] = new Point3D (6, 2, 8);
  colFirst[2] = new Point3D (11.1, 3.1, 90.2);
  colFirst[3] = new Point3D (21.1, 23.1, 50.2);

  std::cout<<"\nFirst collection\n";
  colFirst.Print();      // (9, 1, 5)
                         // (6, 2, 8)
                         // (11.1, 3.1, 90.2)
                         // (21.1, 23.1, 50.2)

  const PointCollection colSecond = colFirst;

  (*colFirst[0])[Point3D::X] = 42;
  (*colFirst[0])[Point3D::Y] = 42;
  (*colFirst[0])[Point3D::Z] = 42;

  std::cout<<"\nModified first collection\n";
  colFirst.Print();      // (42, 42, 42)
                         // (6, 2, 8)
                         // (11.1, 3.1, 90.2)
                         // (21.1, 23.1, 50.2)

  std::cout<<"\nSecond collection\n";
  colSecond.Print();     // (9, 1, 5)
                         // (6, 2, 8)
                         // (11.1, 3.1, 90.2)
                         // (21.1, 23.1, 50.2)

  return 0;
}
/* output
First and second
(10, 20, 30)
(1.2, 2.3, 3.4)

Manual first: 1.2, 2.3, 3.4

Modified second
(50.5, 60.5, 30)

First collection
(9, 1, 5)
(6, 2, 8)
(11.1, 3.1, 90.2)
(21.1, 23.1, 50.2)

Modified first collection
(42, 42, 42)
(6, 2, 8)
(11.1, 3.1, 90.2)
(21.1, 23.1, 50.2)

Second collection
(9, 1, 5)
(6, 2, 8)
(11.1, 3.1, 90.2)
(21.1, 23.1, 50.2)
*/
