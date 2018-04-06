#ifndef CATALOG_H
#define CATALOG_H
#include "Book.h"

class Catalog
{
public:
	Catalog(const std::string str, const int size = 0);
	void AddBook(Book* book);
	void Print() const;
	~Catalog();
private:
	Book **C_books = NULL;
	std::string C_title;
	int C_size;

};



#endif