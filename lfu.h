#ifndef LFU_H_
#define LFU_H_

#include <set>
#include <unordered_map>

/*API描述

int get(key)
如果key存在于缓存中，则获取key的value（总是正数），否则返回 -1。

int put(key, value)
如果key已存在，则更新其值；如果key不存在，请插入key-value对。
当缓存达到其容量上限时，则应该在插入新项之前，使最不经常使用的项无效。
当存两个或更多个key具有相同使用频率时，应该去除最久未使用的key。
*/

struct Node
{
    int count;
    int time; // 记录最近一次使用的时间
    int key;
    int value;

    bool operator<(const Node & node)
    {
        return count == node.count ? time < node.time : count < node.count;
    }

    Node(int c, int t, int k, int v) : count(c), time(t), key(k), value(v) {}
};

class LFUCache
{
private:
    int cap;
    int time;
    std::unordered_map<int, Node> table;
    std::set<Node> cache;

public:

};



#endif