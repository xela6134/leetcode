#include <iostream>
#include <vector>
#include <queue>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) {
        size = k;
        
        // Push all the numbers in scores, then pop everything until size is k.
        for (int num : nums) {
            scores.push(num);
        }

        while (scores.size() > k) {
            scores.pop();
        }
    }
    
    int add(int val) {
        if (scores.size() >= size) {
            scores.push(val);
            scores.pop();
            return scores.top();
        } else {
            scores.push(val);
            return scores.top();
        }
    }

    void print() {
        auto scores_copy = scores;
        while (not scores_copy.empty()) {
            std::cout << scores_copy.top() << " ";
            scores_copy.pop();
        }
        std::cout << std::endl;
    }
private:
    int size;
    std::priority_queue<int, std::vector<int>, std::greater<int>> scores;
};

int main() {
    std::vector<int> nums = {};
    KthLargest* obj = new KthLargest(1, nums);

    std::cout << obj->add(-3) << std::endl;
    std::cout << obj->add(-2) << std::endl;
    std::cout << obj->add(-4) << std::endl;
    std::cout << obj->add(0) << std::endl;
    std::cout << obj->add(4) << std::endl;
}
