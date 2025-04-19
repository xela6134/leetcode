#include <unordered_map>
#include <list>
#include <iostream>
#include <utility>

// For maximum speed
// auto init_io = []() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return 0;
// }();

class LRUCache {
 public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        // 1. Return -1 if not found
        if (cache.find(key) == cache.end()) return -1;

        // 2. Change the order (Move to start of list)
        order.erase(cache[key].second);
        order.push_front(key);
        cache[key].second = order.begin();

        // 3. Return the value
        return cache[key].first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);

        // Key exists already
        if (it != cache.end()) {
            order.erase(it->second.second);
            order.push_front(key);
            it->second = {value, order.begin()};
            return;
        }

        // Remove least used element
        if (cache.size() == size) {
            int least_recent = order.back();
            order.pop_back();
            cache.erase(least_recent);
        }
        
        // Inserting process
        order.push_front(key);
        cache[key] = {value, order.begin()};
    }
 private:
    int size;
    std::list<int> order;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
};

auto main() -> int {
    std::cout << "Test 1" << std::endl;
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1);                             // cache is {1=1}
    lRUCache.put(2, 2);                             // cache is {1=1, 2=2}
    std::cout << lRUCache.get(1) << std::endl;      // return 1
    lRUCache.put(3, 3);                             // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    std::cout << lRUCache.get(2) << std::endl;      // returns -1 (not found)
    lRUCache.put(4, 4);                             // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    std::cout << lRUCache.get(1) << std::endl;      // return -1 (not found)
    std::cout << lRUCache.get(3) << std::endl;      // return 3
    std::cout << lRUCache.get(4) << std::endl;      // return 4

    // ["LRUCache","put","put","get","put","get","put","get","get","get"]
    // [       [2],[1,0],[2,2],  [1],[3,3],  [2],[4,4],  [1],  [3],  [4]]

    std::cout << "\nTest 2" << std::endl;
    LRUCache lruCache1 = LRUCache(2);
    lruCache1.put(1, 0);
    lruCache1.put(2, 2);
    std::cout << lruCache1.get(1) << std::endl;
    lruCache1.put(3, 3);
    std::cout << lruCache1.get(2) << std::endl;
    lruCache1.put(4, 4);
    std::cout << lruCache1.get(1) << std::endl;
    std::cout << lruCache1.get(3) << std::endl;
    std::cout << lruCache1.get(4) << std::endl;
}
