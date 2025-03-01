#include <vector>
#include <iostream>
#include <algorithm>

auto kidsWithCandies(std::vector<int>& candies, int extraCandies) -> std::vector<bool> {
    // Go through candies and grab maximum

    int max = *std::max_element(candies.begin(), candies.end());

    std::vector<bool> result;
    for (int i = 0; i < candies.size(); ++i) {
        if (candies[i] + extraCandies >= max) {
            result.push_back(true);
        } else {
            result.push_back(false);
        }
    }

    return result;
}

void printAnswer(std::vector<bool> results) {
    for (bool result : results) {
        std::cout << std::boolalpha << result << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> candies1 = {2, 3, 5, 1, 3};
    std::vector<int> candies2 = {4, 2, 1, 1, 2};
    std::vector<int> candies3 = {12, 1, 12};

    printAnswer(kidsWithCandies(candies1, 3));
    printAnswer(kidsWithCandies(candies2, 1));
    printAnswer(kidsWithCandies(candies3, 10));
}
