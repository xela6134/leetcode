#include <iostream>
#include <vector>
#include <string>

int maximumSwap(int num) {
    std::string str = std::to_string(num);
    
    // int max_num = num;

    // for (int i = 0; i < str.size(); ++i) {
    //     for (int j = i + 1; j < str.size(); ++j) {
    //         std::swap(str[i], str[j]);
    //         max_num = max(max_num, stoi(str));
    //         std::swap(str[i], str[j]);
    //     }
    // }

    // return max_num;

    // Stores the last occurrence of each digit
    std::vector<int> last(10, -1);
    for (int i = 0; i < str.size(); ++i) {
        last[str[i] - '0'] = i;
    }

    for (int i = 0; i < str.size(); ++i) {
        // Greedy swap for any digit that is higher than current digit
        for (int d = 9; d > str[i] - '0'; --d) {
            if (last[d] > i) {
                std::swap(str[i], str[last[d]]);
                return std::stoi(str);
            }
        }
    }

    return std::stoi(str);
}

int main() {

}
