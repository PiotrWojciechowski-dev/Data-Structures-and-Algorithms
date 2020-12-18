#include "StackOfInt.h"
#include <iostream>
using namespace std;

StackOfInt::StackOfInt(ListOfInts list){
	l = list;
}

void StackOfInt::push(double val) {
	l.insertBack(val);
}

void StackOfInt::pop()
{
	l.deleteMostRecent();
}

int StackOfInt::top()
{
	NodeofInt* temp = l.head;
	return temp->getValue();
}

ostream& operator<<(ostream& str, StackOfInt& stackobj)
{
	stackobj.l.displayList();
	return str;
}