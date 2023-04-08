#include <iostream>
#include <algorithm>
#include <thread>
#include "Array.h"
#include <time.h>
using namespace std;

int GetRandomNum(int min, int max)
{
	//srand(time(NULL));
	int num = min + rand() % (max - min + 1);
	return num;
}

void summer( Array ar, int& sumar) {
	
	for (int i = 0; i < ar._size; i++) {
		sumar += ar[i];
	}
}


int main()
{
	int sum = 0;
	 int partCount = 5;
	 int size = 0;
	 cout << "Enter sizeArr: ";
	 cin >> size;

	 cout << "Enter partcount: ";
	 cin >> partCount;
	 Array arr(size);
	 int rand_value = 0;
	 for (int i = 0; i < size; i++) {
		 rand_value = GetRandomNum(0, 9);
		 arr[i] = rand_value;
	 }
	//arr.PrintArr();
	cout << endl;
	 int counter = 0;
	 vector<Array> Arrays;
	 int sizemini = 0;
	 if (size % partCount == 0) { sizemini = size / partCount; }
	 if (size % partCount != 0) { sizemini = size / partCount+1; }
	 for (int i = 0; i < partCount ;i++) {
		 Array miniarr(sizemini);
		 for (int j = 0; j < sizemini; j++) {
			 if (counter < size)
				 miniarr[j] = arr[counter++];
			 else
				 miniarr[j] = 0;
		 }
		 Arrays.push_back(miniarr);
	 }

	// for (int i = 0; i < Arrays.size(); i++) {
	//	 cout << "Array " << i << endl;
		// Arrays[i].PrintArr();
	//		 cout << endl;
	// }
	 summer(arr, sum);
	 cout << sum << endl;
	 sum = 0;
	vector<thread> threads;
	for (int j = 0; j < partCount; j++) {
		threads.push_back(thread ([ j, &sum, sizemini, &Arrays]() {for (int i = 0; i < sizemini; i++) { sum = sum + Arrays[j][i]; }}));
		
	}
	std::for_each(threads.begin(), threads.end(), [](std::thread& t)
		{ t.join(); });
	cout << sum << " ";
}
