#ifndef TREE_H_
#define TREE_H_

#include <vector>

template <class T>
class Node
{
private:
    T data;
    std::vector<Node<T>*> children;

public:
    void add(Node<T>*);
};

template <class T>
class Tree
{
private:
    Node<T> * rt;

public:

};

#endif