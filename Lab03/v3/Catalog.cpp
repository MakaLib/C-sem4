#include "Catalog.h"

Catalog::Catalog(const std::string str):C_title(str)
{
	C_size = 0;
}

void Catalog::AddBook(Book* book)
{
	C_size++;
	C_array.resize(C_size);
	C_array[C_size - 1] = book;
}

void Catalog::Print() const
{
	std::cout<<"\nCatalog::name "<<C_title<<"\n";
	for(int i = 0; i < C_size; i++)
	{
		std::cout<<"Catalog::book("<<i<<") "<<C_array[i]->GetTitle()<<"\n";
	}
}

Catalog::~Catalog()
{
	for(int i = 0; i < C_size; i++)
		delete C_array[i];
}