#include "ListProduct.h"
#include "NodeProduct.h"
#include <iostream>
using namespace std;

ListProduct::ListProduct() {
	head = NULL;
}

ListProduct::~ListProduct() {
	while (head != NULL) {
		ProductNode temp = head;
		head = head->next;
		delete temp;
	}
}

ListProduct::ListProduct(const ListProduct& p) {
	*this = p;
}

ListProduct::ListProduct(ListProduct&& rhs) noexcept {
	swap(rhs);
}

void ListProduct::addProduct(int id, string type) {
	ProductNode newNode = new NodeProduct(id, type);
	newNode->next = head;

	head = newNode;
}

void ListProduct::displayType(string typeToFind) {
	ProductNode temptr = head;
	while (temptr != NULL) {
		if (temptr->product.type == typeToFind) {
			cout << "ID " << temptr->product.id << " is a " << temptr->product.type << endl;
		}
		temptr = temptr->next;
	}
}

bool ListProduct::deleteProduct(int idToDelete)
{
	ProductNode temptr = head;
	ProductNode trailptr = NULL;
	if (head->product.id == idToDelete) {
		head = head->next;
		delete temptr;
		return true;
	}
	else {
		while (temptr != NULL && temptr->product.id != idToDelete) {
			trailptr = temptr;
			temptr = temptr->next;
		}
	}
	if (temptr == NULL) {
		return false;
	}
	else {
		trailptr->next = temptr->next;
		delete temptr;
		return true;
	}
	return false;
}

ListProduct& ListProduct::operator=(const ListProduct& p)
{
	if (this != &p) {
		if (head != NULL) {
			this->~ListProduct();
		}
		ProductNode trailptr = NULL;
		ProductNode temptr = p.head;
		while (temptr != NULL) {
			if (head == NULL) {
				head = new NodeProduct(temptr->product.id, temptr->product.type);
				trailptr = head;
			}
			else {
				trailptr->next = new NodeProduct(temptr->product.id, temptr->product.type);
				trailptr = trailptr->next;
			}
			temptr = temptr->next;
		}

	}
	return *this;
}

ListProduct& ListProduct::operator=(ListProduct&& rhs)
{
	rhs.swap(*this);
	return *this;
}

void ListProduct::swap(ListProduct& other) {
	using std::swap;
	swap(head, other.head);
}
