#include "Book.h"

Book::Book(const int size, const std::string str, const std::string title)
:B_size(size),B_author(str),B_title(title)
{
	B_array.resize(B_size);
	B_array[0] = new Page;
	B_copy = false;
	B_position = 1;
}

Book::Book(const std::string str):B_title(str)
{

}

Book::~Book()
{
	for(int i = 0; i < B_size; i++)
		delete B_array[i];
}

void Book::Print() const
{
	if(B_copy) std::cout<<"\nBook::autor (copy) "<< B_author<<"\n";
	else std::cout<<"\nBook::autor "<< B_author<<"\n";

	for(int i = 0; i < B_size; i++)
	{
		B_array[i]->Print(i);
	}
}

void Book::AddPage(Page* page)
{
	B_size++;
	B_array.resize(B_size);
	B_array[B_size - 1] = page->Copy();
	//B_array.push_back(page);
}

void Book::AddTitle(const std::string str)
{
	B_title = str;
	B_array[0] -> AddHeader("empty");
	B_array[0] -> AddText(str);
}

void Book::AddHeader(const std::string str)
{
	for(int i = 1; i < B_size; i++)
	{
		B_array[i] -> AddHeader(str);
	}
}

void Book::AddText(const std::string str)
{
	if(B_position < B_size)
	{
		B_array[B_position]->AddText(str);
		B_position++;
	}
	else std::cout<<"\n[ERROR]:: No enough pages in the book!\n";

}

void Book::Copy(Book *book)
{
	B_array.resize(book->B_size);
	B_size = book -> B_size;
	B_copy = true;
	for(int i = 0; i < B_size; i++)
	{
		B_array[i] = book->B_array[i]->Copy();
	}
}

std::string Book::GetTitle() const
{
	return B_title;
}