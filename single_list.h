#ifndef SINGLE_LIST_H_
#define SINGLE_LIST_H_

#include <iostream>
#include <vector>
#include <queue>

template <class T>
struct Node
{
	Node<T> * next;
	T value;
	Node(T d) : value(d), next(nullptr) {}
};

// template <class T>
// Node<T> * CreateNode(T value)
// {
// 	Node<T> * node = new Node<T>;
// 	node->next = nullptr;
// 	node->value = value;
// 	return node;
// }

template <class T>
class SingleList
{
private:
	int len;
	Node<T> * rt;
	
public:
	SingleList() : rt(nullptr), len(0) {}
	SingleList(const std::vector<T> & v);
	~SingleList();
	Node<T> * root() const { return rt; }
	SingleList<T> * append(Node<T> * node);
	SingleList<T> * appendleft(Node<T> * node);
	SingleList<T> * insert(Node<T> * node, Node<T> * at);
	void delete_node(Node<T> * node);
	void delete_node(T & value);
	void remove(Node<T> * node);
	void reverse();
	void reverse_show() const;
	Node<T> * first_k(int k);
	Node<T> * last_k(int k);

	// leetcode
	void delete_last_k_node(int k);
	Node<T> * merge_two_lists(SingleList<T> & sl);
	Node<T> * merge_k_lists(std::vector<SingleList<T>*> & lists);
	Node<T> * swap_pairs();
	Node<T> * rotate(int k); // +right
	Node<T> * reverse_k_group(int k);
	void sort():
	Node<T> * to_binary_tree();
};

SingleList::SingleList(const std::vector<T> & v) : SingleList()
{
	for (auto x : v)
	{
		Node<T> * node = new Node<T>(x);
		if (rt == nullptr)
			rt = node;
		else
		{
			
		}
	}
}

#endif