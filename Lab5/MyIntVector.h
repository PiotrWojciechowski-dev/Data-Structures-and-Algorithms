#pragma once

class MyIntVector {
	public:
		MyIntVector();
		MyIntVector(const MyIntVector& vector);
		~MyIntVector();

		int size();
		int capacity();
		int& at(int i);
		const int& at(int i) const;
		int& operator[](int i);
		const int& operator[](int i) const;
		void push_back(int val);
		void resize(int i);
		MyIntVector operator =(const MyIntVector&);

	private:
		int* arrPtr; // pointer
		int m_size; // size of object
		int m_capacity; // capacity of object

};