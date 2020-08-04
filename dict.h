#ifndef DICT_H_
#define DICT_H_

// 基于hash table实现的dict

template <class T, class U>
struct DictEntry
{
    T key;
    U value;
    DictEntry<T, U> * next;
};



#endif