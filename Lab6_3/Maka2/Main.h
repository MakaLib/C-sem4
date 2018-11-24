#ifndef MAIN_H
#define MAIN_H

typedef struct Array
{
	int str_rows;
	int *str_columns;
	int **wsk;
}Array;


Array& CreateArray (const int *size1,const int size2 );
void FillWith(Array firstArray,const int value);
void Print (Array firstArray);
void SetElement(const int row,const int column, Array *firstArray,const int value);
void  PrintMax (Array firstArray); 
void Clear (Array &firstArray);

#endif