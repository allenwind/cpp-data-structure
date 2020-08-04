#include <iostream>
#include "double_list.h"

using namespace std;

int main(int argc, char ** argv)
{
    DoubleList<int> list = { 1, 2, 3, 4, 5 };
    list.show();
    cout << list.size() << endl;

    auto x = list.back();
    list.delnode(x);
    list.show();

    auto y = list.front();
    list.delnode(y);
    list.show();
    cout << list.size() << endl;
}