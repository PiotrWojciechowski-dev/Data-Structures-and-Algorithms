#pragma once
#include <string>
using namespace std;

class Employee {

	friend class NodeOfEmployee;

	public:
		Employee();
		Employee(string n, double s);
		string getName();
		double getSalary();

	private:
		string name;
		double salary = 0;
};