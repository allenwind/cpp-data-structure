#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template <class T>
class Stack
{
private:
	T * items;
	int stacksize; // capacity
	int top;

public:
	//Stack();
	Stack(int size);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	int size();
	int capacity();
	void clean();
	void show();
	bool push(const T & item);
	bool pop(T & item);

	// operator
	bool operator<<(const T & item);
	bool operator>>(T & item);
	Stack & operator=(const Stack & st);

	// friend
	template <class TT>
	friend std::ostream & operator<<(std::ostream & os, Stack<TT> & st);
};

template <class T>
Stack<T>::Stack(int size)
{
	top = 0;
	stacksize = size;
	items = new T[size];
}

template <class T>
Stack<T>::~Stack()
{
	delete [] items;
}

template <class T>
bool Stack<T>::isempty() const
{
	return top == 0;
}

template <class T>
bool Stack<T>::isfull() const
{
	return top == stacksize;
}

template <class T>
int Stack<T>::size()
{
	return top;
}

template <class T>
int Stack<T>::capacity()
{
	return stacksize;
}

template <class T>
void Stack<T>::clean()
{
	top = 0;
}

template <class T>
void Stack<T>::show()
{
	using namespace std;
	for (int i = top - 1; i >= 0; i--)
	{
		cout << items[i] << endl;
	}
}

template <class T>
bool Stack<T>::push(const T & item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	return false;
}

template <class T>
bool Stack<T>::pop(T & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	return false;
}

template <class T>
bool Stack<T>::operator<<(const T & item)
{
	return this->push(item);
}

template <class T>
bool Stack<T>::operator>>(T & item)
{
	return this->pop(item);
}

template <class T>
Stack<T> & Stack<T>::operator=(const Stack<T> & st)
{
	if (this == &st)
		return *this;
	top = st.top;
	stacksize = st.stacksize;
	delete [] items;
	items = new T [stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

template <class TT>
std::ostream & operator<<(std::ostream & os, Stack<TT> & st)
{
	st.show();
	return os;
}


#endif