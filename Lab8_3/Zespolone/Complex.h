#pragma once

class Register;

class ComplexNumber
{
public:
	void Print() const;
	ComplexNumber(const int real_part, const int imagine_part );
	
	ComplexNumber();
	ComplexNumber& SetReal(const int number);
	void SetImaginary(const int number);
	void Save(Register &reg);
	ComplexNumber Add(ComplexNumber number) const;
	int GetReal() const;
	int GetImagine() const;
	~ComplexNumber();


private:
	int real;
	int imagine;

};