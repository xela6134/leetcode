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
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (map_.find(key) == map_.end()) return -1;

        auto it = map_[key];
        list_.splice(list_.begin(), list_, it);
        return (*it).second; // it->second also works
    }

    void put(int key, int value) {
        // Key exists
        if (map_.find(key) != map_.end()) {
            std::cout << "in if" << std::endl;
            // 1. Get the iterator from list
            auto it = map_[key];

            // 2. Change the value
            it->second = value;

            // 3. Move to start of list            
            list_.splice(list_.begin(), list_, it);
            return;
        }

        // If capacity full, remove least used
        if (list_.size() == capacity_) {
            int least = list_.back().first;
            list_.pop_back();
            map_.erase(least);
        }

        // Now push to start of list
        list_.emplace_front(std::make_pair(key, value));
        map_[key] = list_.begin();
    }

 private:
    // Data structure explanation:
    // - List of pairs {key, val}
    // - Map which points to the iterators of the list {key, iterator}

    int capacity_;
    std::list<std::pair<int, int>> list_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
};

auto main() -> int {
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
}
