#include <iostream>
#include <unordered_map>
#include <list>

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min_freq = 0;
    }
    
    int get(int key) {
        // Return -1 if not found
        if (key_value_freq.find(key) == key_value_freq.end()) return -1;

        int value = key_value_freq[key].first;
        int freq = key_value_freq[key].second;

        // Update frequency for the key
        key_value_freq[key].second = freq + 1;

        // Remove key from current frequency list
        freq_keys[freq].erase(key_iter[key]);

        // Update freq_keys and key_iter
        freq_keys[freq + 1].push_front(key);
        key_iter[key] = freq_keys[freq + 1].begin();

        // If current frequency list becomes empty && it was the min frequency, update min_freq
        if (freq_keys[min_freq].empty()) ++min_freq;

        return value;
    }
    
    void put(int key, int value) {
        // Tiny error handling
        if (capacity <= 0) return;

        // Updating value, if key exists
        // Calling get over here also updates the frequency
        if (get(key) != -1) {
            key_value_freq[key].first = value;
            return;
        }

        // Inserting new value, if key doesn't exist

        // Size exceeded - must remove least used
        if (key_value_freq.size() == capacity) {
            // Get LRU key at min frequency
            int key_to_remove = freq_keys[min_freq].back();

            // Remove everything associated with that key
            key_value_freq.erase(key_to_remove);
            freq_keys[min_freq].pop_back();
            key_iter.erase(key_to_remove);
        }

        // Insert new key with frequency 1
        key_value_freq[key] = {value, 1};
        freq_keys[1].push_front(key);
        key_iter[key] = freq_keys[1].begin();

        // Reset min frequency to 1 for the new key
        min_freq = 1;
    }
private:
    int capacity;
    int min_freq;

    // { key, { value, frequency } }
    std::unordered_map<int, std::pair<int, int>> key_value_freq;
    // { frequency, { list of keys } }
    std::unordered_map<int, std::list<int>> freq_keys;
    // { key, iterator to freq_keys }
    std::unordered_map<int, std::list<int>::iterator> key_iter;
};


int main() {
    return 0;
}