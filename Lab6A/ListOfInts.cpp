#include "ListOfInts.h"
#include <iostream>
using namespace std;

ListOfInts::ListOfInts() {
	head = nullptr;
}

ListOfInts::~ListOfInts() {
	while (head) {
		ListNodePtr temptr = head;

		head = head->next;

		delete temptr;
	}
}

ListOfInts::ListOfInts(ListOfInts&& other) noexcept : ListOfInts() {
	swap(other);
}

ListOfInts::ListOfInts(const ListOfInts& l)
{
	*this = l;
}

//adds node to the back of the list
void ListOfInts::insertBack(int i) {
	NodeofInt* newNode = new NodeofInt(i);
	newNode-> next = head;

	head = newNode;
}

// Display list of nodes until temporary ptr is NULL
void ListOfInts::displayList() {
	ListNodePtr tempptr = head;
	while (tempptr != NULL) {
		cout << tempptr->theValue << endl;
		tempptr = tempptr->next;
	}
}

// Delete the most recent value added to the list
int ListOfInts::deleteMostRecent() {
	ListNodePtr deleteptr = head;
	head = head->next;
	return deleteptr->theValue;
	delete deleteptr;
}

// Delete the value we pass into the function by traversing the list until the value is found
// If the leading ptr is NULL then return else update the tail ptr
void ListOfInts::deleteInt(int value) {
	ListNodePtr temptr = head;
	ListNodePtr trailptr = NULL;
	if (head->theValue == value) {
		head = head->next;
		delete temptr;
	}
	else {
		while (temptr != NULL && temptr->theValue != value) {
			trailptr = temptr;
			temptr = temptr->next;
		}
	}
	if (temptr == NULL) {
		return;
	}
	else {
		trailptr->next = temptr->next;
		delete temptr;
	}
}

ListOfInts& ListOfInts::operator=(const ListOfInts& l)
{
	if (this != &l) {
		if (head != NULL) this->~ListOfInts();
		ListNodePtr trailptr = NULL, temptr = l.head;
		while (temptr != NULL) {
			if (head == NULL) {
				head = trailptr = new NodeofInt(temptr->theValue);
			}
			else {
				trailptr->next = new NodeofInt(temptr->theValue);
				trailptr = trailptr->next;
			}
			temptr = temptr->next;
		}
	}
	return *this;
}

ListOfInts& ListOfInts::operator=(ListOfInts&& other){
	other.swap(*this);
	return *this;
}


void ListOfInts::swap(ListOfInts& second) {

	using std::swap;
	swap(head, second.head);
}
