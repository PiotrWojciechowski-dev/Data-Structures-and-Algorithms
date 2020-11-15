#include <iostream>

class PizzaStore {
    public:
        PizzaStore(int id);

        int getSold();
        void incrementTotal();
        void justSold();

        static int getTotal() {
            return total;
        }

    private:
        int store_id, pizza_count;
        static int total;

};

int PizzaStore::total = 0;

PizzaStore::PizzaStore(int id) {
    store_id = id;
    pizza_count = 0;
    total = 0;
}

int PizzaStore::getSold() {
    return pizza_count;
}

void PizzaStore::justSold() {
    pizza_count += 1;
}

void PizzaStore::incrementTotal() {
    total++;
}

int main()
{
    char input;

    PizzaStore store_1 = PizzaStore(1);
    PizzaStore store_2 = PizzaStore(2);
    PizzaStore store_3 = PizzaStore(3);

    std::cout << "Would you like to add a pizza at store 1? (Y/N) ";
    std::cin >> input;
    while (input == 'Y' || input == 'y') {
        store_1.justSold();
        store_1.incrementTotal();
        std::cout << "Would you like to add another pizza at Store 1? (Y/N) ";
        std::cin >> input;
    }
    std::cout << "\nThe total number of pizzas sold at Store 1 is: " << store_1.getSold() << "\n\n";


    std::cout << "Would you like to add a pizza at Store 2? (Y/N) ";
    std::cin >> input;
    while (input == 'Y' || input == 'y') {
        store_2.justSold();
        store_2.incrementTotal();
        std::cout << "Would you like to add another pizza at Store 2? (Y/N) ";
        std::cin >> input;
    }
    std::cout << "\nThe total number of pizzas sold at Store 2 is: " << store_2.getSold() << "\n\n";


    std::cout << "Would you like to add a pizza at Store 3? (Y/N) ";
    std::cin >> input;
    while (input == 'Y' || input == 'y') {
        store_3.justSold();
        store_3.incrementTotal();
        std::cout << "Would you like to add another pizza at Store 3? (Y/N) ";
        std::cin >> input;
    }
    std::cout << "The total number of pizzas sold at Store 3 is: " << store_3.getSold() << "\n\n";


    std::cout << "The total number of pizzas sold is: " << PizzaStore::getTotal() << "\n";
    std::cout << "Program end";

    return 0;
}