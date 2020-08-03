#ifndef DOUBLE_LIST_H_
#define DOUBLE_LIST_H_

#include <iostream>

template <class T>
struct Node
{
	Node<T> * next;
	Node<T> * prev;
	T data;
};

template <class T>
Node<T> * CreateNode(T data)
{
	Node<T> * node = new Node<T>; // TODO:smart ptr
	node->next = nullptr;
	node->prev = nullptr;
	node->data = data;
	return node;
}

template <class T>
struct ListIter
{
	Node<T> * next;
};

template <class T>
class DoubleList
{
private:
	int len;
	Node<T> * head;
	Node<T> * tail;
	
public:
	DoubleList();
	~DoubleList();
	DoubleList<T> * append(Node<T> * node);
	DoubleList<T> * appendleft(Node<T> * node);
	DoubleList<T> * insert(Node<T> * node, Node<T> * at);
	void delnode(Node<T> * node);
	void clean();
	void show();
	Node<T> * firstk(int k);
	Node<T> * search(T & data);

	int size() const { return len; }
	bool isempty() const { return len == 0; }
	Node<T> * front() { return head; }
	Node<T> * back() { return tail; }

	// friend
	template <class U>
	friend std::ostream & operator<<(std::ostream & os, DoubleList<U> & dl);

	// operator
};

template <class U>
std::ostream & operator<<(std::ostream & os, DoubleList<U> & dl)
{
	dl.show();
	return os;
}

template <class T>
DoubleList<T>::DoubleList()
{
	len = 0;
	head = nullptr;
	tail = nullptr;
}

template <class T>
DoubleList<T>::~DoubleList()
{
	Node<T> * node;
	while (head != nullptr)
	{
		node = head;
		head = head->next;
		delete node;
		len--;
	}
}

template <class T>
DoubleList<T> * DoubleList<T>::append(Node<T> * node)
{
	if (isempty())
		head = node;
	else
	{
		tail->next = node;
		node->prev = tail;
	}
	tail = node;
	len++;
	return this;
}

template <class T>
DoubleList<T> * DoubleList<T>::appendleft(Node<T> * node)
{
	if (isempty())
		tail = node;
	else
	{
		head->prev = node;
		node->next = head;
	}
	head = node;
	len++;
	return this;
}

template <class T>
DoubleList<T> * DoubleList<T>::insert(Node<T> * node, Node<T> * at)
{
	if (at == nullptr || at == tail)
	{
		append(node);
		return this;
	}
	else
	{
		node->next = at->next;
		node->prev = at;
		at->next = node;
	}
	len++;
	return this;
}

template <class T>
void DoubleList<T>::delnode(Node<T> * node)
{
	if (node->prev != nullptr)
		node->prev-next = node->next;
	else
		head = node->next; // head node
	if (node->next != nullptr)
		node->next->prev = node->prev;
	else
		tail = node->prev; // tail node;
	delete node;
	len--;
}

template <class T>
void DoubleList<T>::clean()
{
	Node<T> * node;
	while (head != nullptr)
	{
		node = head;
		head = head->next;
		delete node;
		len--;
	}
	head = nullptr;
	tail = nullptr;
}

template <class T>
void DoubleList<T>::show()
{
	Node<T> * node = head;
	while (node != nullptr)
	{
		std::cout << node->data;
		std::cout << "->";
		node = node->next;
	}
	cout << endl;
}

template <class T>
Node<T> * DoubleList<T>::firstk(int k)
{
	if (k > len)
		return nullptr;
	Node<T> * node = head;
	for (int i = 0; i < k; i++)
		node = head->next;
	return node;
}

template <class T>
Node<T> * DoubleList<T>::search(T & data)
{
	if (head == nullptr)
		return nullptr;
	Node<T> * node = head;
	while (node->data != data)
		node = node->next;
	return node;
}

#endif