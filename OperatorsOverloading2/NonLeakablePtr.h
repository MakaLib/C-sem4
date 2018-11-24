#pragma once

class NonLeakable;
class NonLeakablePtr
{
public:
	NonLeakablePtr();
	NonLeakablePtr(NonLeakablePtr& pointer);
	void MakeNewObject();
	void Print() const;
	NonLeakablePtr& operator=(NonLeakablePtr& pointer);
	NonLeakable* operator->();
	NonLeakable& operator*();
	NonLeakable* operator&();
	~NonLeakablePtr();

private:
	NonLeakable *NLP_Pointer;
};