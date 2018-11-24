#pragma once
#include <iostream>
class NonLeakable
{
public:
	friend class NonLeakablePtr;

	NonLeakable();
	void Print() const;
	~NonLeakable();

	

private:
	static int ID;
	int NL_ID;
	static void * operator new(size_t size);
	static void operator delete(void *wsk);
};