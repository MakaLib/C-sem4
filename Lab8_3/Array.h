#ifndef ARRAY_H
#define ARRAY_H



class MyArray
{
public:
	// referencja do pola Csize
	const int &size;
	// konstrukotr tworzyacy tablice int o wielkosci size
	MyArray(const int SIZE);
	//konstrukotr kopiujacy, tworzacy nowa tablice (nie chcemy wrzucac oryginalnego wskaznika do funkcji)
	MyArray(const MyArray &array);
	//funckja zwracajaca element tablicy
	int& at(const int number) const;
	//funkcja wypisujaca elementy tablicy
	void print();
	//funkcja zmieniajaca rozmiar tablicy
	void resize(const int number);
	//destruktor niszczacy tabice Carray
	~MyArray();

private:
	int *Carray;
	int Csize;


};

#endif