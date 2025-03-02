#include <vector>
#include <iostream>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    // Greedy Algorithm

    int remaining_spots = 0;
    for (int i = 0; i < flowerbed.size(); ++i) {
        if (
            flowerbed[i] == 0 and
            (i == 0 or flowerbed[i - 1] == 0) and
            (i == flowerbed.size() - 1 or flowerbed[i + 1] == 0)
        ) {
            ++remaining_spots;
            flowerbed[i] = 1;
        }
    }

    std::cout << remaining_spots << std::endl;

    return remaining_spots >= n;
}

int main() {
    std::vector<int> flowerbed = {1, 0, 0, 0, 1};
    std::cout << std::boolalpha << canPlaceFlowers(flowerbed, 1) << std::endl;
    std::cout << std::boolalpha << canPlaceFlowers(flowerbed, 2) << std::endl;

    std::vector<int> flowerbed1 = {1, 0, 0, 0, 0, 1};
    std::cout << std::boolalpha << canPlaceFlowers(flowerbed1, 2) << std::endl;

    std::vector<int> flowerbed2 = {0, 0, 1, 0, 1};
    std::cout << std::boolalpha << canPlaceFlowers(flowerbed2, 1) << std::endl;    
}
