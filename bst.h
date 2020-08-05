#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <initializer_list>
#include <utility>
#include <functional>

enum class Traverse // enum class in C++11
{
    PREORDER,
    INORDER,
    POSTORDER,
    DEPTH,
    BREADTH
};

template <class T, class U>
struct Node
{
    Node<T, U> * left;
    Node<T, U> * right;
    T key;
    U value;
};

template <class T>
bool compare(T & t1, T & t2)
{
    // TODO
    return true;
}

template <class T, class U>
Node<T, U> * CreateNode(T & key, U & value)
{
    Node<T, U> * node = new Node<T, U>;
    node->left = nullptr;
    node->right = nullptr;
    node->key = key;
    node->value = value;
    return node;
}

template <class T, class U>
class BinarySearchTree
{
private:
    Node<T, U> * rt; // root
    int count;

public:
    BinarySearchTree() : count(0), rt(nullptr) {}
    BinarySearchTree(const std::initializer_list<std::pair<T, U>> & il);
    BinarySearchTree(const std::initializer_list<Node<T, U>*> & il);
    BinarySearchTree(const std::initializer_list<T> & key, const std::initializer_list<U> & value);
    ~BinarySearchTree();
    Node<T, U> * min();
    Node<T, U> * max();
    Node<T, U> * search(T & key);
    Node<T, U> * topk(int k);
    BinarySearchTree<T, U> * set(T & key, U & value);
    BinarySearchTree<T, U> * insert(Node<T, U> * node);
    BinarySearchTree<T, U> * remove(Node<T, U> * node);
    void delnode(Node<T, U> * node);
    int depth();
    virtual void tolist();

    int size() const { return count; }
    bool isempty() const { return rt == nullptr; }
    Node<T, U> * root() const { return rt; }

    // traverse
    void preorder();
    void inorder();
    void postorder();
    void depth_traverse();
    void breadth_traverse();
    void show(Traverse kind);

    // friend
    template <class TT, class UU>
    friend std::ostream & operator<<(std::ostream & os, BinarySearchTree<TT, UU> & bst);
};

// friend
template <class TT, class UU>
std::ostream & operator<<(std::ostream & os, BinarySearchTree<TT, UU> & bst)
{
    bst.show();
    return os;
}

#endif