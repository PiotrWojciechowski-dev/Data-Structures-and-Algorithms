#include "MyIntVector.h"
#include "ListOfInts.h"
#include "StackOfInt.h"
#include <iostream>
using namespace std;

int main()
{
	// Create Object MyIntVector
	MyIntVector vector1, vector2;

	// Push Back the value at the end of the vector and resize if the size is greater than or equal to the capacity
	vector1.push_back(2);

	std::cout << "This is the contents of the first vector: " << std::endl;
	for (size_t i = 0, ilen = vector1.size(); i < ilen; ++i) {
		std::cout << vector1.at(i);
	}
	cout << endl;

	vector2.swap(vector1);

	std::cout << "This is the contents of the second vector: " << std::endl;
	for (size_t i = 0, ilen = vector2.size(); i < ilen; ++i) {
		std::cout << vector2.at(i);
	}
	cout << endl;

	std::cout << "This is the contents of the first vector: " << std::endl;
	for (size_t i = 0, ilen = vector1.size(); i < ilen; ++i) {
		std::cout << vector1.at(i);
	}
	cout << endl << endl;

	ListOfInts l1;
	StackOfInt stack(l1);
	// Push Test
	stack.push(10.10);
	stack.push(20.20);
	stack.push(30.30);
	stack.push(40.40);
	stack.push(50.50);

	cout << "Print stack contents: " << endl;
	cout << stack;

	// Test pop and top stack
	stack.pop();

	cout << "Get the top item of the stack: " << endl;
	int item = stack.top();
	cout << item << endl;
	cout << endl;

	cout << "Print stack contents: " << endl;
	cout << stack;

	return 0;

}