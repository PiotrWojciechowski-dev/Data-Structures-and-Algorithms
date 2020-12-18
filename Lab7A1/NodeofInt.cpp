#include "NodeofInt.h"
#include <cstddef>

NodeofInt::NodeofInt(int i) : next(NULL), theValue(i) {}

int NodeofInt::getValue()
{
	return theValue;
}

NodeofInt* NodeofInt::getNext()
{
	return next;
}
