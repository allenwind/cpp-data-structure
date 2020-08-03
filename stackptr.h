#ifndef STACKPTR_H_
#define STACKPTR_H_

template <class T>
class Stack
{
private:
	enum {SIZE = 10};
	int top;
	int size;
	T * items;

public:
	explicit Stack(unsigned int s = SIZE);
	~Stack();
	bool isempty() const { return top == 0; };
	bool isfull() const { return top == size; };
	int size() const { return size; };
	void clean();
	void show();
	bool push(const T & item);
	bool pop(T & item);

	// operator
};

#endif