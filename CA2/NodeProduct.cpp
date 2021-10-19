// Piotr Wojciechowski X00152561
#include "NodeProduct.h"

NodeProduct::NodeProduct(int id, string type)
{
	product.id = id;
	product.type = type;
	next = NULL;
}