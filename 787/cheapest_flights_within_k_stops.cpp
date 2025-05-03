#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <limits>

int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
    // Build adjacency list
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (auto& flight : flights) {
        int u = flight[0], v = flight[1], w = flight[2];
        graph[u].emplace_back(v, w);
    }

    // Min-heap (cost, current_city, stops)
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq;
    pq.emplace(0, src, 0);

    // Track best costs by (city, stops)
    std::vector<int> stopsAtNode(n, std::numeric_limits<int>::max());

    // BFS-like Dijkstra
    while (not pq.empty()) {
        auto [cost, city, stops] = pq.top();
        pq.pop();

        if (city == dst) return cost;

        if (stops > k or stops >= stopsAtNode[city]) continue;
        stopsAtNode[city] = stops;

        for (auto& [next, price] : graph[city]) {
            pq.emplace(cost + price, next, stops + 1);
        }
    }

    return -1;
}

int main() {

}
