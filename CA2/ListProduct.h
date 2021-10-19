// Piotr Wojciechowski X00152561
#define LISTPRODUCT_H
#pragma once
#include "NodeProduct.h"

class ListProduct {

	friend class NodeOfEmployee;

	public: 
		ListProduct();
		~ListProduct();
		ListProduct(const ListProduct& p);
		ListProduct(ListProduct&& rhs) noexcept;
		void addProduct(int id, string type);
		void displayType(string typeToFind);
		bool deleteProduct(int idToDelete);
		ListProduct& operator=(const ListProduct& p);
		ListProduct& operator=(ListProduct&& rhs);
		void swap(ListProduct& second);

	private:
		NodeProduct* head;
};