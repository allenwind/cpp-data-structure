#ifndef DOUBLE_LIST_H_
#define DOUBLE_LIST_H_

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
	DoubleList(const std::initializer_list<T> & il);
	DoubleList(const std::initializer_list<Node<T>*> & il);
	~DoubleList();
	DoubleList<T> * append(Node<T> * node);
	DoubleList<T> * appendleft(Node<T> * node);
	DoubleList<T> * appendlist(DoubleList<T> & dl);
	DoubleList<T> * mergelists(std::vector<DoubleList<T>*> & lists); // merge k sorted lists
	DoubleList<T> * insert(Node<T> * node, Node<T> * at);
	void delnode(Node<T> * node);
	Node<T> * remove(Node<T> * node);
	void clean();
	void show();
	void vswap(Node<T> * node1, Node<T> * node2); // vswap two node in a list
	void swap(Node<T> * node1, Node<T> * node2);
	void sort(); // sorting list
	void reverse();
	void move_to_back(Node<T> * node);
	void move_to_front(Node<T> * node);
	Node<T> * firstk(int k);
	Node<T> * lastk(int k);
	Node<T> * search(T & data);

	int size() const { return len; }
	bool isempty() const { return len == 0; }
	Node<T> * front() { return head; }
	Node<T> * back() { return tail; }

	// friend
	template <class U>
	friend std::ostream & operator<<(std::ostream & os, DoubleList<U> & dl);

	// operator
	DoubleList<T> * operator<<(Node<T> * node) { return append(node); }
	Node<T> * operator[](int k) { return firstk(k); }
	Node<T> * operator()(int k) { return lastk(k); }
};

// friend
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
DoubleList<T>::DoubleList(const std::initializer_list<T> & il) : DoubleList()
{
	for (auto & x : il)
	{
		Node<T> * node = CreateNode(x);
		append(node);
	}
}

template <class T>
DoubleList<T>::DoubleList(const std::initializer_list<Node<T>*> & il) : DoubleList()
{
	for (auto x : il)
		append(x);
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
DoubleList<T> * DoubleList<T>::appendlist(DoubleList<T> & dl)
{
	// TODO
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
	remove(node);
	delete node;
}

template <class T>
Node<T> * DoubleList<T>::remove(Node<T> * node)
{
	if (node->prev != nullptr)
		node->prev->next = node->next;
	else
		head = node->next; // head node
	if (node->next != nullptr)
		node->next->prev = node->prev;
	else
		tail = node->prev; // tail node;
	len--;
	return node;
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
		if (node->next != nullptr)
			std::cout << "->";
		node = node->next;
	}
	std::cout << std::endl;
}

template <class T>
void DoubleList<T>::vswap(Node<T> * node1, Node<T> * node2)
{
	if (node1 == nullptr || node2 == nullptr)
		return;
	T t = node1->data;
	node1->data = node2->data;
	node2->data = t;
}

template <class T>
void DoubleList<T>::sort()
{
	// TODO
}

template <class T>
void DoubleList<T>::reverse()
{
	
}

template <class T>
void DoubleList<T>::move_to_back(Node<T> * node)
{
	remove(node);
	append(node);
}

template <class T>
void DoubleList<T>::move_to_front(Node<T> * node)
{
	remove(node);
	appendleft(node);
}

template <class T>
Node<T> * DoubleList<T>::firstk(int k)
{
	if (k > len)
		return nullptr;
	Node<T> * node = head;
	for (int i = 0; i < k - 1; i++)
		node = node->next;
	return node;
}

template <class T>
Node<T> * DoubleList<T>::lastk(int k)
{
	if (k > len)
		return nullptr;
	Node<T> * node = tail;
	for (int i = 0; i < k - 1; i++)
		node = node->prev;
	return node;
}

template <class T>
Node<T> * DoubleList<T>::search(T & data)
{
	if (head == nullptr)
		return nullptr;
	Node<T> * node = head;
	while (node != nullptr)
	{
		if (node->data == data)
			return node;
		else
			node = node->next;
	}
	return nullptr;
}

#endif