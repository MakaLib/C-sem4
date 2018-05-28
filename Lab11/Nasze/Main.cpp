// Nazwa pliku wykonywalnego: SmartPointer

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac prosta klase Object, ktora bedzie przchowywala nazwe
// np. w postaci std::string i miala mozliwosc wypisywania na ekran

// Prosze zaimplementować szablon klasy UniquePointer, ktory bedzie przechowywal adres
// obiektu. Moze istniec tylko jeden obiekt przechowujacy ten sam
// adres. Gdy obiekt typu UniqeuPointer jest niszczony, niszczony
// powinien byc rowniez obiekt na ktory wskazuje.

// UWAGA
// W zadaniu bardzo wazne jest zarzadzanie pamiecia.

// Pliku Main.cpp, nie wolno modyfikowac.

// Komentarz w kodzie mowia jakie wyjscie powinna generowac dana
// linia.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Fraction. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.

#include"Main.h"
#include<iostream>

void PrintObject (const Object* obj) { obj->Print(); }

int main ()
{
  using namespace std;

  std::cout<<"===== INTEGER =====\n";
  UniquePointer<int> dynamicInt1 ( new int (4) );
  std::cout<<"pointer: "<<dynamicInt1<<"\n";      // pointer: [pointing to <adres>]
  std::cout<<"  value: "<<*dynamicInt1<<"\n\n";   //   value: 4

  std::cout<<"===== FLOAT =====\n";
  UniquePointer<float> dynamicFloat ( new float (3.5) );
  std::cout<<"pointer: "<<dynamicFloat<<"\n";     // pointer: [pointing to <adres>]
  std::cout<<"  value: "<<*dynamicFloat<<"\n\n";  //   value: 3.5

  cout<<"===== ARBITRARY OBJECT =====\n";
  UniquePointer<const Object> dynamicObject1 ( new Object ("Frist object") );
  cout<<"pointer: "<<dynamicObject1<<"\n";          // pointer: [pointing to <adres>]
  dynamicObject1->Print();                          // name: "Frist object".
  {
    cout<<" ---- entering new scope ---- \n";
    UniquePointer<const Object> dynamicObject2 = dynamicObject1;
    cout<<"pointer: "<<dynamicObject1<<"\n"; // pointer: [pointing to 0]
    cout<<"pointer: "<<dynamicObject2<<"\n"; // pointer: [pointing to <adres>]
    dynamicObject2->Print();                 // name "Frist object".

    UniquePointer<const Object> dynamicObject3 ( new Object ("Next object") );
    cout<<dynamicObject3<<"\n";       // [pointing to <adres>]
    PrintObject(dynamicObject3);      // name "Next object".

    dynamicObject3 = dynamicObject2 = dynamicObject2;
    cout<<"EQUAL: "<<"\n";                      // EQUAL:
    cout<<"pointer: "<<dynamicObject1<<"\n";    // pointer: [pointing to 0]
    cout<<"pointer: "<<dynamicObject2<<"\n";    // pointer: [pointing to 0]
    cout<<"pointer: "<<dynamicObject3<<"\n";    // pointer: [pointing to <adres>]
    (*dynamicObject3).Print();                  // name "Frist object."
    cout<<" ---- end of scope ---- \n\n";
  }

  return 0;
}
/*
===== INTEGER =====
pointer: [pointing to 0x24b2030]
  value: 4

===== FLOAT =====
pointer: [pointing to 0x24b2050]
  value: 3.5

===== ARBITRARY OBJECT =====
pointer: [pointing to 0x24b2070]
name: "Frist object".
 ---- entering new scope ---- 
pointer: [pointing to 0]
pointer: [pointing to 0x24b2070]
name: "Frist object".
[pointing to 0x24b20a0]
name: "Next object".
EQUAL: 
pointer: [pointing to 0]
pointer: [pointing to 0]
pointer: [pointing to 0x24b2070]
name: "Frist object".
 ---- end of scope ----
 */
