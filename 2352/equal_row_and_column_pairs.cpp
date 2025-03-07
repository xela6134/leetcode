#include <vector>
#include <string>
#include <unordered_map>

int equalPairs(std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::unordered_map<std::string, int> rowFreq;
    
    for (int i = 0; i < size; ++i) {
        std::string str = "";
        for (int j = 0; j < size; ++j) {
            str += std::to_string(grid[i][j]) + ",";
        }
        rowFreq[str]++;
    }

    int count = 0;

    for (int i = 0; i < size; ++i) {
        std::string str = "";
        for (int j = 0; j < size; ++j) {
            str += std::to_string(grid[j][i]) + ",";
        }
        if (rowFreq.find(str) != rowFreq.end()) {
            count += rowFreq[str];
        }
    }

    return count;
}

int main() {

}
