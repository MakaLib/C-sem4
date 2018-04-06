#include "Page.h"

std::vector<Page*> array;
Page::Page(const std::string first, const std::string second):P_header(first),P_bufor(second)
{

}

void Page::AddHeader(const std::string str)
{
	P_header = str;
}

void Page::AddText(const std::string str)
{
	P_bufor = str;
}

void Page::Print(const int i) const
{
	if(i < 0)
	{
	std::cout <<"Page::header "<<P_header<<"\n";
	std::cout<<"Page::text "<<P_bufor<<"\n";
	}
	else if(i == 0)
	{
		if(P_bufor == "empty")
		{
		 std::cout<<"Page("<<i<<")::text Title page(header: "<<P_header<<")\n";
		}
		else
		{
			std::cout<<"Page("<<i<<")::text Title: "<<P_bufor<<"(header: "<<P_header<<")\n";
		}
	}
	else std::cout<<"Page("<<i<<")::text "<<P_bufor<<"(header: "<<P_header<<")\n";
}

Page* Page::Copy()
{

	return new Page(P_header, P_bufor);
}

void Page::SetHeader(const std::string str)
{
	P_header = str;
}

void Page::SetText(const std::string str)
{
	P_bufor = str;
}