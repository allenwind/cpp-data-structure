#ifndef LISTSTACH_H_
#define LISTSTACH_H_

template <class T>
struct Node
{
	Node<T> * next;
	T data;
};

template <class T>
class Stack
{
private:
	Node<T> * top;
	int stacksize;
	int size;

public:
	Stack(int ss);
	~Stack();
	bool isempty() const { return size == 0; }
	bool isfull() const { return stacksize == size; }
	int length() const { return size; }
	int capacity() const { return stacksize; }
	void clean();
	void show();
	bool push(const T & item);
	bool pop(T & item);
};

template <class T>
Stack<T>::Stack(int ss) : stacksize(ss)
{
	top = nullptr;
	size = 0;
}

template <class T>
Stack<T>::~Stack()
{
	Node<T> * node;
	while (top != nullptr)
	{
		node = top;
		top = top->next;
		delete node;
	}
}

template <class T>
void Stack<T>::clean()
{
	Node<T> * node;
	while (top != nullptr)
	{
		node = top;
		top = top->next;
		delete node;
		size--;
	}
}

template <class T>
void Stack<T>::show()
{
	
}

template <class T>
bool Stack<T>::push(const T & item)
{
	if (size < stacksize)
	{
		size++;
		Node<T> * node = new Node<T>;
		node->data = item;
		if (top != nullptr)
		{
			node->next = top;
			top = node;
		}
		else
			top = node;
		return true;
	}
	return false;
}

template <class T>
bool Stack<T>::pop(T & item)
{
	if (size > 0)
	{
		item = top->data;
		top = top->next;
		size--;
		return true;
	}
	return false;
}

#endif