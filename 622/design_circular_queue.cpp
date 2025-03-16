#include <iostream>
#include <vector>

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        
    }
    
    bool deQueue() {
        
    }
    
    int Front() {
        if (count == 0) return -1;
        return queue[front];
    }
    
    int Rear() {
        if (count == 0) return -1;
        return queue[back];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
private:
    // capacity and number of elements
    int capacity;
    int count = 0;

    // indexes for front and back
    int front = 0;
    int back = 0;

    // queue structure
    std::vector<int> queue;
};

int main() {
    return 0;
}