#include <iostream>
#include <iomanip>
#include <fstream>

// Function that redisplays the menu each time its called
void menu() {
	std::cout << std::string(12, '*') << " Shop Menu " << std::string(12, '*') << "\n\n";
	std::cout << std::setw(6) << "1." << std::setw(11) << "Purchase\n";
	std::cout << std::setw(6) << "2." << std::setw(19) << "Increase a price\n";
	std::cout << std::setw(6) << "3." << std::setw(20) << "Exit Application\n\n";
	std::cout << std::string(35, '*') << "\n";
	return;
}

// Function that calls the item prices by value and references the variable final_cost
// The quantity is inputted for each item and the final_cost var is referenced and updated each time
// The total is then displayed and we return to the end of the call.
void purchase(double price1, double price2, double price3, double &total) {
	int user_quant;
	std::cout << "Enter in quantity for the 1st item: ";
	std::cin >> user_quant;
	total += user_quant * price1;
	std::cout << "Enter in quantity for the 2nd item: ";
	std::cin >> user_quant;
	total += user_quant * price2;
	std::cout << "Enter in quantity for the 3rd item: ";
	std::cin >> user_quant;
	total += user_quant * price3;
	std::cout << std::endl << "The total price is: €"  << total << "\n\n";
	return;
}

// Function that calls by references the variables of each item
// User is asked which item do they want to update and by what percentage
// The function ends and the Item list is redisplayed with their new values
bool increase_price(double& price1, double& price2, double& price3) {
	int item;
	double percentage;
	std::cout << "Which item do you want to update the price for? ";
	std::cin >> item;
	switch (item) {
		case 1:
			std::cout << "By what percentage do you want to update item " << item << ": ";
			std::cin >> percentage;
			price1 = price1 * (1 + percentage / 100);
			return price1;
		case 2:
			std::cout << "By what percentage do you want to update item " << item << ": ";
			std::cin >> percentage;
			price2 = price2 * (1 + percentage / 100);
			return price2;
		case 3:
			std::cout << "By what percentage do you want to update item " << item << ": ";
			std::cin >> percentage;
			price3 = price3 * (1 + percentage / 100);
			return price3;
		default:
			std::cout << "Item out of range! Please try again\n";
	}
	return 0;
}

int main() {

	double price1 = 10;
	double price2 = 15;
	double price3 = 12;
	double final_cost = 0.0;
	int user_input;

	std::cout << std::string(14, '*') << " Items " << std::string(14, '*') << "\n\n";
	std::cout << std::setw(5) << '1' << std::setw(10) << "Widget: " << std::setw(8) << "cost €" << price1 << "\n";
	std::cout << std::setw(5) << '2' << std::setw(10) << "Gadget: " << std::setw(8) << "cost €" << price2 << "\n";
	std::cout << std::setw(5) << '3' << std::setw(10) << "Toggle: " << std::setw(8) << "cost €" << price3 << "\n\n";

	menu();
	std::cout << "Enter in a menu option\n";
	std::cin >> user_input;
	while (user_input != 3) {
		switch (user_input) {
		case 1:
			purchase(price1, price2, price3, final_cost);
			break;
		case 2:
			increase_price(price1, price2, price3);
			std::cout << std::string(14, '*') << " Items " << std::string(14, '*') << "\n\n";
			std::cout << std::setw(5) << '1' << std::setw(10) << "Widget: " << std::setw(8) << "cost €" << price1 << "\n";
			std::cout << std::setw(5) << '2' << std::setw(10) << "Gadget: " << std::setw(8) << "cost €" << price2 << "\n";
			std::cout << std::setw(5) << '3' << std::setw(10) << "Toggle: " << std::setw(8) << "cost €" << price3 << "\n\n";
			break;
		default:
			std::cout << "Incorrect Input! Please try again\n";
			break;
		}
		menu();
		std::cout << "Enter in a number\n";
		std::cin >> user_input;
	}
	std::fstream myFile;
	myFile.open("prices.txt", std::fstream::out );

	myFile << "The total price is: €" << final_cost << "\n\n";;

	myFile.close();

	return 0;
}