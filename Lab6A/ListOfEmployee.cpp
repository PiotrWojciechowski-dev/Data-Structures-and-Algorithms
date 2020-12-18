#include "ListOfEmployee.h"
#include <iostream>
using namespace std;

void ListOfEmployee::insertAtFront(string s, double d) {
	Employee empNew = Employee(s, d);
	EmpNodePtr newNode = new NodeOfEmployee(empNew.getName(), empNew.getSalary());
	newNode->next = head;

	head = newNode;
}

void ListOfEmployee::deleteMostRecent() {
	EmpNodePtr deleteptr = head;
	head = head->next;
	delete deleteptr;
}

double ListOfEmployee::getSalary(string name) {
	EmpNodePtr temptr = head;
	EmpNodePtr trailptr = NULL;
	while (temptr != NULL) {
		if (temptr->emp.getName() == name) {
			trailptr = temptr;
			temptr = NULL;
		}
		else {
			temptr = temptr->next;
		}
	}
	if (trailptr == NULL) {
		return 0.0;
	}
	else {
		return trailptr->emp.getSalary();
	}
}

ListOfEmployee::ListOfEmployee() {
	head = NULL;
}

ListOfEmployee::~ListOfEmployee() {
	while (head) {
		EmpNodePtr temptr = head;

		head = head->next;

		delete temptr;
	}

}

ListOfEmployee::ListOfEmployee(const ListOfEmployee& empL) {
	*this = empL;
}

ListOfEmployee& ListOfEmployee::operator=(const ListOfEmployee& empL) {
	if (this != &empL) {
		if (head != NULL) this->~ListOfEmployee();
		EmpNodePtr trailptr = NULL, temptr = empL.head;
		while (temptr != NULL) {
			if (head == NULL) {
				Employee emp = temptr->getEmp();
				head = trailptr = new NodeOfEmployee(temptr->emp.getName(), temptr->emp.getSalary());
			} else {
				Employee emp = temptr->getEmp();
				trailptr->next = new NodeOfEmployee(temptr->emp.getName(), temptr->emp.getSalary());
				trailptr = trailptr->next;
			}
			temptr = temptr->next;
		}
	}
	return *this;
}

ostream& operator<<(ostream& outputStream, ListOfEmployee& empList)
{
	EmpNodePtr temptr = empList.head;
	while (temptr != NULL) {
		Employee emp = temptr->getEmp();
		outputStream << "Employee named " << emp.getName() << ", has a salary of €" << emp.getSalary() << endl;
		temptr = temptr->getNext();
	}
	return outputStream;
}