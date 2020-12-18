#define NODEOFINT_H
#pragma once

class NodeofInt {
	friend class ListOfInts;

	public:
		NodeofInt(int i);

	private:
		int theValue;
		NodeofInt* next;
};
typedef NodeofInt* ListNodePtr;

