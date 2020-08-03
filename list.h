#ifndef LIST_H_
#define LIST_H_

template <class T>
struct Node
{
	Node<T> * prev;
	Node<T> * next;
	T data;
};

template <class T>
class List
{
private:
	int size;
	Node<T> * head;
	Node<T> * tail;

public:
	List();
	~List();
	void insert(Node<T> * e, Node<T> * at);
	void remove(Node<T> * e);
	void push(Node<T> * e);
	Node<T> * get();
};

#endif