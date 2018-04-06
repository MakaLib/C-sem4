
// Nazwa pliku wykonywalnego: mobile2

// Imie i Nazwisko:
// Imie i Nazwisko:

// Zajęcia realizowane w zespołach - bardziej twórcze niż odtwórcze!
// Uwaga1: Kontynuujemy pracę z programem z poprzednich zajęć - mobile.
// Uwaga2: We wszystkich nowotworzonych klasach przyjąć własną inicjatywę
//         niezbędnych składowych!
//
// Prosze napisac/uzupełnić klasy reprezentujace:
// CSilnik konstruktor typu elektrycznego
// CFord : public CSamochod
// CPojazdTrakcyjny : public CPojazd
// CTrolejbus : public CPojazdTrakcyjny, public CSamochod
// Uwaga1: jakiej modyfikacji trzeba dokonać w kodzie aby uniknąć
//        wielokrotnego zawierania klasy CPojazd?
// Uwaga2: W których klasach można zastosować ideę klasy finalnej?
//         Proszę ewentualnie to zrobić...

// CTimer
// CTimerDigital
// CTimerAnalog
// CTimerSerwer

// Proszę wyposzarzyć daną markę pojazdu o konkretny timer (digital lub analog)
// wedle uznania.

// Proszę postępować wg. instrukcji poniżej w main. Praktycznie będzie dodać
// odpowiednie drukowanie na ekran!

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string", oraz szablonu std::vector

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Rozwiazanie (archiwum mobile2.tar.gz zawierajace dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"

int main()
{
   CSilnik diesel(115,1.8,"ON");                  // moc, pojemność, paliwo
   CSilnik benzyna(130,1.9,"Pb95");               // moc, pojemność, paliwo
   CSilnik electric(110);                         // moc

   CPojazd* Pojazdy[9];                           // alternatywnie można skorzystać z std::vector

   // Prototyp:
   // 1. Metoda czysto wirtualna Clone w klasie bazowej
   // 2. !konstruktor kopiujący private - dlaczego?
   // Zadanie: proszę utworzyć wg wzorca po 3 kopie poniższych pojazdów zachowując
   //          wskaźnik na nie w tablicy Pojazdy (-> inicjalizacja statycznej tablicy)
   CMercedes mercedes_prototyp(diesel,0);
   CFord ford_prototyp(benzyna,0);
   CTrolejbus trolejbus_prototyp(electric,0);

   // Obserwatorzy:
   // 1. Do podmiotu CTimerSerwer dodajemy/rejestrujemy obserwatorów
   //    poprzez zainicjowanie tablicy/wektora wskaźników na zegary markowych samochódów,
   //    ale poprzez klase abstrakcyjną CTimer:
   //    CTimerSerwer::Attach(CTimer*) wywołana dla wszystkich pojazdów z tablicy Pojazdy
   //    Uwaga1: Może przydała by się metoda CTimerSerwer::Detach(CTimer*) ???
   // 2. Metody Synchronize(), Reset() w klasie CTimerSerwer ustawiające wszystkie zegary
   // Zadanie: Proszę utworzyć serwer czasowy oraz z synchronizować zegary w pojazdach


    return 0;
}
