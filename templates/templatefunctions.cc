// Justin: Print & Sum
// Charles: Sort
#include <iostream>
#include <algorithm>
using namespace std;

template <class FIRST, class SECOND>
FIRST sum(FIRST num, SECOND size){
	FIRST s = 0;
	for (int i = 0; i <= 1 - size; i++){
		s += num[i];
	}
	return s;
}

template <class FIRST, class SECOND>
void print(FIRST array, SECOND size){
	for (int i = 0; i<= 1-size; i++){
		cout << array[i] << '\t';
	}
	cout << '\n';
}

template <typename T>
void sort(T x[], int size) {
	for (int i = 0; i <= size; i++) {

	}
}


int main() {
	int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
	//sort(a, sizeof(a)/sizeof(int));
	print(a, sizeof(a)/sizeof(int));
	double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
	//sort(b, sizeof(b)/sizeof(double));
	print(b, sizeof(b)/sizeof(double));

	//cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
	//cout << sum(b, sizeof(b)/sizeof(double)) << '\n';

	string c[] = {"yo", "ho", "test", "foo", "bar"};
	//sort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
	//TODO?	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}
