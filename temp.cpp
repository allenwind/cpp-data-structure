#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
    string s = "abcdef";
    for (char v : s)
        cout << v << endl;

    pair<int, int> a(1, 1);
    cout << a.first << a.second << endl;
}