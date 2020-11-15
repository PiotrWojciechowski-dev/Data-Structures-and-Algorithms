// Piotr Wojciechowski
// X00152561

#include "MyIntVector.h"
#include <iostream>
using namespace std;

int main()
{
    MyIntVector vector1;
    MyIntVector vector2;

    // Push Back the value at the end of the vector
    vector1.push_back(2);
    cout << vector1;
    cout << endl;
    cout << vector2;
    cout << endl;
    cout << endl;

    vector1.resize(5);
    cout << vector1;
    cout << endl;

    cout << vector1[2];
    cout << endl;
    cout << vector1[6];

    cout << endl;
    //cout << vector1 + vector2;

    MyIntVector vector3 = vector1;
    cout << vector3;

    // Assignment operator not working
    //MyIntVector vector4;
    //vector4 = vector1;

}