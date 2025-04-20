#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // Key is most recently used
        auto it = cache[key].second;
        order.erase(it);
        order.push_front(key);
        cache[key].second = order.begin();

        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Reallocating the iterator
            auto it = cache[key].second;
            order.erase(it);
            order.push_front(key);
            cache[key].second = order.begin();

            // Reassigning the value
            cache[key].first = value;

            return;
        }

        if (cache.size() == size) {
            int last = order.back();

            cache.erase(last);
            order.pop_back();
        }

        order.push_front(key);
        cache[key] = {value, order.begin()};
    }
private:
    int size;
    std::list<int> order;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */