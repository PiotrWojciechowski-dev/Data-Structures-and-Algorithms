#define MYINTVECTOR_H
#pragma once

class MyIntVector {
	public:
		MyIntVector();
		~MyIntVector();
		MyIntVector(const MyIntVector& vector);

		// Move Constructer
		MyIntVector(MyIntVector&& other) noexcept;

		int size();
		int capacity();
		int& at(int i);
		const int& at(int i) const;
		int& operator[](int i);
		const int& operator[](int i) const;
		void push_back(int val);
		void resize(int i);
		MyIntVector operator =(const MyIntVector&);

		// Move Assignment operator
		MyIntVector& operator=(MyIntVector&& other);
		// Swap functionality
		void swap(MyIntVector& second);

	private:
		int* arrPtr; // pointer
		int m_size; // size of object
		int m_capacity; // capacity of object

};