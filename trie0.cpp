#include <iostream>
#include <string>
#include "trie.h"

using namespace std;

int main(int argc, char ** argv)
{
    Trie<string> trie;
    string a = "hello";
    trie.setitem("abc", a);
    string b;
    bool state;
    state = trie.getitem("abc", b);
    cout << boolalpha;
    cout << "b is " << b << endl;
    cout << state << endl;
    cout << trie.contains("abc") << endl;
}