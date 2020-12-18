#include <queue>
#include <iostream>
using namespace std;

void display(priority_queue <double>  que);

int main()
{
    queue<double> que1;

	cout << "Is the queue empty? " << que1.empty() << endl;
	que1.push(10);
	que1.push(20);
	que1.push(30);
	que1.push(40);


	cout << "Size of queue: " << que1.size() << endl;
	cout << "Front of queue: " << que1.front() << endl;
	cout << "Back of queue: " << que1.back() << endl;

	que1.pop();
	que1.pop();
	cout << endl;

	cout << "Size of queue: " << que1.size() << endl;
	cout << "Front of queue: " << que1.front() << endl;

	cout << endl;

	priority_queue<double>  que2;
	cout << "Is the priority queue empty? " << que2.empty() << endl;

	que2.push(10);
	que2.push(11);
	que2.push(12);
	que2.push(13);

	display(que2);

	cout << "Size of priority queue: " << que2.size() << endl;
	cout << "Front of priority queue: " << que2.top() << endl;

	que2.pop();

	display(que2);


    return 0;
}

void display(priority_queue<double> que)
{
	priority_queue <double>  i = que;
	while (!i.empty())
	{
		cout << i.top() << endl;
		i.pop();
	}
	cout << endl;
}