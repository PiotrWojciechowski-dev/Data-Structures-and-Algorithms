#include <iostream>

// Constant variable options for the type and size of pizza
const int DEEPDISH = 1, HANDTOSSED = 2, PAN = 3;
const int SMALL = 1, MEDIUM = 2, LARGE = 3;

// Class Pizza member variables are private and member functions are public
class Pizza {
    public:
        Pizza();
        int getType();
        int getSize();
        int computePrice();
        bool getCheese();
        bool getPepperoni();
        void setType(int type);
        void setSize(int size);
        void setCheese(bool c);
        void setPepperoni(bool p);
        void outputDescription();

    private:
        int type;
        int size;
        bool cheese;
        bool pepperoni;

};

// Default initialiser for the class 
Pizza::Pizza()
{
    type = DEEPDISH;
    size = SMALL;
    cheese = pepperoni = false;
}

// Getters for member variables
int Pizza::getType() {
    return type;
}
int Pizza::getSize() {
    return size;
}
bool Pizza::getCheese() {
    return cheese;
}
bool Pizza::getPepperoni() {
    return pepperoni;
}

// Setters for member variables
void Pizza::setType(int t) {
    type = t;
}
void Pizza::setSize(int s) {
    size = s;
}
void Pizza::setCheese(bool c) {
    cheese = c;
}
void Pizza::setPepperoni(bool p) {
    pepperoni = p;
}

// Compute price of pizza based on the inputs from the user
int Pizza::computePrice()
{
    int cost = 0;

    switch (size)
    {
    case SMALL:
        cost += 10;
        break;
    case MEDIUM:
        cost += 14;
        break;
    case LARGE:
        cost += 17;
        break;
    }

    // If any of the toppings is true add 2 euro to the cost
    if (pepperoni)
        cost += 2;
    if (cheese)
        cost += 2;
    return cost;
}

// Display the pizza you have made
void Pizza::outputDescription() {

    switch (size) {
    case 1:
        std::cout << "Small ";
        break;
    case 2:
        std::cout << "Medium ";
        break;
    case 3:
        std::cout << "Large ";
        break;
    default:
        std::cout << "Unkown size ";
    }

    switch (type) {
    case 1:
        std::cout << "deepdish ";
        break;
    case 2:
        std::cout << "hand tossed ";
        break;
    case 3:
        std::cout << "pan ";
        break;
    default:
        std::cout << "unkown type ";
    }

    std::cout << "pizza with " << pepperoni << " pepperoni and "
        << cheese << " cheese toppings.";
}


int main() {
    int type, size, in_type, in_size;
    char topping;
    // Ask the user for what type of pizza they would like and if they say something other than 1-3 default the type to 0
    // which will output the type as unknown later on
    std::cout << "What pizza type would you like? Please enter type number; Deepdish(1) / Hand-tossed(2) / Pan (3): ";
    std::cin >> in_type;
    
    switch (in_type) {
        case 1:
            type = DEEPDISH;
            break;
        case 2:
            type = HANDTOSSED;
            break;
        case 3:
            type = PAN;
            break;
        default:
            type = 0;
    }

    // Ask the user for what size of pizza they would like and if they say something other than 1-3 default the type to 0
    // which will output the size as unknown later on
    std::cout << "What pizza size would you like? Please enter size number; Small(1) / Medium (2) / Large (3): ";
    std::cin >> in_size;
    switch (in_size) {
        case 1:
            size = SMALL;
            break;
        case 2:
            size = MEDIUM;
            break;
        case 3:
            size = LARGE;
            break;
        default:
            size = 0;
    }

    // Default pizza
    Pizza custPizza;
    custPizza.setType(type);
    custPizza.setSize(size);

    // Ask user if they want pepperoni on their pizza
    std::cout << "Would you like to top your pizza with pepperoni? (Y/N)? ";
    std::cin >> topping;
    if (topping == 'Y' || topping == 'y')
        custPizza.setPepperoni(true);

    // Ask user if they want cheese on their pizza
    std::cout << "Would you like to top your pizza with cheese? (Y/N)? ";
    std::cin >> topping;
    if (topping == 'Y' || topping == 'y')
        custPizza.setCheese(true);

    std::cout << std::endl << "Your Pizza: ";
    custPizza.outputDescription();
    std::cout << "\n";
    std::cout << "Order total: �" << custPizza.computePrice() << "\n";

    return 0;
}