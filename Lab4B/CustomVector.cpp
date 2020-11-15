// I'm assuming that we are required to create a bits folder with stdc++.h 
// Although in my opinion this is overkill for the amount of libraties we are including
// and at least for this lab we would be better off using just <iostream> 
#include "CustomVector.h"
#include <bits/stdc++.h> 
using namespace std;

// Default constructor to initialise 
// an initial capacity of 1 element and 
// allocating storage using dynamic allocation 
vectorClass::vectorClass()
{
    arr = new int[1];
    capacity = 1;
    current = 0;
}

// Function to add an element at the last 
void vectorClass::push(int data)
{

    // if the number of elements is equal to the capacity, 
    // that means we don't have space 
    // to accommodate more elements. 
    // We need to double the capacity 
    if (current >= capacity) {
        int* temp = new int[2 * capacity];

        // copying old array elements to new array 
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }

        // deleting previous array 
        delete[] arr;
        capacity *= 2;
        arr = temp;
    }

    // Inserting data 
    arr[current] = data;
    ++current;
}

// function to add element at any index 
void vectorClass::push(int data, int index)
{

    // if index is equal to capacity then this 
    // function is same as push defined above 
    if (index >= current) {
        for (current; current < index; current++) {
            arr[current] = 0;
        }
        push(data);
    }
    else {
        arr[index] = data;
    }
    cout << capacity;
}

// function to extract element at any index 
int vectorClass::get(int index)
{

    // if index is within the range 
    int badreturn = -1;
    if (index < 0 || index >= current) {
        std::cout << "Element is out of bounds" << std::endl;
        return badreturn;
    }
    else {
        return arr[index];
    }
}

// function to delete last element 
void vectorClass::pop()
{
    current--;
    int* arr_new = new int[current];
    for (int i = 0; i < current; ++i) {
        arr_new[i] = arr[i];
    }
    delete[] arr;
    arr = arr_new;
}

// function to get size of the vector 
int vectorClass::size()
{
    return current;
}

// function to get capacity of the vector 
int vectorClass::getcapacity()
{
    return capacity;
}

// function to print array elements 
void vectorClass::print()
{
    for (int i = 0; i < current; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
