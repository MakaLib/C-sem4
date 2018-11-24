#ifndef MAIN_H
#define MAIN_H
#include <iostream>


typedef int** Array;

void CreateArray (Array *&firstArray, const int *size1, const int size2);
void FillWith(Array *&firstArray, const int value);
void Print (Array firstArray);
void PrintMax (Array *firstArray);
void SetElement(const int row, const int column, Array **firstArray, const int value);
void Clear (Array **firstArray);

#endif