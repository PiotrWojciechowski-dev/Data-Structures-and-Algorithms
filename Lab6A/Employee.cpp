#include "Employee.h"

Employee::Employee()
{
	name = "";
}

Employee::Employee(string n, double s)
{
	name = n;
	salary = s;
}

string Employee::getName()
{
	return name;
}

double Employee::getSalary()
{
	return salary;
}