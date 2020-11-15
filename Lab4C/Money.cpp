#include "Money.h"

Money::Money(){
	euro = 0;
	cent = 0;
}

Money::Money(int euro, int cent) : euro(euro), cent(cent) {}

// Take away two amounts from eachother and return a new money object
const Money Money::operator-(const Money& money)
{
	int totalCentsDiff = (cent + (euro * 100)) - (money.cent + (money.euro * 100));
	int absAllCents = abs(totalCentsDiff);
	int newEuro = absAllCents / 100;
	int newCent = absAllCents % 100;

	if (totalCentsDiff < 0) {
		newEuro = -newEuro;
	}
	return Money(newEuro, newCent);
}

// Multiply the money object to the left of the operator by two
const Money Money::operator*(const Money&)
{
	int totalCentsProduct = (cent + (euro * 100)) * 2;
	int absAllCents = abs(totalCentsProduct);
	int newEuro = absAllCents / 100;
	int newCent = absAllCents % 100;

	if (totalCentsProduct < 0) {
		newEuro = -newEuro;
	}
	return Money(newEuro, newCent);
}

// Divide the money object to the left of the operator by two
const Money Money::operator/(const Money&)
{
	int totalCentsQuotient = (cent + (euro * 100)) / 2;
	int absAllCents = abs(totalCentsQuotient);
	int newEuro = absAllCents / 100;
	int newCent = absAllCents % 100;

	if (totalCentsQuotient < 0) {
		newEuro = -newEuro;
	}
	return Money(newEuro, newCent);
}

// Compare the money objects against eachother to see if they are equal
bool Money::operator==(const Money& money)
{
	return (euro == money.euro) && (cent == money.cent);
}

// Check if money object to the right of the operator < is greater than the amount
// to the left. If the euro amounts are the same, compare the cents.
bool Money::operator<(const Money& money)
{	
	if (euro == money.euro) {
		if (cent < money.cent) {
			return true;
		}
	}
	return (euro < money.euro);
}

// Check if money object to the left of the operator > is greater than the amount
// to the right. If the euro amounts are the same, compare the cents.
bool Money::operator>(const Money& money)
{
	if (euro == money.euro) {
		if (cent > money.cent) {
			return true;
		}
	}
	return (euro > money.euro);
}


// Display money object
ostream& operator<<(ostream& outputStream, const Money& aMoney) {
	if (aMoney.euro < 0 || aMoney.cent < 0) {
		outputStream << "€-";
	} else {
		outputStream << "€";
	}
	outputStream << abs(aMoney.euro);

	if (abs(aMoney.cent) >= 10) {
		outputStream << '.' << abs(aMoney.cent);
	} else {
		outputStream << '.' << '0' << abs(aMoney.cent);
	}
	return outputStream;
}
