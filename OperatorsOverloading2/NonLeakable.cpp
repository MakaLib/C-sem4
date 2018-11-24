#include "NonLeakable.h"
#include <iostream>
#include <cstdlib>
int NonLeakable::ID = 0;

NonLeakable::NonLeakable()
{
	std::cout<<"Constructing object "<<ID<<"\n";
	NL_ID = ID;
	ID++;
}

void NonLeakable::Print() const
{
	std::cout<<"This is object with ID="<<NL_ID<<"\n";
}

void * NonLeakable::operator new(size_t size)
{
	void *wsk = malloc(size);
	return wsk;
}

NonLeakable::~NonLeakable()
{
	std::cout<<"Destroying object "<<NL_ID<<"\n";
}

void NonLeakable::operator delete(void *wsk)
{
	free(wsk);
}