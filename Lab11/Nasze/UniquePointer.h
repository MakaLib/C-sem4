#pragma once
#include "Object.h"

//Szablonowa klasa UniquePointer
//majaca informacje o wskazniku na dowolny obiekt
template <typename T> class UniquePointer
{
public:
	//Konstruktr klasy ustawiajacy adres wskaznika
	UniquePointer(T* pointer);
	//Konstruktor kopiujacy ustawiajacy adres wskaznika i ustawiajacay
	//adres zmiennej kopiowanego obiektu na NULL
	UniquePointer(UniquePointer<T> &pointer);
	//Metoda zwracajaca adres wskaznika
	T* Get() const;
	//Przeladowanie operatora= , jesli trzeba usuwa obecny wskaznik, przypisuje do niego nowa wartosc
	//i ustawia kopiowany wskaznik na NULL
	UniquePointer<T>& operator=(UniquePointer<T> &pointer);
	//Zwraca to na co wskazuje wskaznik
	T operator*() const;
	//Metoda wypisuje to na co wskazuje wskaznik
	void Print() const;
	//zwraca adres wskaznika
	T* operator ->() const;
	//zwraca odres wskaznika
	operator T*() const;
	//Destruktor zwalniajacy wskaznik
	~UniquePointer();

private:
	//Wskaznik na dowolny obiekt
	T* UP_pointer;

};



template <typename T> std::ostream& operator<<(std::ostream& out, const UniquePointer<T> &pointer)
{
	return out<<"[pointing to "<<pointer.Get()<<"]";
}

template <typename T> UniquePointer<T>::UniquePointer(T* pointer)
:UP_pointer(pointer)
{

};

template <typename T> UniquePointer<T>::UniquePointer(UniquePointer<T> &pointer)
{
	UP_pointer = pointer.UP_pointer;
	pointer.UP_pointer = NULL;
}

template <typename T> T* UniquePointer<T>::Get() const
{
	return UP_pointer;
}

template <typename T> T UniquePointer<T>::operator*() const
{
	return *UP_pointer;
}

template <typename T> UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer<T> &pointer)
{
	if(UP_pointer != pointer.UP_pointer)
	{
		delete UP_pointer;
		UP_pointer = pointer.UP_pointer;
		pointer.UP_pointer = NULL;
	}

	return *this;
}

template <typename T> void UniquePointer<T>::Print() const
{
	std::cout<<*UP_pointer;
}

template <typename T> T* UniquePointer<T>::operator->() const
{
	return UP_pointer;
}

template <typename T> UniquePointer<T>::operator T*() const
{
	return UP_pointer;
}

template <typename T> UniquePointer<T>::~UniquePointer()
{
	if(UP_pointer)
	{
		delete UP_pointer;
	}
	UP_pointer = NULL;
}