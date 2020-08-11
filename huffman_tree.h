#ifndef HUFFMAN_TREE_H_
#define HUFFMAN_TREE_H_

#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <bitset>
#include <iostream>

struct Node
{
    char value;
    int weight;
    Node * left;
    Node * right;
};

struct NodeCompare
{
    bool operator()(Node * n1, Node * n2)
    {
        return n1->weight > n2->weight;
    }
};

Node * CreateNode(char v, int w, Node * left, Node * right)
{
    Node * node = new Node;
    node->value = v;
    node->weight = w;
    node->left = left;
    node->right = right;
    return node;
}

inline bool map_contains(std::map<char, int> m, char key)
{
    return m.find(key) != m.end();
}

class HuffmanTree
{
private:
    Node * rt;
    std::map<char, int> counter;
    std::priority_queue<Node*, std::vector<Node*>, NodeCompare> pq;

public:
    HuffmanTree(const std::string & s);
    HuffmanTree() : rt(nullptr) {};
    ~HuffmanTree();
    bool is_digest() const { return rt != nullptr; }
    Node * root() const { return rt; } // return tree root
    void update(const std::string & s); // update counter
    void digest();
    void codes(std::map<char, int> & cmap);
    void codes(Node * node, int prefix, std::map<char, int> & cmap);
    void show();
    void destroy(Node * node);
};

HuffmanTree::HuffmanTree(const std::string & s) : HuffmanTree()
{
    for (char c : s)
        counter[c]++;
}

HuffmanTree::~HuffmanTree()
{
    destroy(rt);
}

void HuffmanTree::update(const std::string & s)
{
    for (char c : s)
        counter[c]++;
}

void HuffmanTree::digest()
{
    for (auto pair : counter)
    {
        Node * node = CreateNode(pair.first, pair.second, nullptr, nullptr);
        pq.push(node);
    }

    while (pq.size() != 1)
    {
        Node * left = pq.top();
        pq.pop();
        Node * right = pq.top();
        pq.pop();
        int weight = left->weight + right->weight;
        // '\0' as non-leaf node
        Node * node = CreateNode('\0', weight, left, right);
        pq.push(node);
    }
    rt = pq.top();
    pq.pop();
}

void HuffmanTree::codes(std::map<char, int> & cmap)
{
    codes(rt, 0, cmap);
}

void HuffmanTree::codes(Node * node, int prefix, std::map<char, int> & cmap)
{
    if (node->value != '\0')
        cmap[node->value] = prefix;
    else
    {
        int lprefix = 2 * prefix;
        codes(node->left, lprefix, cmap);
        int rprefix = 2 * prefix + 1;
        codes(node->right, rprefix, cmap);
    }
}

void HuffmanTree::show()
{
    for (auto pair : counter)
        std::cout << pair.first << ":" << pair.second << std::endl;
}

void HuffmanTree::destroy(Node * node)
{
    if(node != nullptr)
    {
        Node * left = node->left;
        Node * right = node->right;
        delete node;
        node = nullptr;
        destroy(left);
        destroy(right);
    }
}

#endif