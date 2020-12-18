#include "NodeofInt.h"
#define LISTOFINTS_H
#pragma once

class ListOfInts {

	public:
		ListOfInts();
		// Copy Constructer
		ListOfInts(const ListOfInts& l);
		// Destructor
		~ListOfInts();
		// Move Constructer
		ListOfInts(ListOfInts&& other) noexcept;

		void insertBack(int i);
		void displayList();
		int deleteMostRecent();
		void deleteInt(int value);
		// Copy Assignment operator
		ListOfInts& operator=(const ListOfInts& l);
		// Move Assignment operator
		ListOfInts& operator=(ListOfInts&& other);
		// Swap functionality
		void swap(ListOfInts& second);

	private:
		NodeofInt* head;
};