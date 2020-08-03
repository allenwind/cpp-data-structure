#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <initializer_list>
#include <vector>

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
class Queue
{
private:
	Node<T> * head;
	Node<T> * tail;
	int size;
	const int qsize;
	Queue(const Queue & q) : qsize(0) { }
	Queue & operator=(const Queue & q) { return *this; }

public:
	Queue(int qs);
	// Queue(const Queue & q); // 拷贝构造函数
	Queue(const std::initializer_list<T> & il, int qs);
	Queue(const std::vector<Node<T>*> & v, int qs);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	void clean();
	bool push(const T & t);
	bool concat(const Queue & q);
	bool get(T & t);
	bool find(T t) const;
	int length() { return size; }
	int capacity() { return qsize; }

	void show();
	// friend
	template <class TT>
	friend std::ostream & operator<<(std::ostream & os, Queue<TT> & q);

	// operator
};

template <class T>
Queue<T>::Queue(int qs) : qsize(qs)
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T>
Queue<T>::Queue(const std::initializer_list<T> & il, int qs) : qsize(qs)
{
	head = nullptr;
	tail = nullptr;
	size = il.size();
	for (auto p = il.begin(); p != il.end(); p++)
	{
		Node<T> * node = new Node<T>;
		node->next = nullptr;
		node->data = *p;
		if (head == nullptr)
			head = node;
		else
			tail->next = node;
		tail = node;
	}
}

template <class T>
Queue<T>::Queue(const std::vector<Node<T>*> & v, int qs) : qsize(qs)
{
	head = nullptr;
	tail = nullptr;
	size = v.size();
	for (auto node : v)
	{
		if (head == nullptr)
			head = node;
		else
			tail->next = node;
		tail = node;
	}
}

template <class T>
Queue<T>::~Queue()
{
	Node<T> * t;
	while (head != nullptr)
	{
		t = head;
		head = head->next;
		delete t;
	}
}

template <class T>
bool Queue<T>::isempty() const
{
	return size == 0;
}

template <class T>
bool Queue<T>::isfull() const
{
	return size == qsize;
}

template <class T>
void Queue<T>::clean()
{
	Node<T> * t;
	while (head != nullptr)
	{
		t = head;
		head = head->next;
		delete t;
	}
	size = 0;
}

template <class T>
bool Queue<T>::push(const T & t)
{
	if (this->isfull())
		return false;
	Node<T> * node = new Node<T>;
	node->next = nullptr;
	node->data = t;
	size++;
	if (head == nullptr)
		head = node;
	else
		tail->next = node;
	tail = node;
	return true;
}

template <class T>
bool Queue<T>::concat(const Queue & q)
{
	return true;
}

template <class T>
bool Queue<T>::get(T & t)
{
	if (this->isempty())
		return false;
	t = head->data;
	size--;
	Node<T> * temp = head;
	head = head->next;
	delete temp;
	if (this->isempty())
		tail = nullptr;
	return true;
}

template <class T>
bool Queue<T>::find(T t) const
{
	Node<T> * node = head;
	while (node != nullptr)
	{
		if (node->data == t)
			return true;
		node = node->next;
	}
	return false;
}

template <class T>
void Queue<T>::show()
{
	Node<T> * t = head;
	while (t != nullptr)
	{
		std::cout << t->data;
		std::cout << "->";
		t = t->next;
	}
	std::cout << std::endl;
}

template <class TT>
std::ostream & operator<<(std::ostream & os, Queue<TT> & q)
{
	q.show();
	return os;
}


#endif