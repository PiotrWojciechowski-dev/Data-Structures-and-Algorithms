#include "MyIntVector.h"

void MyIntVector::push_back(int value){
	if (m_size >= m_capacity) {
		resize(m_capacity * 2);
	}

	arrPtr[m_size] = value;
	++m_size;
}

void MyIntVector::resize(int i){
	if (i < 0) {
		cout << "\nCan't make the vector smaller than 0\n";
		return;
	}

	if (i > m_capacity) {
		// If i is greater than capacity, create a new array and copy contents of old one
		int* arr = new int[i];
		for (int i = 0; i < m_capacity; ++i) {
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

MyIntVector::MyIntVector() : m_size(10), m_capacity(10) {
	arrPtr = new int[m_capacity];
	for (size_t i = 0; i < m_capacity; i++) {
		arrPtr[i] = i;
	}
}

MyIntVector::MyIntVector(const MyIntVector& vector){
}

MyIntVector::~MyIntVector(){
	delete[] arrPtr;
}

const int& MyIntVector::operator[](int i) const{
	if (i < 0 || i >= m_size) {
		return -1;
	}
	else {
		return arrPtr[i];
	}
}

void MyIntVector::copyConstructer(const MyIntVector& newVector){
	m_size = newVector.m_size;
	m_capacity = newVector.m_capacity;
	arrPtr = new int[m_capacity];
	for (size_t i = 0; i < m_size; i++) {
		arrPtr[i] = newVector.arrPtr[i];
	}
}

void MyIntVector::operator=(const MyIntVector& rhs){
	delete[] arrPtr;

	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	for (size_t i = 0; i < m_size; i++) {
		arrPtr[i] = rhs.arrPtr[i];
	}
}

const MyIntVector MyIntVector::operator+(const MyIntVector& rhs){

	MyIntVector sumVector;
	for (size_t i = 0; i < m_size; i++) {
		arrPtr[i] += rhs.arrPtr[i];
		//sumVector[i] = arrPtr[i];
	}
	return sumVector;
}

ostream& operator<<(ostream& outputStream, const MyIntVector& aVector){
	for (int i = 0; i < aVector.m_size; i++) {
		outputStream << aVector.arrPtr[i] << " ";
	}
	return outputStream;
}
