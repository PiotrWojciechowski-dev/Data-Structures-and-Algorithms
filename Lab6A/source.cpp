#include "NodeofInt.h"
#include "ListOfInts.h"
#include "ListOfEmployee.h"
#include "NodeOfEmployee.h"
#include "Employee.h"
#include <iostream>
using namespace std;

int main() {
	cout << "List Of Ints Program" << endl;
	ListOfInts list;
	list.insertBack(10);
	list.insertBack(20);
	list.insertBack(30);
	list.insertBack(40);
	list.insertBack(50);

	cout << "Display contents of the list" << endl;
	list.displayList();

	// Delete the most recent node in the list
	list.deleteMostRecent();

	cout << endl;
	cout << "Display contents of the list after deleting the most recent node" << endl;
	list.displayList();

	// Delete node with value 10
	list.deleteInt(10);

	cout << endl;
	cout << "Display contents of the list after finding the node value and deleting it" << endl;
	list.displayList();

	ListOfInts list2(list);
	cout << endl;
	cout << "Display contents of List 2" << endl;
	list2.displayList();

	ListOfInts list3;
	list3.insertBack(60);
	cout << endl;
	cout << "Display contents of List 3" << endl;
	list3.displayList();

	list3 = list2;
	cout << endl;
	cout << "Display new contents of List 3" << endl;
	list3.displayList();
	cout << endl;

	ListOfInts list4;
	list4.insertBack(60);
	list4.insertBack(70);
	list4.insertBack(80);

	list3 = std::move(list4);
	cout << "This is List 3 now" << endl;
	list3.displayList();
	cout << endl;
	cout << "This is List 4 now" << endl;
	list4.displayList();

	cout << endl;
	cout << "List Of Employees Program";
	ListOfEmployee empL1;
	empL1.insertAtFront("emp1", 100);
	empL1.insertAtFront("emp2", 200);
	empL1.insertAtFront("emp3", 300);
	empL1.insertAtFront("emp4", 400);
	empL1.insertAtFront("emp5", 500);

	cout << empL1 << endl;

	cout << "Salary of emp3 is €" << empL1.getSalary("emp3") << endl;
	cout << endl;

	empL1.deleteMostRecent();
	empL1.deleteMostRecent();
	empL1.deleteMostRecent();

	cout << "List Of Employees:" << endl;
	cout << empL1 << endl;

	ListOfEmployee empL2(empL1);

	cout << "Employee List 2" << endl;
	cout << empL2;

	ListOfEmployee empL3;
	empL3.insertAtFront("emp6", 600);

	cout << endl;
	cout << "Employee List 3" << endl;
	cout << empL3;

	empL3 = empL2;
	cout << endl;
	cout << "New Employee List 3" << endl;
	cout << empL3;

	return 0;
};