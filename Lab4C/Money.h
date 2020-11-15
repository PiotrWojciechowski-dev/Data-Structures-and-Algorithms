#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Money {
	public:
		Money();
		Money(int euro, int cent);
		const Money operator -(const Money&);
		const Money operator *(const Money&);
		const Money operator /(const Money&);
		bool operator ==(const Money&);
		bool operator <(const Money&);
		bool operator >(const Money&);
		friend ostream& operator <<(ostream& outputStream, const Money& aMoney);

	private:
		int euro;
		int cent;
};
