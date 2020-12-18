#define STACKOFINT_H
#include "ListOfInts.h"
#pragma once
#include <iostream>
using namespace std;

class StackOfInt
{

	public:

		StackOfInt(ListOfInts list);
		void push(double val);
		void pop();
		int top();
		friend ostream& operator<<(ostream& str, StackOfInt& stackobj);

	private:
		ListOfInts l;
};