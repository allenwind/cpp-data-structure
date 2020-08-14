#include <iostream>
#include "stack.h"

using namespace std;

class StackMin
{
private:
    Stack<int> * mstack;
    Stack<int> * cstack;

public:
    bool push(const int & item);
    bool pop(int & item);
};

