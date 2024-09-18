#include <vector>
#include <algorithm>

auto jump(std::vector<int>& nums) -> int {
    int n = nums.size();

    if (n <= 1) return 0;

    int jumps = 0;
    int current_end = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = std::max(farthest, i + nums[i]);

        if (i == current_end) {
            jumps++;
            current_end = farthest;  // Update the next end if next position is not reachable

            // Finish if current_end reaches or exceeds the last index
            if (current_end >= n - 1) break;
        }
    }

    return jumps;
}

auto main() -> int {

}

/*
index:      0, 1, 2, 3, 4
nums:       2, 3, 1, 1, 4
steps:      ∞, ∞, ∞, ∞, ∞
steps:      1, 1, 1, ∞, ∞
steps:      1, 1, 1, 2, 2
steps:      ∞, ∞, ∞, ∞, ∞
steps:      ∞, ∞, ∞, ∞, ∞
(2)

index:      0, 1, 2, 3, 4
nums:       2, 3, 0, 1, 4
steps:      ∞, ∞, ∞, ∞, ∞
steps:      1, 1, 1, ∞, ∞
steps:      1, 1, 1, 2, 2
steps:      ∞, ∞, ∞, ∞, ∞

index:      0, 1, 2, 3, 4, 5, 6, 7, 8, 9
nums:       4, 2, 3, 1, 1, 1, 3, 1, 3, 1
steps:      ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞
steps:      1, 1, 1, 1, 1, ∞, ∞, ∞, ∞, ∞
steps:      ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞
steps:      ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞
steps:      ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞
steps:      ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞

0, 1, 2, 3, 4, 5, 6, 7, 8, 9
4, 2, 3, 1, 1, 1, 3, 1, 3, 1
4, 3, 5, 4, 5, 6, 9, 8, 9, 9


(4)
*/
