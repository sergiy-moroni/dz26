#include <iostream>
#include <algorithm>
#include <thread>
#include "Array.h"

using namespace std;

int GetRandomNum(int min, int max)
{
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

	 cout << "start" << endl;
	 sum = 0;
	 vector<int> sums;
	 for (int i = 0; i < partCount; i++) {
		 sums.push_back(0);
	 }
	vector<thread> threads;
	for (int j = 0; j < partCount; j++) {
		threads.push_back(thread ([ j, &sums, sizemini, &Arrays]() {
			//cout << "thread start " << j << endl;
			for (int i = 0; i < sizemini; i++) { sums[j] = sums[j] + Arrays[j][i]; }}));	
	}
	std::for_each(threads.begin(), threads.end(), [](std::thread& t)
		{ t.join(); });

	for (int y = 0; y < sums.size(); y++) {
		sum = sum + sums[y];
	}
	cout << sum << " ";
}
