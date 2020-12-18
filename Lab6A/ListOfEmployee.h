#define LISTOFEMPLOYEE_H
#pragma once

#include "NodeOfEmployee.h"
#include <iostream>
using namespace std;

class ListOfEmployee {

	friend class NodeOfEmployee;
	
	public:
		ListOfEmployee();
		~ListOfEmployee();
		ListOfEmployee(const ListOfEmployee& empL);

		void insertAtFront(string s, double d);
		void deleteMostRecent();
		double getSalary(string name);
		friend ostream& operator <<(ostream& outputStream, ListOfEmployee& empList);
		ListOfEmployee& operator=(const ListOfEmployee& empL);

	private:
		NodeOfEmployee* head;
};
