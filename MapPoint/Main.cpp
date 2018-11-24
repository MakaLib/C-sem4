// Nazwa pliku wykonywalnego: MapaKlasa

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase MapPoint, ktora reprezentuje punkt na
// mapie skladajacy sie z dlugosci (longitude) i szerokosci
// (latitude) geograficznej bez oznaczania polkol.

// Funkcja print klasy MapPoint wypisuje na ekran, ze jest to punkt i
// podaje jego wspolrzedne w nawiasach okraglych.

// Metoda set_coordinates ustawia dlugosc i szerokosc geogreficzna
// punktu na podstawie argumentow, ktore przyjmuje.

// Metoda assign_id przypisuje obiektowy niepowtarzający sie numer ID.

// Zmienna next_free_id przechowuje numer ID, ktory moze byc
// przypisany kolejnemu punktowi.

// Funkcja distance w klasie MapPoint zwraca obiekt typu MapDistance,
// ktory przechowuje informacje o roznicy pomiedzy dlugosciami
// geograficznymi dwoch punktow oraz roznicy pomiedzy szerokosciami
// geograficznymi tych samych punktow.

// Metoda closest, zwraca punkt bedacy najblizej punktu na rzecz
// ktorego zostala wywolana metoda. Odleglosc pomiedzy punktami nalezy
// obliczyc jako pierwiastek sumy kwadratow roznic, czyli
// r = sqrt(delta_dlugosc*delta_dlugosc + delta_szerokosc*delta_szerokosc)

// Funkcja obliczajaca pierwiastek nazywa sie: sqrt(double) i znajduje
// sie w bibliotece "cmath".

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie MapaKlasa. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22

#include <iostream>
#include "MapDistance.h"
#include "MapPoint.h"
#include "MapPoint.h"
#include "MapDistance.h"

int main() {
  using std::cout;

  cout<<"========== KRK ==========\n";
  MapPoint krk;
  krk.set_latitude(19.938333);
  krk.set_longitude(50.061389);
  krk.assign_id();
  krk.print();

  cout<<"========== NYC ==========\n";
  const double nyc_latitude = 40.7127;
  const double nyc_longitude = -74.0059;
  MapPoint nyc;
  nyc.set_coordinates (nyc_latitude, nyc_longitude);
  nyc.assign_id();
  nyc.print();

  cout<<"Next free id: "<<MapPoint::next_free_id<<"\n";

  cout<<"========== PORTO & IRKUTSK ==========\n";
  MapPoint porto;
  porto.set_coordinates(41.162142, -8.621953);
  porto.assign_id();
  porto.print();
  MapPoint irkutsk;
  irkutsk.set_coordinates(52.283333, 104.283333);
  irkutsk.assign_id();
  irkutsk.print();

  cout<<"========== DISTANCE ==========\n";
  MapDistance nyc_porto = nyc.distance(porto);
  nyc_porto.print();

  cout<<"Next free id: "<<MapPoint::next_free_id<<"\n";

  cout<<"========== CLOSEST ==========\n";
  krk.closest(porto, irkutsk).print();

  return 0;
}
/** Wynik dzialania programu:
========== KRK ==========
Point with ID=1 : (19.9383, 50.0614)
========== NYC ==========
Point with ID=2 : (40.7127, -74.0059)
Next free id: 3
========== PORTO & IRKUTSK ==========
Point with ID=3 : (41.1621, -8.62195)
Point with ID=4 : (52.2833, 104.283)
========== DISTANCE ==========
Distance: (65.3839, 0.449444)
Next free id: 5
========== CLOSEST ==========
Point with ID=3 : (41.1621, -8.62195)
*/
