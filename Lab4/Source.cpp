#include "MyIntVector.h"
#include <iostream>

int main() {
	// Create Object MyIntVector
	MyIntVector vector1;

	// Get the size of vector
	std::cout << "Size of vector 1 is: " << vector1.size() << std::endl;

	// Get the capacity of vector
	std::cout << "Capacity of vector 1 is: " << vector1.capacity() << std::endl;

	// Push Back the value at the end of the vector and resize if the size is greater than or equal to the capacity
	vector1.push_back(2);
	std::cout << "Capacity of vector 1 is: " << vector1.capacity() << std::endl;

	// Get the value in the array at a certain position using .at
	vector1.at(4) = 3;
	std::cout << "The element at position using .at 2 is: " << vector1.at(4) << std::endl;

	// Test if the number is out of bounds using .at
	std::cout << "The element at position 2 using .at is: " << vector1.at(21) << std::endl;

	// Overload the operator at a position with a value
	// Get the value in the array at a certain position using operator[]
	vector1[0] = 8;
	std::cout << "The element at position 2 using operator[] is: " << vector1[0] << "\n\n";

	std::cout << "This is the contents of the vector: " << std::endl;
	for (size_t i = 0, ilen = vector1.size(); i < ilen; ++i) {
		std::cout << vector1.at(i);
	}

	// Resize the vector to show that we populated it with 0's without increasing capacity
	vector1.resize(14);
	std::cout << "\n\nSize of vector 1 is: " << vector1.size() << std::endl;
	std::cout << "This is the contents of the vector: " << std::endl;
	for (size_t j = 0, jlen = vector1.size(); j < jlen; ++j) {
		std::cout << vector1.at(j);
	}

	// Resize the vecotr to something that is smaller than the current size
	vector1.resize(5);
	std::cout << "\n\nSize of vector 1 is: " << vector1.size() << std::endl;
	std::cout << "This is the contents of the vector: " << std::endl;
	for (size_t j = 0, jlen = vector1.size(); j < jlen; ++j) {
		std::cout << vector1.at(j);
	}
	std::cout << "\n\n";

	// Check what happens when the size is the same as the current one
	vector1.resize(10);
	std::cout << "Size of vector 1 is: " << vector1.size() << std::endl;

	//Check what happens when the size is smaller than 0
	vector1.resize(-1);

	return 0;
}