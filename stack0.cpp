#include <iostream>
#include "stack.h"

using namespace std;

int main(int argc, char ** argv)
{
	Stack<int> stack(3);

	cout << "Stack push:" << endl;
	stack << 1;
	stack << 2;
	stack << 3;

	cout << boolalpha;
	cout << "Stack is full:" << stack.isfull() << endl;

	cout << "show Stack:" << endl;
	stack.show();

	cout << "Stack pop:" << endl;
	int item;
	stack >> item;
	cout << item << endl;

	stack >> item;
	cout << item << endl;

	stack >> item;
	cout << item << endl;

	cout << "Stack is empty:" << stack.isempty() << endl;
	stack << 1;
	stack << 2;
	cout << stack << endl;
}