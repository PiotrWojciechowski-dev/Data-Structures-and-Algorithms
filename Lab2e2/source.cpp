#include <iostream>

// https://stackoverflow.com/questions/31134757/struggling-with-partial-arrays
// Accessed on 12/10/2020
// Based on answer from logic stuff


// deleteReapets takes in the array and calls by reference the variable size
void deleteRepeats(char a[], int &size) {
    // Set a temporary variable to 0
    int temp = 0;
    // Loop over the size var
    for (int i = 0; i < size; ++i) {
        // set repeat to false in each iteration
        bool repeat = false;
        // Loop over the temp value and find if a value in the array is the same as another value in the list
        for (int j = 0; j < temp; ++j) {
            if (a[i] == a[j]) {
                repeat = true;
            }
        }
        // If repeat is not false than increment temp by 1 where the var i is at, effectively skipping over any characters that repeat.
        if (!repeat) {
            a[temp++] = a[i];
        }
    }
    // Make temp the new size
    size = temp;
    return;
}

int main() {
    // Character array of length 10 that is partially filled
    char a[10] = { 'a', 'b', 'a', 'c' };
    int size = 4;

    // Call function to delete repeats in the array
    deleteRepeats(a, size);
    
    //  Print out the new elements in the array
    for (int i = 0; i < size; i++) {
        std::cout << a[i];
    }

    return 0;
}