
#include "CustomVector.h"
#include <bits/stdc++.h> 
using namespace std;

// Self implementation of 
// the Vector Class in C++ 

// 1. The functions we have are displayed in the class itself. The interface of the class should show the data members 
// and the declerations of member functions. Member variables of the class although will default to private should be written
// under "private:" in our class since it also upholds principals of OOP. Overall the structure of the file should be divided so it is easier to read/bug fix.

// Solution: Seperate the file into three files, a header file that has our vector class with member variables and function declerations,
// a .cpp file for our class functions and another .cpp file for our main().

// 2. Our push function isn't very robust because it will only increase the capacity of the vector if the size is the same
// as our capacity. This only works in situations like our default constructer which sets current to be less than 1, and once we try to push
// our capcity will increase but it doesn't take into account if our size was bigger than our capacity. If it is then our program would run into a heap error.
// Also we are using more memory with our current++ since ++ creates a temporary copy of that variable

// Solution: Change our if statement so it takes into account a size larger than our capacity and change current++ to ++current so we can save on space

// 3. Our second push function is also not as robust as we want it to be especially for values that are again outside our capacity
// If our index is outside of the current size and larger than capacity our function will cause a heap error. Apart from that we never take into
// account what happens with the values between our current size up to our index. Our vector won't display correctly.

// Solution: Change our if statement so it checks if our index is greater than or equal to our capacity and if our index is at a positon that doesn't
// have any values at positions after our size make sure to populate them with 0.

// 4. Our get function isn't perfect aswell. It only checks if index is less than capcity before returning the position of index in the array.
// This doesn't work because it doesn't take into account if our index is lower than 0.

// Solution: Correct our if statement on our get function so it checks if the position we want isn't lower than 0.

// 5. The pop function does technically what it's supposed to by decreasing the size by 1 and when we display the contents of the vector
// it shows the values up to what the new size is. The problem is that our value that existed before on the old size is still there just hidden from our view.
// We want to make sure that our size is fully reduced and our memory is made smaller.

// Solution: Update our pop function so after it decreases the size we copy all the values of our array and put it into a new array than delete the temporary 
// array we created.

// Driver code
// I've change the main code slightly to test my new functions fully
int main()
{
    vectorClass v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);

    cout << "Vector size : "
        << v.size() << endl;
    cout << "Vector capacity : "
        << v.getcapacity() << endl;

    cout << "Vector elements : ";
    v.print();

    v.push(80, 7);

    cout << "\nAfter updating 1st index"
        << endl;

    cout << "Vector elements : ";
    v.print();

    cout << "Element at 1st index : "
        << v.get(1) << endl;

    v.pop();

    cout << "\nAfter deleting last element"
        << endl;

    cout << "Vector size : "
        << v.size() << endl;
    cout << "Vector capacity : "
        << v.getcapacity() << endl;

    cout << "Vector elements : ";
    v.print();

    return 0;
}