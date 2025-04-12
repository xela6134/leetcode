#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

class TimeMap {
 public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        stores[key][timestamp] = value;
    }
    
    std::string get(std::string key, int timestamp) {
        // Returns an iterator to the first element with key > timestamp
        auto it = stores[key].upper_bound(timestamp);
        
        if (it == stores[key].begin()) {
            return "";
        } else {
            return prev(it)->second;
        }
    }
 private:
    std::unordered_map<std::string, std::map<int, std::string>> stores;
};

int main() {
    TimeMap* timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);
    std::cout << "answer: " << timeMap->get("foo", 1) << std::endl;
    std::cout << "answer: " << timeMap->get("foo", 3) << std::endl;
    timeMap->set("foo", "bar2", 4);
    std::cout << "answer: " << timeMap->get("foo", 4) << std::endl;
    std::cout << "answer: " << timeMap->get("foo", 5) << std::endl;
}
