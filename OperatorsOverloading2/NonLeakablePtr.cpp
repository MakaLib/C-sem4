#include "NonLeakablePtr.h"
#include "NonLeakable.h"
#include <iostream>

NonLeakablePtr::NonLeakablePtr()
{
	NLP_Pointer = 0;
}

NonLeakablePtr::NonLeakablePtr(NonLeakablePtr& pointer)
{
	NLP_Pointer = pointer.NLP_Pointer;
	pointer.NLP_Pointer = 0;

}

void NonLeakablePtr::MakeNewObject()
{
	if(NLP_Pointer) delete NLP_Pointer;
	NLP_Pointer = new NonLeakable;
}

void NonLeakablePtr::Print() const
{
	if(NLP_Pointer == 0) std::cout<<"Object pointing to nothing\n";
	else std::cout<<"Object pointing to "<<NLP_Pointer<<"\n";
}

NonLeakable* NonLeakablePtr::operator->()
{
	return NLP_Pointer;
}

NonLeakable& NonLeakablePtr::operator*()
{
	return *NLP_Pointer;
}

NonLeakablePtr::~NonLeakablePtr()
{
	if(NLP_Pointer)
	{
	delete NLP_Pointer;
	NLP_Pointer = 0;
	}
}

NonLeakable* NonLeakablePtr::operator&()
{
	return NLP_Pointer;
}

NonLeakablePtr& NonLeakablePtr::operator=(NonLeakablePtr& pointer)
{
	if(NLP_Pointer == pointer.NLP_Pointer) return *this;
	NLP_Pointer = pointer.NLP_Pointer;
	pointer.NLP_Pointer = 0;
	return *this;
}