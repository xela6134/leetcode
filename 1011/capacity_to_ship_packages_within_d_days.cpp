#include <iostream>
#include <vector>
#include <numeric>
#include <climits>

int shipWithinDays(std::vector<int> weights, int days) {
    int left = 1;
    int right = std::accumulate(weights.begin(), weights.end(), 0);

    int min = INT_MAX;
    while (left <= right) {
        // Current max capacity
        int mid = (left + right) / 2;

        int curr_weight = 0;
        int count = 1;
        for (int i = 0; i < weights.size(); ++i) {
            if (weights[i] > mid) {
                count = INT_MAX;
                break;
            }

            if (curr_weight + weights[i] > mid) {
                curr_weight = weights[i];
                ++count;
            } else {
                curr_weight += weights[i];
            }
            // std::cout << "mid: " << mid << ", count: " << count << ", curr_weight: " << curr_weight << ", weights[i]: " << weights[i] << std::endl;
        }

        // std::cout << std::endl;

        if (count > days) {
            left = mid + 1;
        } else {
            right = mid - 1;
            min = std::min(min, mid);
        }
    }

    return min;
}

int main() {
    std::cout << shipWithinDays({1,2,3,4,5,6,7,8,9,10}, 5) << std::endl;
    std::cout << shipWithinDays({3,2,2,4,1,4}, 3) << std::endl;
    std::cout << shipWithinDays({1,2,3,1,1}, 4) << std::endl;
}
