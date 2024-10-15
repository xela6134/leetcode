#include <stack>
#include <iostream>
#include <limits>

class MinStack {
 public:
    MinStack() {}
    
    void push(int val) {
        main_.push(val);
        
        if (min_.empty() or min_.top() >= val) {
            min_.push(val);
        }
    }
    
    void pop() {
        if (main_.top() == min_.top()) {
            min_.pop();
        }
        main_.pop();
    }
    
    int top() {
        return main_.top();
    }
    
    int getMin() {
        return min_.top();
    }

 private:
    std::stack<int> main_;
    std::stack<int> min_;
};

auto main() -> int {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl; // return -3
    minStack.pop();
    std::cout << minStack.top() << std::endl;    // return 0
    std::cout << minStack.getMin() << std::endl; // return -2
}
