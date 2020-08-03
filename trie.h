#ifndef TRIE_H_
#define TRIE_H_

#include <map>
#include <string>
#include <iostream>

template <class T>
class Node
{
private:
	std::map<char, Node<T>*> children;
	T val;

public:
	Node() {}
	Node(T & v) : val(v) {}
	Node<T> * add(char c, T & v);
	Node<T> * add(char c);
	Node<T> * get(char c);
	T value() { return val; }
	void setvalue(T & vv) { val = vv; }
	void show();

	// operator

	// friend
	template <class U>
	friend std::ostream & operator<<(std::ostream & os, Node<U> & node);
};

template <class T>
Node<T> * Node<T>::add(char c, T & v)
{
	Node<T> * child = children[c];
	if (child == nullptr)
	{
		child = new Node<T>(v);
		children[c] = child;
	}
	else
		child->val = v;
	return child;
}

template <class T>
Node<T> * Node<T>::add(char c)
{
	T t;
	return add(c, t);
}

template <class T>
Node<T> * Node<T>::get(char c)
{
	return children[c];
}

template <class T>
void Node<T>::show()
{
	std::cout << "Node<" << val << ">" << std::endl;
}

template <class U>
std::ostream & operator<<(std::ostream & os, Node<U> & node)
{
	node.show();
	return os;
}

template <class T>
class Trie : private Node<T>
{
public:
	Trie() : Node<T>() {}
	bool contains(std::string key);
	bool getitem(std::string key, T & v);
	bool setitem(std::string key, T & v);
	bool removeitem(std::string key);
	void show();

	// friend;
	template <class U>
	friend std::ostream & operator<<(std::ostream & os, Trie<U> & trie);
};

template <class T>
bool Trie<T>::contains(std::string key)
{
	Node<T> * node = this;
	for (char c : key)
	{
		node = node->get(c);
		if (node == nullptr)
			return false;
	}
	return true;
}

template <class T>
bool Trie<T>::getitem(std::string key, T & v)
{
	Node<T> * node = this;
	for (char c : key)
	{
		node = node->get(c);
		if (node == nullptr)
			return false;
	}
	v = node->value();
	return true;
}

template <class T>
bool Trie<T>::setitem(std::string key, T & v)
{
	Node<T> * node = this;
	int i = 0;
	for (char c : key)
	{
		if (i < key.size() - 1)
			node = node->add(c);
		else
			node = node->add(c, v);
		i++;
	}
	return true;
}

template <class T>
bool Trie<T>::removeitem(std::string key)
{
	return false;
}

template <class T>
void Trie<T>::show()
{

}

template <class U>
std::ostream & operator<<(std::ostream & os, Trie<U> & trie)
{
	trie.show();
	return os;
}

#endif