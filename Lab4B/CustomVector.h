#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H
#pragma once

class vectorClass {
    private:
        // arr is the integer pointer 
        // which stores the address of our vector 
        int* arr;

        // capacity is the total storage 
        // capacity of the vector 
        int capacity;

        // current is the number of elements 
        // currently present in the vector 
        int current;

    public:
        // Default constructor to initialise 
        // an initial capacity of 1 element and 
        // allocating storage using dynamic allocation 
        vectorClass();

        // Function to add an element at the last 
        void push(int data);

        // function to add element at any index 
        void push(int data, int index);

        // function to extract element at any index 
        int get(int index);

        // function to delete last element 
        void pop();

        // function to get size of the vector 
        int size();

        // function to get capacity of the vector 
        int getcapacity();

        // function to print array elements 
        void print();
};

#endif