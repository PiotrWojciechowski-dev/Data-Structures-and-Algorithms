#include "Percent.h"
#include "Money.h"
#include <iostream>
using namespace std;

// https://elearning-ta.tudublin.ie/pluginfile.php/249607/mod_resource/content/2/Absolute_C%2B%2B_%285th_Edition%29.pdf?forcedownload=1
// Accessed on 3/11/2020
// Used examples in chapter 8 using money to solve question 4 and 5.
int main() {

	// Q4

	Percent value1, value2;
	cout << "When entereing values include % as the last character\n";
	cout << "Enter in a percentage value: ";
	cin >> value1;
	cout << "Enter in a percentage value: ";
	cin >> value2;
	cout << endl;

	cout << "Your first percentage value is: " << value1 << endl;
	cout << "Your second percentage value is: " << value2 << endl;

	if (value1 == value2) {
		cout << "Values are the same percentage" << endl;
	} else if (value1 < value2) {
		cout << "Second percentage is bigger than the first one" << endl;
	} else {
		cout << "First percentage is bigger than the second one" << endl;
	}

	cout << endl;
	cout << "Adding the two percentages gives: " << value1 + value2 << endl;

	cout << "Subtracting the two percentages gives: " << value1 - value2 << endl;

	cout << "Multiplying the two percentages gives: " << value1 * value2 << endl;

	// Q5

	int euro, cent;
	cout << "Enter in euro for the first amount: ";
	cin >> euro;
	cout << "Enter in cent for the first amount: ";
	cin >> cent;
	Money amount1(euro, cent);
	cout << amount1;
	cout << endl;
	cout << "Enter in euro for the second amount: ";
	cin >> euro;
	cout << "Enter in cent for the second amount: ";
	cin >> cent;
	Money amount2(euro, cent);
	cout << amount2;
	cout << endl;
	if (amount1 == amount2) {
		cout << "Both amounts are the same" << endl;
	}
	if (amount1 < amount2) {
		cout << "Second amount is bigger than fist amount" << endl;
	}
	if (amount1 > amount2) {
		cout << "First amount is bigger than second amount" << endl;
	}
	cout << amount1 - amount2;
	cout << endl;
	cout << amount1 * amount2;
	cout << endl;
	cout << amount1 / amount2;

	return 0;
}