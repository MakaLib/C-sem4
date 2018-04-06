#ifndef CATALOG_H
#define CATALOG_H
#include "Book.h"

class Catalog
{
public:
	Catalog(const std::string str);
	void AddBook(Book* book);
	void Print() const;
	~Catalog();
private:
	std::vector<Book*> C_array;
	std::string C_title;
	int C_size;

};



#endif