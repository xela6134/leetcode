#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (numbers.find(val) != numbers.end()) return false;

        // Insert into numbers and lookups
        numbers[val] = size;
        lookups.push_back(val);

        // Increment size
        ++size;
        return true;
    }
    
    bool remove(int val) {
        if (numbers.find(val) == numbers.end()) return false;

        // 1. Erase element
        int index = numbers[val];
        numbers.erase(val);

        // If it's not the last element, perform swap.
        if (index != lookups.size() - 1) {
            int to_replace = lookups.back();
            lookups[index] = to_replace;
            numbers[to_replace] = index;
        }
        
        lookups.pop_back();
        --size;
        return true;
    }
    
    int getRandom() {
        int random = rand() % size;
        return lookups[random];
    }
private:
    int size = 0;
    // { value, index in lookups }
    std::unordered_map<int, int> numbers;
    std::vector<int> lookups;
};
