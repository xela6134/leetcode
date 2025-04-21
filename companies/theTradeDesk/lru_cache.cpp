#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        auto it = cache[key].second;
        order.erase(it);
        order.push_front(key);
        cache[key].second = order.begin();

        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Pushed to start of list
            auto it = cache[key].second;
            order.erase(it);
            order.push_front(key);
            cache[key].second = order.begin();

            // Updating the value
            cache[key].first = value;

            return;
        }

        // Cache is already full, need to remove the least recently used element
        if (cache.size() == size) {
            int least_recent = order.back();

            cache.erase(least_recent);
            order.pop_back();
        }

        // 1. Push current key to start of order
        order.push_front(key);

        // 2. Update the cache
        cache[key] = {value, order.begin()};
    }
private:
    int size;
    std::list<int> order;
    // key: { value, order's iterator }
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
};