#include <iostream>
#include <queue>

class RecentCounter {
 public:
    RecentCounter() {}
    
    int ping(int t) {
        pings.push(t);
        
        while (not pings.empty() and pings.front() < t - 3000) {
            pings.pop();
        }

        return pings.size();
    }
 private:
    std::queue<int> pings;
};

int main() {
    RecentCounter* counter = new RecentCounter();

    std::cout << counter->ping(1) << std::endl;
    std::cout << counter->ping(100) << std::endl;
    std::cout << counter->ping(3001) << std::endl;
    std::cout << counter->ping(3002) << std::endl;

    delete counter;
}
