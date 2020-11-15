#include "MyIntVector.h"
#include <iostream>
using namespace std;

int main()
{
	MyIntVector vector1;
	cout << "This is vector 1: ";
	for (size_t i = 0, ilen = vector1.size(); i < ilen; ++i) {
		cout << vector1[i] << ' ';
	}
	cout << endl;

	MyIntVector vector2 = vector1;
	cout << "This is vector 2: ";
	for (size_t i = 0, ilen = vector2.size(); i < ilen; ++i) {
		cout << vector2[i] << ' ';
	}
	cout << endl;

	MyIntVector vector3;
	vector3 = vector1;
	cout << "This is vector 3: ";
	for (size_t i = 0, ilen = vector3.size(); i < ilen; ++i) {
		cout << vector3[i] << ' ';
	}
}