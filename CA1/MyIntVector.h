#pragma once
#include <iostream>
using namespace std;

class MyIntVector {
	public:

		void push_back(int value);
		void resize(int i);
		MyIntVector();
		MyIntVector(const MyIntVector& vector);
		~MyIntVector();
		const int& operator[](int i) const;
		void copyConstructer(const MyIntVector& newVector);
		void operator =(const MyIntVector&);
		friend ostream& operator <<(ostream& outputStream, const MyIntVector& aVector);
		const MyIntVector operator +(const MyIntVector&);

	private:
		int* arrPtr;
		int m_size;
		int m_capacity;

};