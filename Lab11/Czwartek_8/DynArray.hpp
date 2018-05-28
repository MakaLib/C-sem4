#pragma once
#include <iostream>

template <typename T> class DynArray
{
public:
	DynArray(const int &size);
	DynArray(const int &size, const T *array);
	int size() const;
	T* begin() const;
	T* end() const;
	T& operator[](const int &i) const;
	~DynArray();

	class Iterator
	{
	public:
		Iterator(T* it)
		:I_it(it)
		{
			I_place = 0;
		}

		bool operator !=(const T* it) const
		{
			if(I_it == it) return false;
			return true;
		}

		T* operator++()
		{
			//I_place++;
			//I_it = &DA_array[I_place];
			I_it++;
			return I_it;
		}

		T operator*() const
		{
			return *I_it;
		}

		T* operator->() const
		{
			return I_it;
		}









	private:
		T* I_it;
		int I_place;
	};
private:
	T* DA_array;
	int DA_size;
};


template <typename T> std::ostream& operator<<(std::ostream &out, const DynArray<T> &array)
{
	out<<"{";
	for(int i = 0; i < array.size(); i++)
	{
		out<<"\""<<array[i]<<"\"";
		if(i < array.size() - 1) out<<",";
	}
	out<<"}";
	return out;
}

template <typename T> DynArray<T>::DynArray(const int &size)
:DA_size(size)
{
	DA_array = new T [size];
}

template <typename T> DynArray<T>::DynArray(const int &size, const T *array)
:DA_size(size)
{
	DA_array = new T[size];
	for(int i = 0; i < size; i++)
	{
		DA_array[i] = array[i];
	}
}

template <typename T> int DynArray<T>::size() const
{
	return DA_size;
}

template <typename T> T& DynArray<T>::operator[](const int &i) const
{
	return DA_array[i];
}

template <typename T> DynArray<T>::~DynArray()
{
	delete [] DA_array;
	DA_size = 0;
}

template <typename T> T* DynArray<T>::begin() const
{
	return &DA_array[0];
}

template <typename T> T* DynArray<T>::end() const
{
	return &DA_array[DA_size];
}




