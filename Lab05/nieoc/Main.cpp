
// Nazwa pliku wykonywalnego: mobile2

// Imie i Nazwisko: Mateusz Libirt
// Imie i Nazwisko: Aleksandra Poręba

// Zajęcia realizowane w zespołach - bardziej twórcze niż odtwórcze!
// Uwaga1: Kontynuujemy pracę z programem z poprzednich zajęć - mobile.
// Uwaga2: We wszystkich nowotworzonych klasach przyjąć własną inicjatywę
//         niezbędnych składowych!
//
// Prosze napisac/uzupełnić klasy reprezentujace:
// Silnik konstruktor typu elektrycznego
// Ford : public Samochod
// PojazdTrakcyjny : public Pojazd
// Trolejbus : public CPojazdTrakcyjny, public Samochod
// Uwaga1: jakiej modyfikacji trzeba dokonać w kodzie aby uniknąć
//        wielokrotnego zawierania klasy Pojazd?
// Uwaga2: W których klasach można zastosować ideę klasy finalnej?
//         Proszę ewentualnie to zrobić...

// Timer
// TimerDigital : public Timer
// TimerAnalog : public Timer
// TimerSerwer : public Timer

// Proszę wyposzarzyć daną markę pojazdu o konkretny timer (digital lub analog)
// wedle uznania.

// Proszę postępować wg. instrukcji poniżej w main. Praktycznie będzie dodać
// odpowiednie drukowanie na ekran!

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string", oraz szablonu std::vector

// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod).

// Rozwiazanie (archiwum mobile2.tar.gz zawierajace dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"

int main()
{
   Silnik diesel(115,1.8,"ON");                  // moc, pojemność, paliwo
   Silnik benzyna(130,1.9,"Pb95");               // moc, pojemność, paliwo
   Silnik electric(110);                         // moc

   //Pojazd* Pojazdy[9];                           // alternatywnie można skorzystać z std::vector
	std::vector<Pojazd*> Pojazdy;
	Pojazdy.resize(5);

   // Prototyp:
   // 1. Metoda czysto wirtualna Clone w klasie bazowej
   // 2. !konstruktor kopiujący private - dlaczego?
   // Zadanie: proszę utworzyć wg wzorca po 3 kopie poniższych pojazdów (xxx_prototyp)
   //          zachowując wskaźnik na nie w tablicy Pojazdy
   //          (-> inicjalizacja statycznej tablicy, lub wektora)
   Mercedes mercedes_prototyp1(diesel,0);
   Ford ford_prototyp1(benzyna,0);
   Mercedes mercedes_prototyp2(benzyna,0);
   Ford ford_prototyp2(diesel,0);
   Trolejbus trolejbus_prototyp1(electric,0);

	std::cout<<mercedes_prototyp1<<std::endl;
	std::cout<<ford_prototyp1<<std::endl;
	std::cout<<trolejbus_prototyp1<<std::endl;

	Pojazdy[0] = ford_prototyp1.Clone();
	Pojazdy[1] = mercedes_prototyp1.Clone();
	Pojazdy[2] = trolejbus_prototyp1.Clone();
	Pojazdy[3] = ford_prototyp2.Clone();
	Pojazdy[4] = ford_prototyp2.Clone();

	TimerServer *server = new TimerServer;
	//TimerDigital *td;

	for (Pojazd * pojazd : Pojazdy)	pojazd->Get_Timer()->Attach(server);
   //ford_prototyp2.m_timer->Synchronize()
   std::cout<<ford_prototyp2.Get_Timer()->Get_Start()<<std::endl;
	std::cout<<ford_prototyp2.Get_Timer()->Get_Start()<<std::endl;
	std::cout<<Pojazdy[0]->Get_Timer()->Get_Start()<<std::endl;

   server->Synchronize();
   std::cout<<"Po synchronizacji\n";
  // for(Pojazd *pojazd : Pojazdy) std::cout<<*pojazd<<std::endl;
   std::cout<<*Pojazdy[1]<<std::endl;
   std::cout<<*Pojazdy[3]<<std::endl;

   std::cout<<"Po Reset\n";
   server->Reset();
   std::cout<<*Pojazdy[1]<<std::endl;
   std::cout<<*Pojazdy[3]<<std::endl;
   //for(Pojazd *pojazd : Pojazdy) std::cout<<*pojazd<<std::endl;

	for(Pojazd * pojazd : Pojazdy) pojazd->Get_Timer()->Detach(server);


   for(int i = 0; i < 5; i++) delete Pojazdy[i];
	delete server;


   // Obserwatorzy:
   // 1. Do podmiotu TimerSerwer dodajemy/rejestrujemy obserwatorów
   //    poprzez zainicjowanie tablicy/wektora wskaźników na zegary markowych samochódów,
   //    ale poprzez klase abstrakcyjną Timer:
   //    TimerSerwer::Attach(Timer*) wywołana dla wszystkich pojazdów z tablicy Pojazdy
   //    Uwaga1: Może przydała by się metoda TimerSerwer::Detach(Timer*) ???
   // 2. Metody Synchronize(), Reset() w klasie TimerSerwer ustawiające wszystkie zegary
   // Zadanie: Proszę utworzyć serwer czasowy oraz z synchronizować zegary w pojazdach


    return 0;
}
