#include <iostream>
#include <vector>
#include <queue>

int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> queue;
    for (int stone : stones) {
        queue.push(stone);
    }

    while (queue.size() > 1) {
        int y = queue.top();
        queue.pop();
        int x = queue.top();
        queue.pop();

        if (x < y) {
            queue.push(y - x);
        }
    }

    if (queue.size() == 1) {
        return queue.top();
    } else {
        return 0;
    }    
}

int main() {
    std::vector<int> stones = {2,7,4,1,8,1};
    std::cout << lastStoneWeight(stones) << std::endl;

    std::vector<int> stones1 = {2,2};
    std::cout << lastStoneWeight(stones1) << std::endl;
}
