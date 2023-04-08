#pragma once
#include <vector>
#include <iostream>
#include <stdlib.h>

class Array

{public:
	int _size;
	int* _arr;

	Array();
	Array(int size);
	~Array();
	int& operator [](const int& index);
	void PrintArr();
};

