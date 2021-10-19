// Piotr Wojciechowski X00152561
#define NODEPRODUCT_H
#pragma once
#include "Product.h"

class NodeProduct {

	friend class ListProduct;

	public:
		NodeProduct(int id, string type);
	private:
		Product product;
		NodeProduct* next;
};
typedef NodeProduct* ProductNode;