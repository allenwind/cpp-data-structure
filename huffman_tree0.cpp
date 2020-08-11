#include <iostream>
#include <vector>
#include <bitset>
#include "huffman_tree.h"

using std::cout;
using std::endl;

int main(int argc, char ** argv)
{   
    cout << std::boolalpha;

    HuffmanTree hf("hopefully this might get you started in the right direction");
    hf.update("ght get you started in th");
    hf.show();
    hf.digest();
    cout << hf.is_digest() << endl;
    std::map<char, int> cmap;
    hf.codes(cmap);
    for (auto pair : cmap)
        cout << pair.first << ":" << pair.second << endl;
}