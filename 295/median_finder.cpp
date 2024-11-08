#include <queue>
#include <iostream>

// Min: 
// Max: 3

// Min: 
// Max: 6 3

// Min: 6
// Max: 3

// Min: 6 
// Max: 3 1

// Min: 6 9
// Max: 3

// Min: 6 7 9
// Max: 4 2 1

// Either min = max + 1 or min = max
class MedianFinder {
 public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if (max_heap.empty() or num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        ++size;

        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }

 private:
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int size;
};

auto main() -> int {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    std::cout << obj->findMedian() << std::endl;    // 1.5
    obj->addNum(3);
    std::cout << obj->findMedian() << std::endl;    // 2
    obj->addNum(5);
    std::cout << obj->findMedian() << std::endl;    // 2.5
    obj->addNum(7);
    std::cout << obj->findMedian() << std::endl;    // 3
}
