#pragma once

#include <iostream>


template <typename T> class UniquePointer
{
public:
	UniquePointer(T *pointer)
	:UP_pointer(pointer){}

	UniquePointer(const UniquePointer<T> &pointer){ }
	UniquePointer(UniquePointer<T> &pointer);

	T& operator*() const;

	UniquePointer<T>& operator = (UniquePointer<T>& pointer);

	operator T* ();

	T* Get() const;

	~UniquePointer();
	

	


private:

	T* UP_pointer;


};


template <typename T> std::ostream & operator <<(std::ostream &output, const UniquePointer<T> &pointer)
{
	return output <<"[pointing to "<<pointer.Get()<<"]";
}

template <typename T> UniquePointer<T>::UniquePointer(UniquePointer<T> &pointer)
{
	UP_pointer = pointer.UP_pointer;
	pointer.UP_pointer = NULL;
}

template <typename T> T& UniquePointer<T>::operator*() const
{
	return *UP_pointer;
}

template <typename T> UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer<T>& pointer)
{
	if(pointer.UP_pointer != UP_pointer)
	{
		delete UP_pointer;
		UP_pointer = pointer.UP_pointer;
		pointer.UP_pointer = NULL;
	}

	return *this;
}

template <typename T> UniquePointer<T>::operator T*()
{
	return UP_pointer;
}

template <typename T> T* UniquePointer<T>::Get () const
{
	return UP_pointer;
}

template <typename T> UniquePointer<T>::~UniquePointer()
{
	if(UP_pointer) delete UP_pointer;
}