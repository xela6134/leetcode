#include <vector>
#include <unordered_map>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
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
        for (const auto& node : graph) {
            if (node.second.first == graph.size() and node.second.second == 0) return node.first;
        }

        return 0;
    }
};
