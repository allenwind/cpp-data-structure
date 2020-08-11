#ifndef LRU_CACHE_H_
#define LRU_CACHE_H_

#include <list>
#include <map>

template <class K, class V>
struct Node
{
    K key;
    V value;
};

template <class K, class V>
class LRUCache
{
private:
    std::map<K, Node<K, V>*> cache;
    std::list<Node<K, V>*> root;
    int size;

public:
    explicit LRUCache(int ss) : size(ss) {}
    ~LRUCache();
    void put(K key, V value);
    V get(K key);
};

template <class K, class V>
LRUCache<K, V>::~LRUCache()
{

}

template <class K, class V>
void LRUCache<K, V>::put(K key, V value)
{
    auto node = cache[key];
    if (node != cache.end())
    {
        root.remove(node);
        node->value = value; // update
        root.push_back(node); // move to hot part
        return;
    }
    if (size == root.size())
    {
        auto node = root.front();
        root.remove(node);
        cache.erase(key); // remove cold node
    }
    auto node = new Node<K, V>;
    node->key = key;
    node->value = value;
    root.push_back(node);
    cache[key] = node;
}

template <class K, class V>
V LRUCache<K, V>::get(K key)
{
    auto node = cache[key];
    V value;
    if (node != cache.end())
    {
        root.remove(node);
        value = node->value;
        root.push_back(node);
    }
    return value;
}

#endif