// Nazwa pliku wykonywalnego: Fabryka

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Tematem zadania sa szablony funkcji. Funkcje szablonowe moga byc metodami i moga byc statyczne.
// chcemy aby jakims wiekszym programie wystepowala klasa fabryka, ktora gwarantuje ze 
// mamy mozliwosc wytworzenia identycznych obiektow.
// 
// Prosze zwrocic uwage ze same fabryka nie jest szablonowa a tylko funkcje sa szablonowe.
// W rozwiazaniu nalezy skozystac z statycznych skladnikow funkcji i tego ze kazda instancjacja 
// szablonu to jest odrebna funkcja.

// Prosze dopisac prosta klase Mercedes do wykorzystana jako prototyp przez Fabryke

// Uwaga na poprawnosc const!

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty 
// (miec czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.


#include <iostream>
#include <string>

#include "Fabryka.h"

int main() {   
  Fabryka p;
  p.prototyp<int>(7);
  p.prototyp<float>(3.14);  
  std::cout << p.produkuj<int>() << std::endl;
  std::cout << p.produkuj<float>() << std::endl;
  std::cout << p.produkuj<float>() << std::endl;

  std::cout << "*** wymiana int i wymiana fabryki ***" << std::endl;
  Fabryka b;
  b.prototyp<int>(9);
  std::cout << b.produkuj<int>() << std::endl;
  std::cout << b.produkuj<float>() << std::endl;

  
  p.prototyp<Samochod>(Samochod("Mercedes", "klasy C"));
  Samochod s1 = p.produkuj<Samochod>();
  s1.print();
  Samochod s2 = p.produkuj<Samochod>();
  s2.print();
  p.prototyp(Samochod("Ford", "C-max"));
  Samochod s3 = p.produkuj<Samochod>();
  s3.print();
   
}

// 7
// 3.14
// 3.14
// *** wymiana int i wymiana fabryki ***
// 9
// 3.14
// Mercedes klasy C
// Mercedes klasy C
// Ford C-max
