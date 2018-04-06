#include "Catalog.h"

Catalog::Catalog(const std::string str,const int size)
:C_title(str), C_size(size)
{
	
}

void Catalog::AddBook(Book* book)
{
	C_size++;
	Book **new_book = new Book *[C_size];
	for(int i = 0 ; i < C_size - 1; i++)
	{
		std::string str = C_books[i]->GetTitle();
		new_book[i] = new Book(str);
		delete C_books[i];
	}
	if(C_books) 
		{
			delete [] C_books;
			C_books = NULL;
		}
	new_book[C_size - 1] = book;
	C_books = new_book;

}

void Catalog::Print() const
{
	std::cout<<"\nCatalog::name " <<C_title<<"\n";
	for(int i = 0; i < C_size; i++)
	{
		std::cout<<"Catalog::book("<<i<<") "<<C_books[i]->GetTitle()<<"\n";
	}

}

Catalog::~Catalog()
{
	
	for(int i = 0; i < C_size; i++)
		delete C_books[i];
	delete [] C_books;
	C_books = NULL;
	
}