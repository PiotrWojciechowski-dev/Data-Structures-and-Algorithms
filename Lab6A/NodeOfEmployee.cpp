#include "NodeOfEmployee.h"

NodeOfEmployee::NodeOfEmployee(string name, double salary) {
	emp.name = name;
	emp.salary = salary;
	next = NULL;
}

Employee NodeOfEmployee::getEmp() {
	return emp;
}

NodeOfEmployee* NodeOfEmployee::getNext() {
	return next;
}