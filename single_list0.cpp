#include <iostream>
#include "single_list.h"

using namespace std;

int main(int argc, char ** argv)
{
    Node<int> * n = new Node<int>(1);
    cout << n->value << endl;
}