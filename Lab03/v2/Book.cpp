#include "Book.h"

Book::Book(const int size, const std::string str, const bool set, const std::string title)
:B_size(size), B_author(str), B_copy(set), B_title(title)
{
	B_position = 0;
}

Book::Book(const std::string str)
{
	B_title = str;
}

Book::~Book()
{

	if(B_pages)
	{for(int i = 0; i < B_size; i++)
		delete B_pages[i];
	delete [] B_pages;
	B_pages =NULL;
	}
}

void Book::Print() const
{
	if(B_copy)
	std::cout<<"\nBook::autor (copy) "<< B_author<<"\n";
	else std::cout<<"\nBook::autor "<< B_author<<"\n";


	for(int i = 0; i < B_size; i++)
	{
		B_pages[i]->Print(i);
	}
}

void Book::AddPage(Page* page)
{
	Page **new_page = new Page*[B_size];
	for(int i = 0; i < B_size; i++)
	{
		new_page[i] = B_pages[i]->Copy();
		delete B_pages[i];
	}
	delete [] B_pages;

	B_size++;
	B_pages = new Page *[B_size];
	for(int i = 0; i < B_size - 1; i++)
	{
		B_pages[i] = new_page[i] -> Copy();
		delete new_page[i];
	}
	delete [] new_page;
	B_pages[B_size - 1] = page->Copy();
}

void Book::AddHeader(const std::string str)
{
	for(int i = 1; i < B_size; i++)
	{
		B_pages[i]->SetHeader(str);
		B_pages[i]->SetText("empty");
	}
}

void Book::AddTitle(const std::string str)
{
	B_pages[0]->SetHeader("empty");
	B_pages[0]->SetText(str);
	B_title = str;
}

void Book::AddText(const std::string str)
{
	if(B_position < B_size)
	{
		B_pages[B_position++]-> SetText(str);
	}
	else
	{
		std::cout<<"\n[ERROR]:: No enough pages in the book!\n";
	}
}

void Book::Copy(Book *book)
{
	B_copy = true;
	B_author = book->B_author;
	B_title = book->B_title;
	B_size = book->B_size;
	B_pages = new Page *[book->B_size];
	for(int i = 0; i < book->B_size; i++)
	{
		B_pages[i] = book->B_pages[i]->Copy();
	}
}

std::string Book::GetTitle() const
{
	return B_title;
}