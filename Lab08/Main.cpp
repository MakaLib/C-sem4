 
// Nazwa pliku wykonywalnego: Wyjatki2

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementowac klasy:
// - MyClass
// - MyException
// oraz funkcje globalne
// - Fold1
// - Fold2
// - Fold3
// - MyTerminate

// Uwaga: ostatnia funkcja służy do zastąpienia domyślnej funkcji terminate() wywoływanej 
// w przypadku niepowodzenia przy odwijaniu stosu, mianowicie 
// żaden pasujący blok catch nie zostanie znaleziony. Mówimy wtedy, że wystąpił nieobsłużony wyjątek!
// Należy więc odpowiednio podmienić wskaźnik na domyślną funkcję terminate() przez nową, MyTerminate()

// Poszczególne stopnie zagdnieżdżenia programu (oraz tworzenie/kopionianie/niszczenie obiektów)
// są komunikowane przez wydruk na ekran;

// Funkcja Fold3 zawiera wewnętrzny mechanizm łapania wyjątków, gdzie określone są bloki catch:
// catch (double fLiczba)
// catch (int nLiczba)
// catch (unsigned uLiczba)
// catch (float fLiczba)
// To jakiego typu wyjątek zostanie rzucony zależy od wartości losowej zmiennej ReturnValueID
// mechanizm rzuczanie możena zaimplementować np poprzez instrukcję switch, gdzie odpowiednio
// rzucane będą przykładowe typy, np.:
// throw 9.242f;    // for float
// throw -87;       // for int
// throw 16u;       // for unsigned
// throw 3.14157;   // for double
// Uwaga: Ostatecznie więc, typ określony w wyniku zadania (linia 107 ponizej):
// Caught an exception of type: int 
// ma charakter losowy spośród (double, int, unsigned, float)

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.

#include "Main.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()  
{  
    cout << "Entering main" << endl;

    // global configuration
    srand( time( NULL ) ); 
    ReturnValueID = rand()%4; 

    try
    {
        try  
        {  
            MyClass d(" F0");  
            Fold1(d,1);  
        }

        catch (MyException& e)  
        {  
            cout << "Caught an exception of type: MyException" << endl;  
        }  
    
        throw 1;
    }

    catch (double& e)
    {
        cout << "Caught an exception of type: double" << endl;  

    }

    cout << "Exiting main." << endl;
}  
  
/* Output:  

Entering main
Created MyClass: F0
Copy created MyClass: F0
Entering fold level 1
Copy created MyClass: F1
Entering fold level 2
Copy created MyClass:F2
Entering fold level 3
Caught an exception of type: int
Destroyed MyClass: F3
Destroyed MyClass:F2
Destroyed MyClass: F1
Destroyed MyClass: F0
Caught an exception of type: MyException
--- UWAGA: blad mechanizmu wyjatkow ---
  
*/