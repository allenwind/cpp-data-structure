#ifndef HEAP_H_
#define HEAP_H_

template <class T>
void swap(T & a, T & b)
{
    T t = a;
    a = b;
    b = t;
}

template <class T>
struct Element
{
    T data;
};

template <class T>
class Heap
{
private:
    int size;

public:
    Heap(int ss);
    ~Heap();

};

#endif