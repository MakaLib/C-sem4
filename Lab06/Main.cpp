// Nazwa pliku wykonywalnego: office

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy wg zadanej hierarchii opisującej zestaw urządzeń
// biórowych. Urządzenia te są w różnych relacjach.
// Zaimplementowana hierarchia powinna być uzasadniona
// inaczej zadanie będzie nie na temat == 0pkt.

// Odpowiednie zależności dziedziczenia lub zawierania proszę
// wywnioskować z treści main().

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie office. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum office.tar.gz zawierajace dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.s

#include <iostream>
#include "Urzadzenia.h"

///////////////////////////////////////////////////////
//
void ptrPrint(const void* p) {
  if ( p == 0 )
    std::cout << "null ptr" << std::endl;
  else
    std::cout << "valid ptr" << std::endl;
}

///////////////////////////////////////////////////////
//
void Print(const Urzadzenie* u) {
  if ( u )
    std::cout << u->rodzaj()  << std::endl;
}

///////////////////////////////////////////////////////
//
int main() {
  
  Skaner* skaner= new Skaner(  Rozdzielczosc(1000, 1600) );
  ptrPrint(dynamic_cast<Papierozerne*>(skaner));
  
  
  Drukarka* drukarka= new Drukarka(  Rozdzielczosc(1000, 1600) );
  ptrPrint(dynamic_cast<Papierozerne*>(drukarka));
  Print(drukarka);

  Papierozerne* AllInOne =  new Wielofunkcyjne( Rozdzielczosc(300,600), Rozdzielczosc(600, 1200) );
  const Drukarka *d = dynamic_cast<Drukarka*>(AllInOne);
  const Ksero *k = dynamic_cast<Ksero*>(AllInOne);  
  const Skaner *s = dynamic_cast<Skaner*>(AllInOne);  
  ptrPrint(d);
  Print(d);
  ptrPrint(k);
  Print(k);
  ptrPrint(s);
  Print(s);
  ptrPrint(dynamic_cast<const Papierozerne*>(k));
 
  std::cout << d->rozdzielczosc() << std::endl;
  std::cout << s->rozdzielczosc() << std::endl;


  delete skaner;
  delete drukarka;
  delete AllInOne;
}
/* wynik
null ptr
valid ptr
Drukarka
valid ptr
Wielofunkcyjne
valid ptr
Wielofunkcyjne
valid ptr
Wielofunkcyjne
valid ptr
300x600
600x1200
 */