#include <iostream>
#include <vector>
#include <unordered_map>

int findJudge(int n, std::vector<std::vector<int>>& trust) {
    if (trust.size() == 0 and n == 1) return 1;

    // Maps { node, { incoming, outgoing } }
    std::unordered_map<int, std::pair<int, int>> graph;

    // trust[i] = [ai, bi]
    // this means: ai->bi
    // - add bi for ai's outgoing
    // - add ai for bi's incoming
    for (const auto& t : trust) {
        int ai = t[0];
        int bi = t[1];
        ++graph[ai].second;
        ++graph[bi].first;
    }

    // if there exists a person ai who satisfies
    // 1. ai's outgoing is 0
    // 2. ai's incoming is graph's size
    for (const auto& [key, val] : graph) {
        // std::cout << key << ": " << val.first << ", " << val.second << std::endl;
        if (val.first == graph.size() - 1 and val.second == 0) return key;
    }

    return -1;
}

int main() {

}
