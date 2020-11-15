#pragma once
#include <iostream>
using namespace std;

class Percent {
	public:
		//friend bool operator ==(const Percent& first, const Percent& second);
		//friend bool operator <(const Percent& first, const Percent& second);
		bool operator ==(const Percent&);
		bool operator <(const Percent&);
		Percent();
		Percent(int value);
		friend istream& operator >>(istream& inputStream, Percent& aPercent);
		friend ostream& operator <<(ostream& outputStream, const Percent& aPercent);
		// There will be other members and friends.
		const Percent operator +(const Percent&);
		const Percent operator -(const Percent&);
		const Percent operator *(const Percent&);
	private:
		int value;
};
