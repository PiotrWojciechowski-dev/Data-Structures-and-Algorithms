#include "Percent.h"
#include <iostream>
#include <string>
using namespace std;

Percent::Percent() {
	value = 0;
}

Percent::Percent(int value) : value(value) {}


istream& operator >>(istream& inputStream, Percent& aPercent) {
	// http://www.tulane.edu/~mpuljic/cpp/savitch/chapter08.pdf
	// Accessed on 4/11/2020
	// Used code on page 514 to create a faster way to read up to '%' and return just the value
	char percent;
	inputStream >> aPercent.value;
	inputStream >> percent; //Discards the % sign
	return inputStream;
}

ostream& operator <<(ostream& outputStream, const Percent& aPercent) {
	outputStream << aPercent.value << '%' << endl;
	return outputStream;
}
/* Commented out the original code to make the two operators as member functions
bool operator ==(const Percent& first, const Percent& second) {
	return first.value == second.value;
}

bool operator <(const Percent& first, const Percent& second) {
	return first.value < second.value;
}
*/

// Check if the percent values are equal
bool Percent::operator ==(const Percent& percent) {
	return value == percent.value;
}

// Check if the percent value to the right of the operator is greater than the operand to the left
bool Percent::operator <(const Percent& percent) {
	return value < percent.value;
}

// Add percent values
const Percent Percent::operator +(const Percent& percent) {
	int newPercent = (value + percent.value);
	return Percent(newPercent);
}

// Subtract percent values
const Percent Percent::operator -(const Percent& percent) {
	int newPercent = (value - percent.value);
	return Percent(newPercent);
}

// Multiply percent values
const Percent Percent::operator *(const Percent& percent) {
	int newPercent = (value * percent.value) / 100;
	return Percent(newPercent);
}

