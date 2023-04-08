#include "Array.h"



	Array::Array() : _size(0) {}
	Array::Array(int size) {
		if (size > 0) {
			_size = size;
			_arr = new int[_size];

			for (int i = 0; i < _size; i++) {
				_arr[i] = 0;
			}
		}else{
			std::cout << "Array is Empty!" << std::endl;
				_size = 0;

		}
	}
	Array::~Array()
	{
	//if(_size>0) delete[] _arr;
	}

	void Array::PrintArr() {
		for (int i = 0; i < _size; i++) {
			std::cout << _arr[i] << " ";
		}
	}
	int& Array:: operator [](const int& index) {
		return _arr[index];
	}

