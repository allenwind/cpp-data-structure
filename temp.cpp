#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

std::map<std::string, int> func()
{
    std::map<std::string, int> m;
    return m;
}

int main()
{
    string s = "abcdef";
    for (char v : s)
        cout << v << endl;

    pair<int, int> a(1, 1);
    cout << a.first << a.second << endl;

    map<char, int> m;
    m['c']++;
    m['c']++;
    cout << m['c'] << endl;

    char c = '\0';
    cout << c << endl;

    m['d'] = 2 * m['d'] + 1;
    cout << m['d'] << endl;

    // auto m = func(); is error
    cout << "char:" << endl;
    for (char c : s)
        cout << (c == '\0') << endl;
}