#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>
#include <initializer_list>

template <class T>
struct Node
{
    Node<T> * next;
    Node<T> * prev;
    T data;
};

template <class T>
Node<T> * CreateNode(T & data)
{
    Node<T> * node = new Node<T>;
    node->next = nullptr;
    node->prev = nullptr;
    node->data = data;
    return node;
}

template <class T>
class List
{
private:
    Node<T> * head;
    Node<T> * tail;
    int len;

public:
    List();
    ~List();
    int size() { return len; }
    Node<T> * front() { return head; }
    Node<T> * back() { return tail; }
    void remove(Node<T> * node);
    void insert(Node<T> * node, Node<T> * at); // insert `node` after `at`
    void append(Node<T> * node);
    void appendleft(Node<T> * node);
    void appendlist(const List<T> & li);
    Node<T> * pop();
    Node<T> * popleft();
    void clean();
    void reverse();
    void rotate(int r);
    void show();

    // friend
    template <class TT>
    friend std::ostream & operator<<(std::ostream & os, List<TT> & li);
};

template <class TT>
std::ostream & operator<<(std::ostream & os, List<TT> & li)
{
    return os;
}

#endif