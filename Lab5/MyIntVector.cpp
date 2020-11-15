#include "MyIntVector.h"
#include <iostream>
using namespace std;

MyIntVector::MyIntVector() : m_size(10), m_capacity(10) {
	arrPtr = new int[m_capacity];
	for (size_t i = 0; i < m_capacity; i++) {
		// Change 0 to i to create an array of different numbers
		// to make sure that the program definitely works
		arrPtr[i] = i;
	}
}

MyIntVector::~MyIntVector() {
	delete[] arrPtr;
}

MyIntVector::MyIntVector(const MyIntVector& vector) {
	m_size = vector.m_size;
	m_capacity = vector.m_capacity;
	arrPtr = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		arrPtr[i] = vector.arrPtr[i];
	}
}

// Get the size of the vector
int MyIntVector::size() {
	return m_size;
}

// Get the capacity of vector
int MyIntVector::capacity() {
	return m_capacity;
}

// Put the value at the end of the array
void MyIntVector::push_back(int val) {
	if (m_size >= m_capacity) {
		resize(m_capacity * 2);
	}

	arrPtr[m_size] = val;
	++m_size;
}

// Resize the array depending on what the full size the user wants to set it to
void MyIntVector::resize(int i) {
	if (i < 0) {
		std::cout << "\nCan't make the vector smaller than 0\n";
		return;
	}

	if (i > m_capacity) {
		// If i is greater than capacity, create a new array and copy contents of old one
		int* arr = new int[i];
		for (int i = 0; i < m_size; ++i) {
			arr[i] = arrPtr[i];
		}
		m_capacity = i;
		delete[] arrPtr;
		arrPtr = arr;
	}
	else if (i > m_size && i < m_capacity) {
		for (m_size; m_size < i; m_size++) {
			arrPtr[m_size] = 0;
		}
		m_size = i;
	}
	else if (i < m_size) {
		m_size = i;
	}
	else {
		return;
	}
}

int& MyIntVector::at(int i) {
	int badreturn = -1;
	if (i < 0 || i >= m_size) {
		std::cout << "Element is out of bounds" << std::endl;
		return badreturn;
	}
	else {
		return arrPtr[i];
	}
}

const int& MyIntVector::at(int i) const {
	if (i < 0 || i >= m_size) {
		std::cout << "Element is out of bounds" << std::endl;
		return -1;
	}
	else {
		return arrPtr[i];
	}
}

int& MyIntVector::operator[](int i) {
	return arrPtr[i];
}

const int& MyIntVector::operator[](int i) const {
	return arrPtr[i];
}

MyIntVector MyIntVector::operator=(const MyIntVector& rhs) {
	if (this != &rhs) {
		delete[] arrPtr;

		m_size = rhs.m_size;
		m_capacity = rhs.m_capacity;

		arrPtr = new int[m_capacity];
		for (int i = 0; i < m_size; ++i) {
			arrPtr[i] = rhs.arrPtr[i];
		}
	}
	return MyIntVector();
}
