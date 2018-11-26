// Justin: Print & Sum
// Charles: Sort
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
T sum(T x[], int size){
	T s = 0;

	for (int i = 0; i < size; i++){
		s = s + x[i];
	}
	return s;
}

template <typename T>
void print(T x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

template <typename T>
void sort(T x[], int size) {
	for (int i = 0; i <= size; i++) {

	}
}


int main() {
	int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
	sort(a, sizeof(a)/sizeof(int));
	print(a, sizeof(a)/sizeof(int));
	double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
	sort(b, sizeof(b)/sizeof(double));
	print(b, sizeof(b)/sizeof(double));

	cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
	cout << sum(b, sizeof(b)/sizeof(double)) << '\n';

	string c[] = {"yo", "ho", "test", "foo", "bar"};
	sort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
	//TODO?	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}
