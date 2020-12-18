#include "Employee.h"
#pragma once

class NodeOfEmployee {

	friend class ListOfEmployee;

	public:
		NodeOfEmployee(string name, double salary);
		Employee getEmp();
		NodeOfEmployee* getNext();

	private:
		Employee emp;
		NodeOfEmployee* next;

};
typedef NodeOfEmployee* EmpNodePtr;