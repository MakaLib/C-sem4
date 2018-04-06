// Nazwa pliku wykonywalnego: bib

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace:
// CSilnik
// CPojazd
// CSamochod
// CMotorower
// CMercedes
// CRomet
// Odpowiednie zależności dziedziczenia lub zawierania proszę
// wywnioskować z treści main().

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string".

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie bib. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum bib.tar.gz zawierajace dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"
using namespace std;

int main()
{
   CSilnik diesel(115,1.8,"ON");
   CSilnik benzyna(10,0.5,"Pb95");

   CSamochod samochod(diesel, "Czarny", 0.0);
   CMotorower motorower(benzyna,"Czarny",0.0);

   CMercedes mercedes(diesel,19808);
   CMercedes KlasaA = mercedes;

   CRomet romet(benzyna,1001);

   std::cout<<"Ogolny typ samochod:" << samochod << endl;
   std::cout<<"Mercedes:" << mercedes << endl;
   std::cout<<"KlasaA:" << KlasaA << endl;

   std::cout<<"Ogolny typ motorower:" << motorower << endl;
   std::cout<<"Romet:" << romet << endl;



    return 0;
}

/*
Ogolny typ samochod:
Liczba kol 4
Stan licznika 0 [km]
Kolor Czarny

Mercedes:
Liczba kol 4
Stan licznika 19808 [km]
Kolor czarny metalic

KlasaA:
Liczba kol 4
Stan licznika 0 [km]
Kolor czarny metalic

Ogolny typ motorower:
Liczba kol 2
Stan licznika 0 [km]
Kolor Czarny

Romet:
Liczba kol 2
Stan licznika 1001 [km]
Kolor czerwony metalic
*/
