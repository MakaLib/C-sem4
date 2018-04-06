/* Task: Properties 
 * Executable file: atest 
 * Description: 
 * 
 * Prosze napisac zestaw klas odpowiadajacych za zarzadzanie wlasciwosciami. 
 * Trzeba sie zastanowic jak za pomocą funkcji pomocniczej zaimplemenetować
 * "dziedziczenie" operatora wypisywania, (prosze nie kombinowac z przyjazniami).
 * 
 * Dodatkowo nalezy napisac klase bedaca kontenerem dla zaimplementowanych wlasciwosci 
 * o stałym rozmiarze (tablice), domyślnie wypelniona obiektami Propety. 
 * 
 */

#include "main.h"

using namespace std;

int main(){ 
	Property pemty;
	cout << "pemty = " << pemty << endl;
	Property_Int pint(245);
	cout << "pint = " << pint << endl;
	Property_Float pfloat(0.25);
	cout << "pfloat = " << pfloat << endl;

	// operacje na wlasciwosciach
	pint.modulo(23);
	cout << "pint = " << pint << endl;
	pfloat.inverse();
	cout << "pfloat = " << pfloat << endl;
	
	// wypisywanie referencji
	Property & pref = pint;
	cout << "pref = " << pref << endl;

	
	// ustawienie tablicy wlasciwosci, klonowanie obiektow:
	ProArray array(5);
	array.set(0, pint);
	array.set(1, pfloat);
	array.set(3, Property_Int(-8));
	array.printAll();
    array.set(0, Property_Float(1.4));
    array.printAll();
    
	// podstawowe obiekty sa niezmienione 
	cout << "pint = " << pint << endl;
	pint.modulo(8);
	cout << "pint = " << pint << endl;
    
    array.printAll();
    
	// do domu: jak zaimplementować operator [] dla naszej tablicy?
    
}

/* Output: 
pemty = EMPTY
pint = 245i
pfloat = 0.25f
pint = 15i
pfloat = 4f
pref = 15i
{15i, 4f, EMPTY, -8i, EMPTY}
{1.4f, 4f, EMPTY, -8i, EMPTY}
pint = 15i
pint = 7i
{1.4f, 4f, EMPTY, -8i, EMPTY}
*/ 
