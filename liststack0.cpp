#include <iostream>
#include "liststack.h"

using namespace std;

int main(int argc, char ** argv)
{
	Stack<int> stack(5);
	stack.push(1);
	stack.push(2);

	int item;
	stack.pop(item);
	cout << item << endl;
}