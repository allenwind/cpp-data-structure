#include <iostream>
#include "double_list.h"

using namespace std;

int main(int argc, char ** argv)
{
    DoubleList<int> list = { 1, 2, 3, 4, 5 };
    list.show();

    auto x = list.back();
    list.show();

    auto y = list.front();
    list.show();

    list.swap(x, y);
    list.show();

}