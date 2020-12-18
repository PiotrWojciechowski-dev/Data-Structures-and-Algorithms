#define NODEOFINT_H
#pragma once

class NodeofInt {

	friend class ListOfInts;
	friend class StackOfInt;

	public:
		NodeofInt(int i);
		int getValue();
		NodeofInt* getNext();


	private:
		int theValue;
		NodeofInt* next;
};