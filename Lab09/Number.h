#pragma once
#include <iostream>
#include <vector>



class Number
{
public:
	Number(const std::string &name, const float &number);
	void Print() const;
	static void Clean(); 
	static void SetRange(const float &a, const float &b);
	static Number* Factory(const std::string &name, const float &i);
	~Number();

private:

	std::string N_name;
	float N_number;
	static std::vector<Number*>  N_allocated;
	static float N_min;
	static float N_max;
	bool N_alloc = false;

};
