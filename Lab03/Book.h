#ifndef BOOK_H
#define BOOK_H
#include "Page.h"

class Book
{
public:
	Book(const int size = 0, const std::string str = "anonym", const bool set = false, const std::string title = "dummy");
	Book(const std::string str);
	~Book();
	void Print() const;
	void AddPage(Page* page);
	void AddTitle(const std::string str);
	void AddHeader(const std::string str);
	void AddText(const std::string str);
	void Copy(Book *book);
	std::string GetTitle() const;


private:
	Page **B_pages = NULL;
	int B_size;
	int B_position;
	std::string B_author;
	bool B_copy;
	std::string B_title;
};


#endif