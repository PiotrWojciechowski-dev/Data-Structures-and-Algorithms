// Piotr Wojciechowski X00152561
#include "Product.h"
#include "ListProduct.h"
#include "NodeProduct.h"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Product Program\n";
    // Create Product objects
    ListProduct list1;

    list1.addProduct(1, "dvd");
    list1.addProduct(2, "book");
    list1.addProduct(3, "book");
    list1.addProduct(4, "book");
    list1.addProduct(5, "stationary");
    list1.addProduct(6, "stationary");

    list1.displayType("dvd");
    list1.displayType("book");
    list1.displayType("stationary");
    cout << endl;

    // Delete Product
    if (list1.deleteProduct(1) == true) {
        cout << "Product has been deleted\n";
    } else {
        cout << "Product was not found\n";
    }

    if (list1.deleteProduct(2) == true) {
        cout << "Product has been deleted\n";
    } else {
        cout << "Product was not found\n";
    }

    if (list1.deleteProduct(7) == true) {
        cout << "Product has been deleted\n";
    } else {
        cout << "Product was not found\n";
    }

    cout << endl;
    list1.displayType("dvd");
    list1.displayType("book");
    list1.displayType("stationary");
    cout << endl;

    // Copy constructer
    ListProduct list2(list1);
    list2.displayType("dvd");
    list2.displayType("book");
    list2.displayType("stationary");
    cout << endl;

    // Assignment operator
    ListProduct list3;
    list3 = list1;

    list3.displayType("dvd");
    list3.displayType("book");
    list3.displayType("stationary");
    cout << endl;

}
