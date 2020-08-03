#include <iostream>
#include <vector>
#include "queue.h"

using namespace std;

int main(int argc, char ** argv)
{
	Queue<int> q1(10);
	q1.push(1);
	q1.push(2);
	q1.push(3);

	cout << "length:" << q1.length() << endl;
	cout << "capacity:" << q1.capacity() << endl;

	q1.show();

	cout << "=====" << endl;
	int item;
	q1.get(item);
	cout << "get item:" << item << endl;
	q1.show();

	q1.clean();
	q1.push(1);
	q1.show();

	cout << "=====" << endl;

	Queue<int> q2({1, 2, 3, 4, 5}, 10);
	q2.show();

	bool state = q2.find(5);
	cout << state << endl;
	state = q2.find(10);
	cout << state << endl;

	vector<Node<int>*> v;
	v.push_back(CreateNode<int>(1));
	v.push_back(CreateNode<int>(2));
	Queue<int> q3(v, 10);
	q3.show();

	cout << "cout" << endl;
	cout << q3 << endl;

}