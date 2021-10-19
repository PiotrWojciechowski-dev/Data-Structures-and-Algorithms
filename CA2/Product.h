// Piotr Wojciechowski X00152561
#pragma once
#define PRODUCT_H
#include <string>
using namespace std;

class Product
{
	friend class NodeProduct;
	friend class ListProduct;

	public:
		Product();

	private:
		int id;
		string type;

};