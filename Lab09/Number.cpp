#include "Number.h"
#include "OutOfRange.h"


float Number::N_min;
float Number::N_max;
std::vector<Number*> Number::N_allocated;
//bool Number::N_alloc = false;

Number::Number(const std::string &name, const float &number)
:N_name(name), N_number(number)
{

}

void Number::SetRange(const float &a, const float &b)
{
	N_min = a;
	N_max = b;
}

Number* Number::Factory(const std::string &name, const float &i)
{
	std::cout<<"Manufacturing number "<<i<<"\n";
	Number *number = new Number(name,i);
	N_allocated.push_back(number);
	 number->N_alloc = true;
	if(i < N_min || i > N_max)
	{
		throw OutOfRange(N_min,N_max,name,i);
	}

	return number;
}

void Number::Print() const
{
	std::cout<<N_name<<" = "<<N_number<<"\n";
}

void Number::Clean()
{
	 if(int(N_allocated.size()))
	 {
		for(Number* n : N_allocated)
		{
			//if(n->N_alloc)
			//{
				//n->N_alloc = false;
				delete n;
			//}
		}
		N_allocated.resize(0);
	}
		
}

Number::~Number()
{
	std::cout<<"Destroying number "<<N_number<<"\n";
}