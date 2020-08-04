#ifndef SINGLE_LIST_H_
#define SINGLE_LIST_H_

#include <iostream>

template <class T>
struct Node
{
	Node<T> * next;
	T data;
};

template <class T>
Node<T> * CreateNode(T data)
{
	Node<T> * node = new Node<T>;
	node->next = nullptr;
	node->data = data;
	return node;
}

template <class T>
class SingleList
{
private:
	int len;
	
public:
	SingleList();
	~SingleList();
	SingleList<T> * append(Node<T> * node);
	SingleList<T> * appendleft(Node<T> * node);
	SingleList<T> * insert(Node<T> * node, Node<T> * at);
	void delnode(Node<T> * node);
	void reverse();
	Node<T> * first_k(int k);
};

#endif