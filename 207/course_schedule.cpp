#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <vector>

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    // 1. Make a graph
    std::vector<int> in_degree(numCourses, 0);              // Track in-degrees of each course
    std::vector<std::vector<int>> adj_list(numCourses);     // Adjacency 'list' representation

    // If {1, 0}: 0 -> 1
    // adj_list[1] contains courses where 'Course 1' is a prereq of.
    for (auto& prereq : prerequisites) {
        adj_list[prereq[1]].push_back(prereq[0]);
        ++in_degree[prereq[0]];
    }

    // 2. Use topological sorting (Kahn's Algorithm)
    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }        
    }

    // 3. If processed_courses equals numCourses, all courses can be finished
    int processed_courses = 0;
    while (not q.empty()) {
        int course = q.front();
        q.pop();
        ++processed_courses;

        for (int neighbour : adj_list[course]) {
            --in_degree[neighbour];

            if (in_degree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return processed_courses == numCourses;
}

auto main() -> int {
    int numCourses = 4;
    std::vector<std::vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    std::cout << std::boolalpha << canFinish(numCourses, prerequisites) << std::endl;

    numCourses = 4;
    prerequisites = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};
    std::cout << std::boolalpha << canFinish(numCourses, prerequisites) << std::endl;

    numCourses = 6;
    prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}, {5, 4}};
    std::cout << std::boolalpha << canFinish(numCourses, prerequisites) << std::endl;
}
