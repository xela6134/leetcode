#include <iostream>
#include <vector>
#include <unordered_map>

int countCoveredBuildings(int n, std::vector<std::vector<int>>& buildings) {
    std::unordered_map<int, std::vector<int>> rows;
    std::unordered_map<int, std::vector<int>> cols;

    for (const auto& b : buildings) {
        rows[b[0]].push_back(b[1]);
        cols[b[1]].push_back(b[0]);
    }
    
    for (auto& [key, val] : rows) {
        std::sort(val.begin(), val.end());
    }
    for (auto& [key, val] : cols) {
        std::sort(val.begin(), val.end());
    }
    
    int count = 0;
    
    for (const auto& b : buildings) {
        int x = b[0];
        int y = b[1];
        
        auto& row = rows[x];
        auto& col = cols[y];
        
        bool hasLeft = false, hasRight = false, hasUp = false, hasDown = false;
        
        // Binary Search (find something before y and after y)
        auto horizontal = std::lower_bound(row.begin(), row.end(), y);
        if (horizontal != row.begin()) hasLeft = true;
        if (horizontal != row.end() and std::next(horizontal) != row.end()) hasRight = true;
        
        // Binary Search (find something before x and after x)
        auto vertical = std::lower_bound(col.begin(), col.end(), x);
        if (vertical != col.begin()) hasUp = true;
        if (vertical != col.end() and std::next(vertical) != col.end()) hasDown = true;

        if (hasLeft and hasRight and hasUp and hasDown) {
            ++count;
        }
    }
    
    return count;

}

int main() {

}
