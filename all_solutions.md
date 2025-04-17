# Twosum

```cpp
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>

// auto twoSum(std::vector<int>& nums, int target) -> std::vector<int> {
//     auto num_map = std::unordered_map<int, int>{};

//     for (int i = 0; i < nums.size(); ++i) {
//         if (num_map.contains(target - nums[i])) {
//             return {num_map[target - nums[i]], i};
//         }
//         num_map[nums[i]] = i;
//     }

//     return {};
// }

auto twoSum(std::vector<int>& nums, int target) -> std::vector<int> {
    std::unordered_map<int, int> num_map;

    for (int i = 0; i < nums.size(); ++i) {
        if (num_map.contains(target - nums[i])) {
            return {num_map[target - nums[i]], i};
        } else {
            num_map[nums[i]] = i;
        }
    }

    return {};
}

auto main() -> int {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto result = twoSum(nums, target);
    std::cout << result[0] << ", " << result[1] << std::endl;
    return 0;
}
```

# Same Tree

```cpp
#include <iostream>
#include "TreeNode.h"

//     1
//    / \
//   2   3
//  / \
// X   X
// 
//     1
//    / \
//   2   3
//  / \
// X   X

// logic that nullptr's return true
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (not p and not q) return true;

    if (p and q and p->val == q->val) {
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    } else {
        // if p and not q, or
        //    not p and q,
        // this won't be a valid test case anyways
        return false;
    }
}

int main() {

}
```

# Max Consecutive Ones 3

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int longestOnes(std::vector<int>& nums, int k) {
    // Sliding window, but window size can change all the time
    // If next element is 1, ++right
    // If next element is 0 and zeroes_used is <= k, ++right, ++zeroes_used
    // Else, ++left. If zero encountered, --zeroes_used
    // Terminate when right >= nums.size()    
    int left = 0;
    int right = 0;
    int zeroes_used = 0;
    int max_size = 0;

    while (right < nums.size()) {
        if (nums[right] == 0) ++zeroes_used;

        while (zeroes_used > k) {
            if (nums[left] == 0) --zeroes_used;
            ++left;
        }

        max_size = std::max(max_size, right - left + 1);
        ++right;
    }

    return max_size;
}

int main() {
    std::vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    std::cout << longestOnes(nums1, 2) << std::endl;

    std::vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    std::cout << longestOnes(nums2, 3) << std::endl;
}
```

# Binary Tree Level Order Traversal

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include "TreeNode.h"

void dfs(std::vector<std::vector<int>>& result, TreeNode* node, int depth) {
    if (not node) return;

    if (result.size() == depth) {
        result.push_back(std::vector<int>());
    }

    result[depth].push_back(node->val);
    if (node->left) dfs(result, node->left, depth + 1);
    if (node->right) dfs(result, node->right, depth + 1);
}

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    dfs(result, root, 0);
    return result;
}

int main() {

}
```

# Maximum Depth Binary Tree

```cpp
#include <iostream>
#include <algorithm>
#include "TreeNode.h"

int maxDepth(TreeNode* root) {
    if (not root) return 0;

    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main() {

}
```

# Last Stone Weight

```cpp
#include <iostream>
#include <vector>
#include <queue>

int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> queue;
    for (int stone : stones) {
        queue.push(stone);
    }

    while (queue.size() > 1) {
        int y = queue.top();
        queue.pop();
        int x = queue.top();
        queue.pop();

        if (x < y) {
            queue.push(y - x);
        }
    }

    if (queue.size() == 1) {
        return queue.top();
    } else {
        return 0;
    }    
}

int main() {
    std::vector<int> stones = {2,7,4,1,8,1};
    std::cout << lastStoneWeight(stones) << std::endl;

    std::vector<int> stones1 = {2,2};
    std::cout << lastStoneWeight(stones1) << std::endl;
}
```

# Gcd Strings

```cpp
#include <iostream>
#include <string>
#include <algorithm>

auto gcdOfStrings(std::string str1, std::string str2) -> std::string {
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    int gcd = std::__gcd(str1.length(), str2.length());

    return str1.substr(0, gcd);
}

int main() {
    std::cout << gcdOfStrings("ABCABC", "ABC") << std::endl;
    std::cout << gcdOfStrings("ABABAB", "AB") << std::endl;
    std::cout << gcdOfStrings("LEET", "CODE") << std::endl;
}
```

# Container With Most Water

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {
    // Naive solution: O(N^2)

    int left = 0;
    int right = height.size() - 1;

    int max_water = 0;

    while (left < right) {
        int curr_water = std::min(height[left], height[right]) * (right - left);
        max_water = std::max(curr_water, max_water);

        // std::cout << left << " " << right << std::endl;

        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return max_water;
}

int main() {
    std::vector<int> heights1 = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(heights1) << std::endl;

    std::vector<int> heights2 = {1,1};
    std::cout << maxArea(heights2) << std::endl;

    std::vector<int> heights3 = {8,7,2,1};
    std::cout << maxArea(heights3) << std::endl;
}
```

# Balanced Binary Tree

```cpp
#include <iostream>
#include <algorithm>
#include "TreeNode.h"

int getHeight(TreeNode* root) {
    if (not root) return 0;

    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(TreeNode* root) {
    if (not root) return true;

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if (std::abs(right - left) > 1) return false;

    return isBalanced(root->left) and isBalanced(root->right);
}

int main() {
    
}
```

# Longest Common Subsequence

```cpp
#include <iostream>
#include <string>
#include <vector>

int longestCommonSubsequence(std::string text1, std::string text2) {
    // DP
    // Definition) dp[i][j]: Length of longest common subsequence of text1[0 ~ i] & text2[0 ~ j]
    //        e.g. dp[3][2]: Length of longest common subsequence of "abc" and "ac"
    // Base Case ) All of dp[i][0] or dp[0][j] is initialised to 0 or 1
    // Recurrence) dp[i][j] = dp[i-1][j-1] + 1, or max(dp[i][j-1], dp[i-1][j])

    // DRAW IT OUT!

    //   a b c d e
    // a 1 1 1 1 1
    // b 1 2 2 2 2
    // c 1 2 3 3 3

    //   a b c f
    // d 0 0 0 0
    // a 1 1 1 1
    // f 1 1 1 2

    std::vector<std::vector<int>> dp(text2.size(), std::vector<int>(text1.size(), 0));
    if (text1[0] == text2[0]) dp[0][0] = 1;
    else dp[0][0] = 0;

    // Initialise horizontal
    for (int i = 1; i < text1.size(); ++i) {
        if (dp[0][i-1] == 1) dp[0][i] = 1;
        else {
            if (text1[i] == text2[0]) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
    }

    // Initialise vertical
    for (int i = 1; i < text2.size(); ++i) {
        if (dp[i-1][0] == 1) dp[i][0] = 1;
        else {
            if (text1[0] == text2[i]) dp[i][0] = 1;
            else dp[i][0] = 0;
        }
    }

    // Whole DP, dp[i][j]
    for (int i = 1; i < text2.size(); ++i) {
        for (int j = 1; j < text1.size(); ++j) {
            if (text1[j] == text2[i]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    for (auto vec : dp) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return dp[text2.size() - 1][text1.size() - 1];
}

int main() {
    std::cout << longestCommonSubsequence("abcde", "ace") << std::endl;
    std::cout << longestCommonSubsequence("abc", "abc") << std::endl;
    std::cout << longestCommonSubsequence("abc", "def") << std::endl;
}
```

# Pascals Triangle

```cpp
#include <vector>
#include <iostream>

auto print_result(std::vector<std::vector<int>>& result) {
    for (std::vector<int> line : result) {
        for (int num : line) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void make_tree(std::vector<std::vector<int>>& result, std::vector<int>& curr, int depth, int numRows) {
    result.push_back(curr);
    if (depth >= numRows) return;

    std::vector<int> next;

    ++depth;
    for (int i = 0; i < depth; ++i) {
        if (i == 0) {
            next.push_back(1);
        } else if (i == depth - 1) {
            next.push_back(1);
        } else {
            next.push_back(curr[i - 1] + curr[i]);
        }
    }
    make_tree(result, next, depth, numRows);
}

auto generate(int numRows) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;
    std::vector<int> curr = {1};
    make_tree(result, curr, 1, numRows);
    return result;
}

auto main() -> int {
    std::vector<std::vector<int>> result = generate(5);
    print_result(result);
}```

# Minimum Knight Moves

```cpp
#include <iostream>
#include <queue>
#include <utility>

int minKnightMoves(int x, int y) {
    // Implement BFS.
    // { order, { x, y } }

    std::queue<std::pair<int, std::pair<int, int>>> coords;
    coords.push(std::make_pair(0, std::make_pair(0, 0)));

    std::vector<std::pair<int, int>> directions = {
        {2, 1}, {2, -1}, {1, 2}, {1, -2}, 
        {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}
    };

    while (not coords.empty()) {
        // 1. Pop off queue, and check the coords
        auto curr = coords.front();
        int moves = curr.first;
        int curr_x = curr.second.first;
        int curr_y = curr.second.second;
        coords.pop();

        // std::cout << curr_x << ", " << curr_y << std::endl;

        if (curr_x == x and curr_y == y) return moves;

        for (const auto& direction : directions) {
            coords.push(std::make_pair(moves + 1, std::make_pair(curr_x + direction.first, curr_y + direction.second)));
        }
    }

    return 0;
}

int main() {
    std::cout << minKnightMoves(0, 0) << std::endl;     // 0
    std::cout << minKnightMoves(1, 2) << std::endl;     // 1
    std::cout << minKnightMoves(1, 1) << std::endl;     // 2
    std::cout << minKnightMoves(3, 3) << std::endl;     // 2
    std::cout << minKnightMoves(5, 5) << std::endl;     // 4
}
```

# Unique Number Of Occurrences

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool uniqueOccurrences(std::vector<int>& arr) {
    std::unordered_map<int, int> num_map;
    std::unordered_set<int> num_set;

    for (const int& num : arr) {
        ++num_map[num];
    }

    for (const auto& [key, val] : num_map) {
        if (num_set.find(val) == num_set.end()) {
            num_set.insert(val);
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<int> arr1 = {1,2,2,1,1,3};
    std::vector<int> arr2 = {1,2};
    std::vector<int> arr3 = {-3,0,1,-3,1,1,1,-3,10,0};

    std::cout << std::boolalpha << uniqueOccurrences(arr1) << std::endl;
    std::cout << std::boolalpha << uniqueOccurrences(arr2) << std::endl;
    std::cout << std::boolalpha << uniqueOccurrences(arr3) << std::endl;
}
```

# Buy Sell Stocks

```cpp
#include <vector>
#include <iostream>
#include <climits>

// 7, 1, 5, 3, 6, 4
// Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

// 7, 6, 4, 3, 1
// In this case, no transactions are done and the max profit = 0
int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 1; i < prices.size(); ++i) {
        max_profit = std::max(max_profit, prices[i] - min_price);
        min_price = std::min(min_price, prices[1]);
    }

    return max_profit;
}

auto main() -> int {
    std::vector<int> prices1 = {7,1,5,3,6,4};
    std::cout << maxProfit(prices1) << std::endl;

    std::vector<int> prices2 = {7,6,4,3,1};
    std::cout << maxProfit(prices2) << std::endl;
}
```

# Binary Tree Max Path Sum

```cpp
#include <iostream>
#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* curr, int& curr_max) {
    // If nullptr, return 0
    // For max, update as curr->val + helper(curr->left, curr_max) + helper(curr->right, curr_max)
    // For path (return), update as curr->val + std::max(helper(curr->left, curr_max), helper(curr->right, curr_max))

    if (curr == nullptr) return 0;

    // Ignore negative numbers
    int left_max = std::max(0, helper(curr->left, curr_max));
    int right_max = std::max(0, helper(curr->right, curr_max));

    // Update maximum
    curr_max = std::max(curr_max, curr->val + left_max + right_max);

    // Return largest path
    return curr->val + std::max(left_max, right_max);
}

int maxPathSum(TreeNode* root) {
    int curr_max = INT_MIN;
    helper(root, curr_max);

    return curr_max;
}

int main() {

}
```

# Valid Palindrome

```cpp
#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
    std::string modified = "";

    for (char c : s) {
        if ((c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')) {
            modified += c;
        } else if (c >= 'A' and c <= 'Z') {
            modified += (c + 32);
        }
    }

    int left = 0;
    int right = modified.size() - 1;

    while (left < right) {
        if (modified[left] != modified[right]) return false;
        ++left;
        --right;
    }

    return true;
}

int main() {
    std::cout << std::boolalpha << isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    std::cout << std::boolalpha << isPalindrome("race a car") << std::endl;
}
```

# Longest Consecutive Sequence

```cpp
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> numbers;

    for (int num : nums) {
        numbers.insert(num);
    }

    int max = 0;

    for (int num : numbers) {
        if (numbers.find(num - 1) == numbers.end()) {
            // We have a place to start, keep looping
            int size = 1;
            int curr = num;

            while (numbers.find(curr + 1) != numbers.end()) {
                ++size;
                ++curr;
            }

            max = std::max(size, max);
        }
    }

    return max;
}

auto main() -> int {
    std::vector<int> nums1 = {100,4,200,1,3,2};
    std::cout << longestConsecutive(nums1) << std::endl;

    std::vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    std::cout << longestConsecutive(nums2) << std::endl;

    std::vector<int> nums3 = {};
    std::cout << longestConsecutive(nums3) << std::endl;

    std::vector<int> nums4 = {1,2,0,1};
    std::cout << longestConsecutive(nums4) << std::endl;

    std::vector<int> nums5 = {0,0};
    std::cout << longestConsecutive(nums5) << std::endl;
}
```

# Divide Array In Sets K Consecutive Numbers

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

bool isPossibleDivide(std::vector<int>& nums, int k) {
    int size = nums.size();
    if (size % k != 0) return false;

    // Get count
    std::unordered_map<int, int> count;
    for (const int& num : nums) {
        ++count[num];
    }

    // Loop through numbers
    std::sort(nums.begin(), nums.end());
    for (const int& num : nums) {
        if (count[num] <= 0) continue;

        // Start loop
        for (int i = num; i < num + k; ++i) {
            if (count[i] <= 0) return false;
            --count[i];
        }
    }

    return true;
}

int main() {

}
```

# Roman To Int

```cpp
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

auto romanToInt(std::string s) -> int {
    std::map<char, int> roman_values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    std::reverse(s.begin(), s.end());

    int total = 0;
    int prev = 0;

    for (int i = 0; i < s.length(); i++) {
        int curr = roman_values[s[i]];

        if (prev > curr) {
            total -= roman_values[s[i]];
        } else {
            total += roman_values[s[i]];
        }

        prev = curr;
    }

    return total;
}

auto main() -> int {
    std::cout << romanToInt("MMCCCXCIV") << std::endl;
}```

# Palindrome Partitioning

```cpp
#include <vector>
#include <string>
#include <iostream>

bool is_palindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

/*
s = "aaab"
output = [["a","a","a","b"],["a","aa","b"],["aa","a","b"],["aaa","b"]]

{}
{a}                      {aa}       {aaa}
{a, a}       {a, aa}     {aa, a}    {aaa, b}
{a, a, a}    {a, aa, b}  {aa, a, b}
{a, a, a, b}
*/
void backtrack(std::vector<std::vector<std::string>>& result, std::vector<std::string>& curr, 
    const std::string& s, int index, int size) {
    
    if (index == size) {
        result.push_back(curr);
        return;
    }

    for (int i = index; i < size; ++i) {
        std::string substring = s.substr(index, i - index + 1);

        if (!is_palindrome(substring)) continue;

        curr.push_back(substring);
        backtrack(result, curr, s, i + 1, size);
        curr.pop_back();
    }
}

auto partition(std::string s) -> std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> curr;
    backtrack(result, curr, s, 0, s.size());
    return result;
}

auto print_result(std::vector<std::vector<std::string>>& result) {
    for (std::vector<std::string> set : result) {
        for (std::string val : set) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    std::vector<std::vector<std::string>> result = partition("aaab");
    print_result(result);
}
```

# Single Number

```cpp
#include <vector>
#include <iostream>

int singleNumber(std::vector<int>& nums) {
    // Uses XOR.
    // a ^ a = 0
    // a ^ 0 = a
    // a ^ b ^ a = b ^ a ^ a

    int result = 0;
    for (int num : nums) {
        result ^= num;
        std::cout << result << " - ";
    }
    std::cout << std::endl;
    return result;
}

auto main() -> int {
    std::vector<int> nums1 = {2,2,1};
    std::vector<int> nums2 = {4,1,2,1,2};
    std::vector<int> nums3 = {1};
    
    std::cout << singleNumber(nums1) << std::endl;
    std::cout << singleNumber(nums2) << std::endl;
    std::cout << singleNumber(nums3) << std::endl;
}
```

# Word Break

```cpp
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
    int size = s.size();
    std::vector<bool> dp(size + 1, false);
    dp[0] = true;

    for (int i = 1; i <= size; ++i) {
        for (int j = 0; j < i; ++j) {
            // Finding if string up to j can be split into 2 valid word-sets
            if (dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end()) {
                dp[i] = true;
                break; // No need to continue j-loop
            }
        }
    }

    return dp[size];
}

auto main() -> int {
    std::vector<std::string> dict = {"cats","dog","sand","and","cat"};
    std::cout << std::boolalpha << wordBreak("catsandog", dict) << std::endl;

    std::vector<std::string> dict1 = {"apple", "pen"};
    std::cout << std::boolalpha << wordBreak("applepenapplepen", dict1) << std::endl;
}
```

# Longest Common Prefix

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// auto longestCommonPrefix(std::vector<std::string>& strs) -> std::string {
//     if (strs.empty()) return "";

//     std::string prefix = strs[0];

//     for (int i = 1; i < strs.size(); ++i) {

//         // start by comparing entire prefix and current str
//         // cut down character by character until we have a match (index 0 represents this)

//         while (strs[i].find(prefix) != 0) {
//             prefix = prefix.substr(0, prefix.length() - 1);
//             if (prefix == "") return "";
//         }
//     }

//     return prefix;
// }

auto longestCommonPrefix(std::vector<std::string>& strs) -> std::string {
    if (strs.empty()) return "";

    // Start with whole string, subtract characters from the back
    std::string prefix = strs[0];

    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            // Returning 0 means that it is found at the start

            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix == "") return "";
        }
    }

    return prefix;
}

auto main() -> int {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << longestCommonPrefix(strs) << std::endl;
    
    strs = {"dog", "racecar", "car"};
    std::cout << longestCommonPrefix(strs) << std::endl;
}```

# Greatest Number Candies

```cpp
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
```

# Count Good Nodes In Binary Tree

```cpp
#include <iostream>
#include "TreeNode.h"

void dfs(TreeNode* node, int& result, int max) {
    // +1 to result if node->val >= max
    if (node->val >= max) {
        ++result;
        max = node->val;
    }

    if (node->left) dfs(node->left, result, max);
    if (node->right) dfs(node->right, result, max);
}

int goodNodes(TreeNode* root) {
    if (not root) return 0;

    int result = 1;

    if (root->left) dfs(root->left, result, root->val);
    if (root->right) dfs(root->right, result, root->val);

    return result;
}

int main() {

}
```

# Substring Maximum Vowels

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

bool isVowel(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int maxVowels(std::string s, int k) {
    int max_vowels = 0, count = 0;

    // Count vowels in the first window
    for (int i = 0; i < k; ++i) {
        if (isVowel(s[i])) ++count;
    }
    max_vowels = count;

    // Sliding window (Not O(N^2) time complexity)
    for (int i = k; i < s.size(); ++i) {
        if (isVowel(s[i])) ++count;
        if (isVowel(s[i - k])) --count;
        max_vowels = std::max(max_vowels, count);
    }

    return max_vowels;
}

int main() {
    std::cout << maxVowels("abciiidef", 3) << std::endl;
    std::cout << maxVowels("aeiou", 2) << std::endl;
    std::cout << maxVowels("leetcode", 3) << std::endl;
    std::cout << maxVowels("weallloveyou", 7) << std::endl;
}
```

# Longest Subarray Of 1s

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int longestSubarray(std::vector<int>& nums) {
    // Sliding window, but window size can change all the time
    // If next element is 1, ++right
    // If next element is 0 and zeroes_used is <= k, ++right, ++zeroes_used
    // Else, ++left. If zero encountered, --zeroes_used
    // Terminate when right >= nums.size()    
    int left = 0;
    int right = 0;
    int zeroes_used = 0;
    int max_size = 0;

    while (right < nums.size()) {
        if (nums[right] == 0) ++zeroes_used;

        while (zeroes_used > 1) {
            if (nums[left] == 0) --zeroes_used;
            ++left;
        }

        max_size = std::max(max_size, right - left);
        ++right;
    }

    return max_size;
}

int main() {
    // std::vector<int> nums1 = {1,1,0,1};
    // std::cout << longestSubarray(nums1) << std::endl;

    // std::vector<int> nums2 = {0,1,1,1,0,1,1,0,1};
    // std::cout << longestSubarray(nums2) << std::endl;

    std::vector<int> nums3 = {1,0,1,1,1,1,1,1,0,1,1,1,1,1};
    std::cout << longestSubarray(nums3) << std::endl;
}
```

# 3sum

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

auto threeSum(std::vector<int>& nums) -> std::vector<std::vector<int>> {
    std::sort(nums.begin(), nums.end());
    auto vectors = std::vector<std::vector<int>>{};

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 and nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) break;

        int target = nums[i];
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = target + nums[left] + nums[right];

            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                vectors.push_back({target, nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
        }
    }

    std::sort(vectors.begin(), vectors.end());
    auto last = std::unique(vectors.begin(), vectors.end());
    vectors.erase(last, vectors.end());

    return vectors;
}

auto main() -> int {
    auto nums = std::vector<int>{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> vecs = threeSum(nums);

    for (const auto& vec : vecs) {
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
```

# Reverse Polish Notation

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <stack>

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> numbers;

    for (std::string& token : tokens) {
        if (token == "+") {
            int first = numbers.top();
            numbers.pop();
            int second = numbers.top();
            numbers.pop();
            numbers.push(second + first);
        } else if (token == "-") {
            int first = numbers.top();
            numbers.pop();
            int second = numbers.top();
            numbers.pop();
            numbers.push(second - first);
        } else if (token == "*") {
            int first = numbers.top();
            numbers.pop();
            int second = numbers.top();
            numbers.pop();
            numbers.push(second * first);
        } else if (token == "/") {
            int first = numbers.top();
            numbers.pop();
            int second = numbers.top();
            numbers.pop();
            numbers.push(second / first);
        } else {
            numbers.push(std::stoi(token));
        }
    }

    return numbers.top();
}

int main() {
    std::vector<std::string> tokens1 = {"2","1","+","3","*"};
    std::vector<std::string> tokens2 = {"4","13","5","/","+"};
    std::vector<std::string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    std::cout << evalRPN(tokens1) << std::endl;
    std::cout << std::endl;
    std::cout << evalRPN(tokens2) << std::endl;
    std::cout << std::endl;
    std::cout << evalRPN(tokens3) << std::endl;
    std::cout << std::endl;
}
```

# Maximum Product

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

int maxProduct(std::vector<int>& nums) {
    int curr_min = nums[0];
    int curr_max = nums[0];
    int whole_max = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        // Swapping is necessary when current num is negative
        if (nums[i] < 0) {
            std::swap(curr_max, curr_min);
        }

        curr_min = std::min(nums[i], curr_min * nums[i]);
        curr_max = std::max(nums[i], curr_max * nums[i]);        
        whole_max = std::max(curr_max, whole_max);
    }

    return whole_max;
}

auto main() -> int {
    std::vector<int> nums = {-1,4,-4,5};
    std::cout << maxProduct(nums) << std::endl;
}
```

# Find Minimum In Sorted Array

```cpp
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    int smallest = INT_MAX;


    // Need a greedy algorithm which tries to find the smallest possible element
    // 0 1 2 3 4 5 6
    // -------------
    // 1 2 3 4 5 6 7
    // 2 3 4 5 6 7 1
    // 3 4 5 6 7 1 2
    // 4 5 6 7 1 2 3
    // 5 6 7 1 2 3 4
    // 6 7 1 2 3 4 5
    // 7 1 2 3 4 5 6
    while (left <= right) {
        int mid = (left + right) / 2;
        smallest = std::min(nums[mid], smallest);

        // Look through right
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 

        // Look through left
        else {
            right = mid - 1;
        }
    }

    return smallest;
}

int main() {

}
```

# Min Stack

```cpp
#include <stack>
#include <iostream>
#include <limits>

class MinStack {
 public:
    MinStack() {}
    
    void push(int val) {
        main_.push(val);
        
        if (min_.empty() or min_.top() >= val) {
            min_.push(val);
        }
    }
    
    void pop() {
        if (main_.top() == min_.top()) {
            min_.pop();
        }
        main_.pop();
    }
    
    int top() {
        return main_.top();
    }
    
    int getMin() {
        return min_.top();
    }

 private:
    std::stack<int> main_;
    std::stack<int> min_;
};

auto main() -> int {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl; // return -3
    minStack.pop();
    std::cout << minStack.top() << std::endl;    // return 0
    std::cout << minStack.getMin() << std::endl; // return -2
}
```

# Two Strings Are Close

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

bool closeStrings(std::string word1, std::string word2) {
    // 1. Swap existing characters
    // abcde -> acedb
    // There needs to be five 1s
    // Technically, (1) is a part of (2)

    // 2. Transform every occurrence of one existing character into another existing character,
    //    and do the same with the other character
    // aacabb -> bbcbaa

    // a3 b2 c1 -> a2 b3 c1
    // There needs to be one 1, one 2, and one 3

    std::unordered_map<char, int> word1_chars;
    std::unordered_map<char, int> word2_chars;
    std::unordered_map<int, int> word1_counts;
    std::unordered_map<int, int> word2_counts;

    for (const char& c : word1) {
        ++word1_chars[c];
    }

    for (const char& c : word2) {
        ++word2_chars[c];
    }

    for (const auto& [key, val] : word1_chars) {
        if (word2_chars[key] == 0) return false;
        ++word1_counts[val];
    }

    for (const auto& [key, val] : word2_chars) {
        if (word1_chars[key] == 0) return false;
        ++word2_counts[val];
    }

    for (const auto& [key, val] : word1_counts) {
        if (word2_counts[key] != val) return false;
    }

    return true;
}

int main() {
    std::cout << std::boolalpha << closeStrings("abc", "bca") << std::endl;
    std::cout << std::boolalpha << closeStrings("a", "aa") << std::endl;
    std::cout << std::boolalpha << closeStrings("cabbba", "abbccc") << std::endl;
}
```

# Twosum2 Sorted

```cpp
#include <iostream>
#include <vector>

// auto twoSum(std::vector<int>& numbers, int target) -> std::vector<int> {
//     int left = 0;
//     int right = 1;
//     std::vector<int> result;

//     while (right < numbers.size() and left < right) {
//         int sum = numbers[left] + numbers[right];

//         if (sum > target) {
//             ++left;
//         } else if (sum < target) {
//             ++right;
//         } else {
//             result.push_back(++left);
//             result.push_back(++right);
//         }
//     }

//     return result;
// }

auto twoSum(std::vector<int>& numbers, int target) -> std::vector<int> {
    int left = 0;
    int right = numbers.size() - 1;
    std::vector<int> result;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum > target) {
            --right;
        } else if (sum < target) {
            ++left;
        } else {
            result.push_back(++left);
            result.push_back(++right);
        }
    }

    return result;
}

void print_result(std::vector<int>& numbers) {
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums1 = {2,7,11,15};
    std::vector<int> nums2 = {2,3,4};
    std::vector<int> nums3 = {-1,0};

    auto result1 = twoSum(nums1, 9);
    auto result2 = twoSum(nums2, 6);
    auto result3 = twoSum(nums3, -1);

    print_result(result1);
    print_result(result2);
    print_result(result3);
}
```

# Max Number Of K Sum Pairs

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

int maxOperations(std::vector<int>& nums, int k) {
    int operations = 0;

    std::unordered_map<int, int> num_count;

    for (int i = 0; i < nums.size(); ++i) {
        if (num_count[k - nums[i]] > 0) {
            --num_count[k - nums[i]];
            ++operations;
        } else {
            ++num_count[nums[i]];
        }
    }

    return operations;
}

int main() {
    std::vector<int> nums1 = {1,2,3,4};
    std::cout << maxOperations(nums1, 5) << std::endl;

    std::vector<int> nums2 = {3,1,3,4,3};
    std::cout << maxOperations(nums2, 6) << std::endl;
}
```

# Majority Element

```cpp
#include <vector>
#include <iostream>

int majorityElement(std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    int count = 1;
    int majority = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == majority) {
            ++count;
        } else {
            --count;
            if (count == 0) {
                majority = nums[i];
                count = 1;
            }
        }
    }

    return majority;
}

auto main() -> int {
    std::vector<int> vec1 = {3,2,3};
    std::cout << majorityElement(vec1) << std::endl;

    std::vector<int> vec2 = {2,2,1,1,1,2,2};
    std::cout << majorityElement(vec2) << std::endl;
}
```

# Letter Combinations

```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

// auto backtrack(
//     std::string curr, 
//     std::string remaining, 
//     std::unordered_map<char, std::string>& letters, 
//     std::vector<std::string>& result) -> void {

//     if (remaining == "") {
//         result.push_back(curr);
//         return;
//     }

//     std::string curr_chars = letters[remaining[0]];
//     std::string new_remaining = remaining.substr(1);

//     for (char& ch : curr_chars) {
//         backtrack(curr + ch, new_remaining, letters, result);
//     }
// }

// auto letterCombinations(std::string digits) -> std::vector<std::string> {
//     if (digits.length() == 0) return {};

//     auto letters = std::unordered_map<char, std::string>{
//         {'2', "abc"},
//         {'3', "def"},
//         {'4', "ghi"},
//         {'5', "jkl"},
//         {'6', "mno"},
//         {'7', "pqrs"},
//         {'8', "tuv"},
//         {'9', "wxyz"},
//     };

//     auto result = std::vector<std::string>{};

//     backtrack("", digits, letters, result);

//     return result;
// }

void backtrack(std::vector<std::string>& result, std::unordered_map<char, std::string>& letters, std::string digits, std::string curr) {
    // 1. Get the first number of the current digits string
    // 2. Get the letters related to current string
    // 3. Traverse each character through string, append to curr
    // 4. Backtrack

    if (digits == "") {
        result.push_back(curr);
        return;
    }

    char first_number = digits[0];
    std::string letter_combination = letters[first_number];

    for (const char& ch : letter_combination) {
        std::string new_curr = curr + ch;
        std::string new_digits = digits.substr(1, digits.size() - 1);
        backtrack(result, letters, new_digits, new_curr);
    }
}

auto letterCombinations(std::string digits) -> std::vector<std::string> {
    if (digits.length() == 0) return {};

    auto letters = std::unordered_map<char, std::string>{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    std::vector<std::string> result;
    backtrack(result, letters, digits, "");
    return result;
}

auto print_result(std::vector<std::string> result) -> void {
    for (auto it = result.begin(); it != result.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

auto main() -> int {
    auto digits1 = "23";
    auto result1 = letterCombinations(digits1);
    print_result(result1);
}
```

# Highest Altitude

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int largestAltitude(std::vector<int>& gain) {
    int curr_altitude = 0;
    int max_altitude = 0;

    // For each difference, calculate the current altitude.

    for (const int& diff : gain) {
        curr_altitude += diff;
        max_altitude = std::max(max_altitude, curr_altitude);
    }

    return max_altitude;
}

int main() {
    std::vector<int> gain1 = {-5,1,5,0,-7};
    std::cout << largestAltitude(gain1) << std::endl;

    std::vector<int> gain2 = {-4,-3,-2,-1,4,3,2};
    std::cout << largestAltitude(gain2) << std::endl;
}
```

# Merge Strings Alternatively

```cpp
#include <string>
#include <algorithm>
#include <iostream>

auto mergeAlternately(std::string word1, std::string word2) -> std::string {
    int max_len = std::max(word1.length(), word2.length());

    // Keep adding to a string
    std::string result = "";

    for (int i = 0; i < max_len; ++i) {
        // Process word1
        if (i < word1.length()) {
            result += word1[i];
        }
        
        // Process word2
        if (i < word2.length()) {
            result += word2[i];
        }
    }

    return result;
}

int main() {
    std::cout << mergeAlternately("abc", "pqr") << std::endl;
    std::cout << mergeAlternately("ab", "pqrs") << std::endl;
    std::cout << mergeAlternately("abcd", "pq") << std::endl;
}
```

# Rotate Array

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void print_result(std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    // 7,6,5,4,3,2,1
    std::reverse(nums.begin(), nums.end());

    // 5,6,7,4,3,2,1
    std::reverse(nums.begin(), nums.begin() + k);

    // 5,6,7,1,2,3,4
    std::reverse(nums.begin() + k, nums.end());
}

auto main() -> int {
    std::vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    std::cout << "This is the result -" << std::endl;
    print_result(nums);
}
```

# House Robber

```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

int rob(std::vector<int>& nums) {
    // 1: Either skip or rob house
    // 2: Maximum of skipping house or robbing house
    // 3: Values for index 0 and 1

    int n = nums.size();
    std::vector<int> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[0] = nums[0];
        } else if (i == 1) {
            dp[1] = std::max(nums[0], nums[1]);
        } else {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
    }

    return dp[n - 1];
}

auto main() -> int {
    std::vector<int> nums1 = {1,2,3,1};
    std::cout << rob(nums1) << std::endl;

    std::vector<int> nums2 = {2,7,9,3,1};
    std::cout << rob(nums2) << std::endl;
}
```

# Binary Tree Right Side View

```cpp
#include <iostream>
#include <vector>
#include "TreeNode.h"

void dfs(std::vector<int>& result, TreeNode* root, int depth) {
    if (not root) return;

    if (result.size() == depth) {
        result.push_back(root->val);
    }

    if (root->right) {
        dfs(result, root->right, depth + 1);
    }

    if (root->left) {
        dfs(result, root->left, depth + 1);
    }
}

std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    dfs(result, root, 0);
}

int main() {

}
```

# Addtwonums

```cpp
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// 2    4    3
// 5    6    4
// 7    0   7+1
// 
// 9    9    9    9    9    9    9
// 9    9    9    9
// 8    9    9    9    0    0    0    1

// 1. just add 2 numbers (straightforward)
// 2. add only remaining num

// add remainder in next iteration

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


auto addTwoNumbers(ListNode* l1, ListNode* l2) -> ListNode* {
    // Revision: head is only made to initialise, meaningful values are stored afterwards
    ListNode* head = new ListNode();
    ListNode* curr = head;

    int carry = 0;

    // Revision: (l1 || l2 || carry) syntax works in C++, no more C
    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        curr->next = new ListNode(sum);
        curr = curr->next;
    }

    return head->next;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

auto main() -> int {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* list = addTwoNumbers(l1, l2);
    printList(list);
}
```

# Valid Parentheses

```cpp
#include <string>
#include <iostream>
#include <stack>

auto isValid(std::string s) -> bool {
    std::stack<char> brackets;

    for (char& ch : s) {
        if (ch == '(') {
            brackets.push(ch);
        } else if (ch == ')') {
            if (not brackets.empty() and brackets.top() == '(') {
                brackets.pop();
            } else {
                return false;
            }
        } else if (ch == '{') {
            brackets.push(ch);
        } else if (ch == '}') {
            if (not brackets.empty() and brackets.top() == '{') {
                brackets.pop();
            } else {
                return false;
            }
        } else if (ch == '[') {
            brackets.push(ch);
        } else if (ch == ']') {
            if (not brackets.empty() and brackets.top() == '[') {
                brackets.pop();
            } else {
                return false;
            }
        } 
    }

    return brackets.empty();
}

auto main() -> int {
    std::cout << std::boolalpha << isValid("()") << std::endl;
    std::cout << std::boolalpha << isValid("()[]{}") << std::endl;
    std::cout << std::boolalpha << isValid("(]") << std::endl;
    std::cout << std::boolalpha << isValid("([])") << std::endl;
    std::cout << std::boolalpha << isValid("([)]") << std::endl;
    std::cout << std::boolalpha << isValid("]") << std::endl;
}
```

# Number Islands

```cpp
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

void bfs(int i, int j, std::vector<std::vector<char>>& grid) {
    std::queue<std::pair<int, int>> q;
    q.push({i, j});
    
    grid[i][j] = '0';
    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Explore top, bottom, left, right
        for (auto& d : directions) {
            int newX = x + d[0];
            int newY = y + d[1];
            
            if (newX >= 0 && newX < grid.size() and newY >= 0 && newY < grid[0].size() and grid[newX][newY] == '1') {
                grid[newX][newY] = '0';  // Mark as visited
                q.push({newX, newY});
            }
        }
    }
}

int numIslands(std::vector<std::vector<char>>& grid) {
    int islands = 0;
    
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '1') {
                bfs(i, j, grid);
                ++islands;
            }
        }
    }

    return islands;
}

auto main() -> int {
    std::vector<std::vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    std::cout << numIslands(grid1) << std::endl;

    std::vector<std::vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    std::cout << numIslands(grid2) << std::endl;
}```

# Course Schedule

```cpp
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
```

# Trie

```cpp
#include <string>
#include <unordered_map>
#include <iostream>

// class TrieNode {
// public:
//     std::unordered_map<char, TrieNode*> children;
//     bool isEndOfWord = false;
// };

// class Trie {
// public:
//     Trie() {
//         root = new TrieNode();
//     }
    
//     void insert(std::string word) {
//         TrieNode* curr = root;
//         for (char& ch : word) {
//             // Character is inserted already
//             if (curr->children.find(ch) != curr->children.end()) {
//                 curr = curr->children[ch];
//             }
            
//             // Character not inserted, need to make new TrieNode
//             else {
//                 TrieNode* next = new TrieNode();
//                 curr->children[ch] = next;
//                 curr = next;
//             }
//         }
//         curr->isEndOfWord = true;
//     }
    
//     bool search(std::string word) {
//         TrieNode* curr = root;

//         for (char& ch : word) {
//             if (curr->children.find(ch) == curr->children.end()) return false;
//             curr = curr->children[ch];
//         }

//         return curr->isEndOfWord;
//     }
    
//     bool startsWith(std::string prefix) {
//         TrieNode* curr = root;

//         for (char& ch : prefix) {
//             if (curr->children.find(ch) == curr->children.end()) return false;
//             curr = curr->children[ch];
//         }

//         return true;
//     }
// private:
//     TrieNode* root;
// };

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord = false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(std::string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }

        curr->isEndOfWord = true;
    }
    
    bool search(std::string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }

        return curr->isEndOfWord;
    }
    
    bool startsWith(std::string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        
        return true;
    }
private:
    TrieNode* root;
};

auto main() -> int {
    Trie trie;
    trie.insert("apple");
    std::cout << std::boolalpha << trie.search("apple") << std::endl;   // return True
    std::cout << std::boolalpha << trie.search("app") << std::endl;     // return False
    std::cout << std::boolalpha << trie.startsWith("app") << std::endl; // return True
    trie.insert("app");
    std::cout << std::boolalpha << trie.search("app") << std::endl;     // return True
}
```

# Merge Sorted Lists

```cpp
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode* tail = dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != nullptr) {
        tail->next = list1;
    } else if (list2 != nullptr) {
        tail->next = list2;
    }

    ListNode* list = dummy;
    list = list->next;
    delete dummy;

    return list;
}

auto main() -> int {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode* mergedList = mergeTwoLists(list1, list2);

    ListNode* current = mergedList;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
```

# House Robber Ii

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int rob_specific(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    
    for (int i = 2; i < n; ++i) {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    }
    
    return dp[n-1];
}

int rob(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    
    // Exclude first house
    std::vector<int> excludeFirst(nums.begin() + 1, nums.end());

    // Exclude last house
    std::vector<int> excludeLast(nums.begin(), nums.end() - 1);
    
    return std::max(rob_specific(excludeFirst), rob_specific(excludeLast));
}

int main() {

}
```

# Kth Largest Element

```cpp
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

// Priority Queue Solution
// int findKthLargest(std::vector<int>& nums, int k) {
//     std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

//     for (int& num : nums) {
//         min_heap.push(num);

//         if (min_heap.size() > k) {
//             min_heap.pop();
//         }
//     }

//     return min_heap.top();
// }

// Quickselect Solution
// int partition(std::vector<int>& nums, int left, int right) {
//     // Pivot: Far right
//     int pivot = nums[right];
//     int i = left - 1;

//     for (int j = left; j < right; ++j) {
//         if (nums[j] < pivot) {
//             ++i;
//             std::swap(nums[i], nums[j]);
//         }
//     }

//     // Place index in right position
//     std::swap(nums[i + 1], nums[right]);
//     return i + 1;
// }

// int quickselect(std::vector<int>& nums, int k_smallest, int left, int right) {
//     if (left <= right) {
//         int pivot_index = partition(nums, left, right);

//         if (pivot_index == k_smallest) {
//             return nums[pivot_index];
//         } else if (pivot_index > k_smallest) {
//             return quickselect(nums, k_smallest, left, pivot_index - 1);
//         } else {
//             return quickselect(nums, k_smallest, pivot_index + 1, right);
//         }
//     }

//     return -1;
// }

// int findKthLargest(std::vector<int>& nums, int k) {
//     int n = nums.size();
//     // Find the (n - k)th smallest element to get the kth largest
//     return quickselect(nums, n - k, 0, n - 1);
// }

// Counting sort
int findKthLargest(std::vector<int>& nums, int k) {
    int min_value = INT_MAX;
    int max_value = INT_MIN;
    
    for (int& num : nums) {
        min_value = std::min(min_value, num);
        max_value = std::max(max_value, num);
    }
    
    // If min_value = 3, max_value = 9
    // index - value is
    // 0 1 2 3 4 5 6
    // 3 4 5 6 7 8 9
    std::vector<int> count(max_value - min_value + 1);
    for (int& num : nums) {
        count[num - min_value]++;
    }
    
    int remain = k;
    for (int num = count.size() - 1; num >= 0; num--) {
        remain -= count[num];

        if (remain <= 0) {
            return num + min_value;
        }
    }
    
    return -1;
}

auto main() -> int {
    std::vector<int> nums1 = {3,2,1,5,6,4};
    std::cout << findKthLargest(nums1, 2) << std::endl;

    std::vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    std::cout << findKthLargest(nums2, 4) << std::endl;
}
```

# Contains Duplicate

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> numbers;

    for (const int& num : nums) {
        if (numbers.find(num) == numbers.end()) {
            numbers.insert(num);
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    
}```

# Make Parentheses

```cpp
#include <vector>
#include <string>
#include <iostream>

auto backtrack(std::vector<std::string>& result, std::string curr, int open, int close, int n) -> void {
    if (curr.length() == n * 2) {
        result.push_back(curr);
    } 
    
    if (open < n) {
        backtrack(result, curr + "(", open + 1, close, n);
    }

    if (open > close) {
        backtrack(result, curr + ")", open, close + 1, n);
    }
}

auto generateParentheses(int n) -> std::vector<std::string> {
    auto result = std::vector<std::string>{};
    backtrack(result, "", 0, 0, n);
    return result;
}

auto print(std::vector<std::string> result) -> void {
    for (auto it = result.begin(); it != result.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

auto main() -> int {
    auto result1 = generateParentheses(1);
    auto result3 = generateParentheses(3);

    print(result1);
    print(result3);
}
```

# Find Difference Two Arrays

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

auto findDifference(std::vector<int>& nums1, std::vector<int>& nums2) -> std::vector<std::vector<int>> {
    std::unordered_set<int> set1;
    std::unordered_set<int> set2;
    std::vector<int> result1;
    std::vector<int> result2;

    for (int i = 0; i < nums1.size(); ++i) {
        set1.insert(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); ++i) {
        set2.insert(nums2[i]);
    }

    for (auto it = set1.begin(); it != set1.end(); ++it) {
        if (set2.find(*it) == set2.end()) {
            result1.push_back(*it);
        }
    }

    for (auto it = set2.begin(); it != set2.end(); ++it) {
        if (set1.find(*it) == set1.end()) {
            result2.push_back(*it);
        }
    }

    std::sort(result1.begin(), result1.end());
    std::sort(result2.begin(), result2.end());

    return {result1, result2};
}

void print_result(std::vector<std::vector<int>>& result) {
    for (const std::vector<int>& row : result) {
        for (const int& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4,6};
    std::vector<std::vector<int>> result1 = findDifference(nums1, nums2);
    print_result(result1);

    std::vector<int> nums3 = {1,2,3,3};
    std::vector<int> nums4 = {1,1,2,2};
    std::vector<std::vector<int>> result2 = findDifference(nums3, nums4);
    print_result(result2);
}
```

# Invert Binary Tree

```cpp
#include <iostream>
#include <queue>
#include <algorithm>
#include "TreeNode.h"

TreeNode* invertTree(TreeNode* root) {
    if (not root) return nullptr;
    
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (not queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();

        std::swap(node->left, node->right);

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
    }

    return root;
}

int main() {

}
```

# Merge K Sorted Lists

```cpp
#include <vector>
#include <iostream>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};                      // Default constructor
    ListNode(int x) : val(x), next(nullptr) {};                 // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {};    // Constructor with value and next
};

// Attempt 1 (Merge everything together)
// auto mergeKLists(std::vector<ListNode*>& lists) -> ListNode* {
//     std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

//     for (ListNode* node : lists) {
//         ListNode* curr = node;
//         while (node != nullptr) {
//             queue.push(node->val);
//             node = node->next;
//         }
//     }

//     ListNode* dummy = new ListNode();
//     ListNode* curr = dummy;

//     while (not queue.empty()) {
//         int value = queue.top();
//         queue.pop();

//         ListNode* new_node = new ListNode(value);
//         curr->next = new_node;
//         curr = new_node;
//     }

//     curr->next = nullptr;
//     return dummy->next;
// }

auto mergeKLists(std::vector<ListNode*>& lists) -> ListNode* {
    auto cmp = [](ListNode* node1, ListNode* node2) {
        return node1->val > node2->val;
    };

    // dammit what was decltype again?
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> queue;

    for (ListNode* node : lists) {
        if (node != nullptr) queue.push(node);
    }

    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;

    while (not queue.empty()) {
        auto node = queue.top();
        queue.pop();

        curr->next = node;
        curr = node;

        if (node->next != nullptr) {
            queue.push(node->next);
        }
    }

    return dummy->next;
}

int main() {
    
}```

# Kth Smallest Element In Bst

```cpp
#include <iostream>
#include <vector>
#include "TreeNode.h"

void dfs(TreeNode* node, std::vector<int>& arr) {
    if (not node) return;

    dfs(node->left, arr);
    arr.push_back(node->val);
    dfs(node->right, arr);
}

int kthSmallest(TreeNode* root, int k) {
    std::vector<int> arr;
    dfs(root, arr);
    return arr[k - 1];
}

int main() {

}
```

# Lowest Common Ancestor Binary Tree

```cpp
#include <iostream>
#include "TreeNode.h"

TreeNode* find(TreeNode* root, int small, int large) {
    if (root == nullptr) return nullptr;

    if (small <= root->val and root->val <= large) {
        return root;
    } else if (root->val < small) {
        return find(root->right, small, large);
    } else {
        return find(root->left, small, large);
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < q->val) {
        return find(root, p->val, q->val);
    } else {
        return find(root, q->val, p->val);
    }
}

int main() {

}
```

# Equal Row And Column Pairs

```cpp
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
```

# Product Except Self

```cpp
#include <vector>
#include <iostream>

// O(N) space complexity
auto productExceptSelf(std::vector<int>& nums) -> std::vector<int> {
    // -1 |  1 |  0 | -3 |  3

    // Pre
    //  1 | -1 | -1 |  0 |  0

    // Post
    //  0 |  0 | -9 |  3 |  1

    std::vector<int> pre(nums.size(), 0);
    int prod = 1;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0) {
            pre[i] = 1;
        } else {
            prod *= nums[i - 1];
            pre[i] = prod;
        }
    }

    std::vector<int> post(nums.size(), 0);
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (i == nums.size() - 1) {
            post[i] = 1;
        } else {
            prod *= nums[i + 1];
            post[i] = prod;
        }
    }

    std::vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        result.push_back(pre[i] * post[i]);
    }

    return result;
}

// O(1) space complexity (excluding result)
auto productExceptSelf1(std::vector<int>& nums) -> std::vector<int> {
    // -1 |  1 |  0 | -3 |  3
    
    // Pre
    //  1 | -1 | -1 |  0 |  0

    // Post
    //  0 |  0 | -9 |  3 |  1
    int n = nums.size();
    std::vector<int> result(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

auto main() -> int {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result;

    result = productExceptSelf1(nums);
    for (int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    nums = {-1, 1, 0, -3, 3};
    result = productExceptSelf1(nums);
    for (int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
```

# Remove Stars From String

```cpp
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

auto removeStars(std::string s) -> std::string {
    std::stack<char> chars;

    for (char c : s) {
        if (c == '*') {
            chars.pop();
        } else {
            chars.push(c);
        }
    }

    std::string result = "";
    while (not chars.empty()) {
        char c = chars.top();
        chars.pop();
        result += c;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::cout << removeStars("leet**cod*e") << std::endl;   // lecoe
    std::cout << removeStars("erase*****") << std::endl;    // 
}
```

# Valid Anagram

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> count1;
    std::unordered_map<char, int> count2;
    
    for (char& c : s) {
        ++count1[c];
    }

    for (char& c : t) {
        ++count2[c];
    }

    return count1 == count2;
}

int main() {

}
```

# Reverse K Nodes

```cpp
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) return head;
    else if (k == 1) return head;

    // Count number of nodes
    int count = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        ++count;
        curr = curr->next;
    }

    // Check if k is valid
    if (k > count) return head;

    // Reverse nodes
    ListNode* prev = nullptr;
    curr = head;
    ListNode* next = nullptr;
    count = 0;

    while (curr != nullptr and count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = reverseKGroup(head, 3);
    printList(result);

    return 0;
}```

# Minimum Repair Cars

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long repairCars(std::vector<int>& ranks, int cars) {
    std::sort(ranks.begin(), ranks.end());

    long long min = 1;    
    long long max = *min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;

    long long left = 1, right = max;
    long long cars_ = static_cast<long long>(cars);
    long long min_time = max;

    while (left <= right) {
        long long curr_time = (left + right) / 2;

        // This takes O(n) time, where n is size of ranks.

        // 1. For each element, calculate sqrt(curr / ranks[0])
        // 2. Add to max_cars_fixed
        // 3. If max_cars_fixed >= cars, search left. Otherwise search right
        long long max_cars_fixed = 0;
        for (int i = 0; i < ranks.size(); ++i) {
            long long cars_fixed = static_cast<long long>(std::floor(std::sqrt(curr_time / ranks[i])));
            max_cars_fixed += cars_fixed;
            // std::cout << max_cars_fixed << ", " << cars_fixed << std::endl;
        }

        std::cout << left << ", " << right << ", " << curr_time << ": " << max_cars_fixed << std::endl;

        if (max_cars_fixed >= cars_) {
            min_time = std::min(curr_time, min_time);
            right = curr_time - 1;
        } else {
            left = curr_time + 1;
        }
    }

    return min_time;
}

int main() {
    std::vector<int> ranks1 = {4,2,3,1};
    std::vector<int> ranks2 = {5,1,8};

    std::cout << repairCars(ranks1, 10) << std::endl;
    std::cout << repairCars(ranks2, 6) << std::endl;
}
```

# Longest Nondecreasing Subarray

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// int maxNonDecreasingLength(std::vector<int>& nums1, std::vector<int>& nums2) {
//     // 1, 3, 2, 1
//     // 2, 2, 3, 4
//     // 1, 2, 2, 4

//     // 2, 3, 1
//     // 1, 2, 1
//     // 1, 2, 1

//     // 1, 1
//     // 2, 2
//     // 1, 1

//     //   1. Only grab element(s) that are smaller than or equal to last choice
//     // 2-1. If existX: Start from scratch, curr = 0
//     // 2-2. If exist : Choose the smaller

//     int curr = 0, max = 0;
//     int last_chosen = 0;

//     for (int i = 0; i < nums1.size(); ++i) {
//         // 1. Only grab elements smaller than last choice
//         std::vector<int> smaller;
//         if (nums1[i] >= last_chosen) smaller.push_back(nums1[i]);
//         if (nums2[i] >= last_chosen) smaller.push_back(nums2[i]);

//         // 2-1. If no elements are in smaller
//         if (smaller.empty()) {
//             curr = 0;
//             last_chosen = std::min(nums1[i], nums2[i]);
//         } 
        
//         // 2-2. If only one element exists
//         else if (smaller.size() == 1) {
//             last_chosen = smaller[0];
//         } 
        
//         // 2-3. Both elements satisfy conditon
//         else {
//             last_chosen = std::min(nums1[i], nums2[i]);
//         }

//         std::cout << last_chosen << ", ";

//         ++curr;
//         max = std::max(curr, max);
//     }

//     std::cout << std::endl;
//     return max;
// }

int maxNonDecreasingLength(std::vector<int>& nums1, std::vector<int>& nums2) {
    // - 1, 3, 2, 1
    // - 2, 2, 3, 4
    // > 1, 2, 2, 4 (4)

    // 1 | 2 | 3 | 1
    // 1 | 2 | 3 | 4

    // - 11, 7, 7, 9
    // - 19,19, 1, 7
    // > 11, 7, 7, 9 (3)

    // 1 | 1 | 2 | 3
    // 1 | 2 | 1 | 3

    // Let dp[i][0] be the length of the longest non-decreasing ending with nums1[i].
    // Let dp[i][1] be the length of the longest non-decreasing ending with nums2[i].
    
    // Initialize dp[i][0] and dp[i][1] to 1.

    // If nums1[i] >= nums1[i - 1], then dp[i][0] may be dp[i - 1][0] + 1. 
    // If nums1[i] >= nums2[i - 1], then dp[i][0] may be dp[i - 1][1] + 1. 
    // Perform a similar calculation for nums2[i] and dp[i][1].

    int maxLen = 1, prev_dp0 = 1, prev_dp1 = 1;
        
    for (int i = 1; i < nums1.size(); ++i) {
        int cur_dp0 = 1, cur_dp1 = 1;

        if (nums1[i-1] <= nums1[i]) cur_dp0 = prev_dp0 + 1;
        if (nums2[i-1] <= nums1[i]) cur_dp0 = std::max(cur_dp0, prev_dp1 + 1);
        
        if (nums1[i-1] <= nums2[i]) cur_dp1 = prev_dp0 + 1;
        if (nums2[i-1] <= nums2[i]) cur_dp1 = std::max(cur_dp1, prev_dp1 + 1);

        maxLen = std::max({maxLen, cur_dp0, cur_dp1});
        prev_dp0 = cur_dp0;
        prev_dp1 = cur_dp1;
    }
    
    return maxLen;
}

int main() {
    std::vector<int> nums1 = {11,7,7,9};
    std::vector<int> nums2 = {19,19,1,7};

    std::cout << maxNonDecreasingLength(nums1, nums2) << std::endl;

    nums1 = {2,3,1};
    nums2 = {1,2,1};
    std::cout << maxNonDecreasingLength(nums1, nums2) << std::endl;

    nums1 = {5,3,17,5};
    nums2 = {3,6,1,17};
    std::cout << maxNonDecreasingLength(nums1, nums2) << std::endl;
}
```

# Move Zeroes

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void print_vec(std::vector<int>& nums) {
    for (int& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void moveZeroes(std::vector<int>& nums) {
    // Push non-zero elements to forward
    // Keep track of 0s
    //    0 1 0 3 2
    // 
    // 0. 0 1 0 3 2
    // 1. 1 0 0 3 2
    // 2. 1 0 0 3 2
    // 3. 1 3 0 0 2
    // 4. 1 3 2 0 0

    int zero_index = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            std::swap(nums[i], nums[zero_index]);
            ++zero_index;
        }
    }
}

auto main() -> int {
    std::vector<int> nums = {0,1,0,3,8};
    // 0 1 0 3 8
    // 1 0 0 3 8
    // 1 3 0 0 8
    // 1 3 8 0 0
    
    moveZeroes(nums);
    print_vec(nums);
}```

# Find Duplicate Number

```cpp
#include <vector>
#include <unordered_set>
#include <iostream>

int findDuplicate(std::vector<int>& nums) {
    // Phase 1: Detect the cycle. Start loop after moving once
    int slow = nums[0], fast = nums[0];
    slow = nums[slow];
    fast = nums[nums[fast]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    // Phase 2: Find the entry point of the cycle (duplicate number)
    // Proof of this is in Neetcode video (https://youtu.be/wjYnzkAhcNk?si=GMZNNLBnSbs1wyd9)

    // Reset slow to the start of the array
    slow = nums[0];

    // Move both pointers one step at a time
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow; // The duplicate number
}

auto main() -> int {
    std::vector<int> nums;

    nums = {1,3,4,2,2};
    std::cout << findDuplicate(nums) << std::endl;

    nums = {3,1,3,4,2};
    std::cout << findDuplicate(nums) << std::endl;

    nums = {3,3,3,3,3};
    std::cout << findDuplicate(nums) << std::endl;
}
```

# Minimum Equal Sum Replace Zeroes

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    // sum1 = 6,  zeroes1 = 2 -> min 8
    // sum2 = 11, zeroes2 = 1 -> min 12

    // sum1 = 4,  zeroes1 = 2 -> min 6
    // sum2 = 5,  zeroes2 = 0 -> min 5

    // sum1 = 5,  zeroes1 = 2 -> min 7
    // sum2 = 9,  zeroes2 = 0 -> min 9

    long long sum1 = 0, sum2 = 0;
    long long zeroes1 = 0, zeroes2 = 0;

    for (int i = 0; i < nums1.size(); ++i) {
        if (nums1[i] != 0) {
            sum1 += nums1[i];
        } else {
            ++zeroes1;
        }
    }

    for (int i = 0; i < nums2.size(); ++i) {
        if (nums2[i] != 0) {
            sum2 += nums2[i];
        } else {
            ++zeroes2;
        }
    }

    long long max1 = sum1 + zeroes1;
    long long max2 = sum2 + zeroes2;

    std::cout << sum1 << ", " << zeroes1 << std::endl;
    std::cout << sum2 << ", " << zeroes2 << std::endl;

    if (zeroes1 == 0 and zeroes2 == 0) {
        if (sum1 == sum2) return sum1;
        else return -1;
    }

    else if (zeroes1 == 0) {
        // Represents nums1 cannot grow any larger
        // If max1 < max2 return -1
        // Else return max1

        if (max1 < max2) return -1;
        else return max1;
    } 
    
    else if (zeroes2 == 0) {
        // Represents nums2 cannot grow any larger
        // If max1 > max2 return -1
        // Else return max2

        if (max1 > max2) return -1;
        else return max2;
    }
    
    else {
        return std::max(max1, max2);
    }
}

int main() {
    std::vector<int> nums1 = {0,17,20,17,5,0,14,19,7,8,16,18,6};
    std::vector<int> nums2 = {21,1,27,19,2,2,24,21,16,1,13,27,8,5,3,11,13,7,29,7};
    std::cout << minSum(nums1, nums2) << std::endl;

    nums1 = {2,0,2,0};
    nums2 = {1,4};
    std::cout << minSum(nums1, nums2) << std::endl;
}

```

# Median Finder

```cpp
#include <queue>
#include <iostream>

// Min: 
// Max: 3

// Min: 
// Max: 6 3

// Min: 6
// Max: 3

// Min: 6 
// Max: 3 1

// Min: 6 9
// Max: 3

// Min: 6 7 9
// Max: 4 2 1

// Either min = max + 1 or min = max
class MedianFinder {
 public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if (max_heap.empty() or num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        ++size;

        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }

 private:
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int size;
};

auto main() -> int {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    std::cout << obj->findMedian() << std::endl;    // 1.5
    obj->addNum(3);
    std::cout << obj->findMedian() << std::endl;    // 2
    obj->addNum(5);
    std::cout << obj->findMedian() << std::endl;    // 2.5
    obj->addNum(7);
    std::cout << obj->findMedian() << std::endl;    // 3
}
```

# Longest Substring

```cpp
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> characters;
    int left = 0;
    int max_length = 0;

    for (int right = 0; right < s.size(); ++right) {
        // Increment left until duplicate elements are gone
        while (characters.contains(s[right])) {
            characters.erase(s[left]);
            ++left;
        }

        characters.insert(s[right]);
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

auto main() -> int {
    std::string str1 = "abcabcbb";  // abc: 3
    std::string str2 = "bbbbb";     // b  : 1
    std::string str3 = "pwwkew";    // wke: 3
    std::cout << lengthOfLongestSubstring(str1) << std::endl;
    std::cout << lengthOfLongestSubstring(str2) << std::endl;
    std::cout << lengthOfLongestSubstring(str3) << std::endl;
}
```

# Longest Increasing Subsequence

```cpp
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

int lengthOfLIS(std::vector<int>& nums) {
    // 10 9 2 5 3 7 101 18
    // 1  1 1 2 2 3 4   4
    int n = nums.size();
    std::vector<int> dp(n);

    int max_length = 1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[i] = 1;
            continue;
        }

        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max_length = std::max(max_length, dp[i]);
    }

    return max_length;
}

auto main() -> int {
    std::vector<int> nums;

    nums = {10,9,2,5,3,7,101,18};
    std::cout << lengthOfLIS(nums) << std::endl;

    nums = {0,1,0,3,2,3};
    std::cout << lengthOfLIS(nums) << std::endl;

    nums = {7,7,7,7,7,7,7};
    std::cout << lengthOfLIS(nums) << std::endl;
}
```

# Next Permutation

```cpp
#include <vector>

void nextPermutation(std::vector<int>& nums) {
    
}

auto main() -> int {

}
```

# Coin Change

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void print_vector(std::vector<int>& nums) {
    for (int& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1);

    for (int& coin : coins) {
        if (coin > amount) continue;
        dp[coin] = 1;
    }

    for (int i = 1; i <= amount; ++i) {
        dp[i] = -1;

        // If i is 2, and coin is {3, 5}
        for (int& coin : coins) {
            if (i - coin < 0 or dp[i - coin] == -1) continue;
            
            if (dp[i] < 1) {
                dp[i] = dp[i - coin] + 1;
            } else {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    print_vector(dp);

    return dp[amount];
}

auto main() -> int {
    std::vector<int> coins;
    
    coins = {1, 2, 5};
    std::cout << coinChange(coins, 11) << std::endl;

    coins = {2, 5};
    std::cout << coinChange(coins, 7) << std::endl;

    coins = {2};
    std::cout << coinChange(coins, 3) << std::endl;
}
```

# Search Rotated Array

```cpp
#include <vector>
#include <iostream>

int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;

        // Left is sorted
        if (nums[left] <= nums[mid]) {
            // Search in left
            if (nums[left] <= target and target <= nums[mid]) {
                right = mid - 1;
            }

            // Search in right
            else {
                left = mid + 1;
            }
        }

        // Right is sorted
        else {
            // Search in right
            if (nums[mid] <= target and target <= nums[right]) {
                left = mid + 1;
            }

            // Search in left
            else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

auto main() -> int {
    // std::vector<int> nums = {4,5,6,7,0,1,2};

    // std::cout << search(nums, 0) << std::endl;
    // std::cout << search(nums, 3) << std::endl;

    std::vector<int> nums1 = {3,1};

    std::cout << search(nums1, 1) << std::endl;
}
```

# Increasing Triplet Subsequence

```cpp
#include <vector>
#include <iostream>

bool increasingTriplet(std::vector<int>& nums) {
    int small = 2147483647;
    int mid = 2147483647;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < small) {
            small = nums[i];
        } else if (nums[i] < mid) {
            mid = nums[i];
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> nums1 = {1,2,3,4,5};
    std::vector<int> nums2 = {5,4,3,2,1};
    std::vector<int> nums3 = {2,1,5,0,6};

    std::cout << std::boolalpha << increasingTriplet(nums1) << std::endl;
    std::cout << std::boolalpha << increasingTriplet(nums2) << std::endl;
    std::cout << std::boolalpha << increasingTriplet(nums3) << std::endl;
}
```

# First Last Position

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

auto searchRange(std::vector<int>& nums, int target) -> std::vector<int> {
    if (nums.empty()) return {-1, -1};

    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    int firstPos = left;

    if (firstPos >= nums.size() || nums[firstPos] != target) {
        return {-1, -1};
    }

    right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        mid = (left + right) / 2;

        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    int lastPos = right;

    return {firstPos, lastPos};
}

auto main() -> int {
    std::vector nums = {5,7,7,8,8,10};
    std::vector<int> result = searchRange(nums, 8);
    std::cout << result[0] << ", " << result[1] << std::endl;
}
```

# Reverse Vowels

```cpp
#include <string>
#include <iostream>
#include <algorithm>

bool checkVowel(const char& c) {
    return (
        c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
        c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'
    );
}

auto reverseVowels(std::string s) -> std::string {
    std::string vowel_string = "";

    // Get all vowels
    for (const char& c : s) {
        if (checkVowel(c)) {
            vowel_string += c;
        }
    }

    std::reverse(vowel_string.begin(), vowel_string.end());

    // Reversing vowel process
    int vowel_index = 0;
    for (char& c : s) {
        if (checkVowel(c)) {
            c = vowel_string[vowel_index];
            ++vowel_index;
        }
    }

    return s;
}

int main() {
    std::cout << reverseVowels("IceCreAm") << std::endl;
    std::cout << reverseVowels("leetcode") << std::endl;
}
```

# Top K Frequent Elements

```cpp
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>

auto topKFrequent(std::vector<int>& nums, int k) -> std::vector<int> {
    // 1. Make a map
    std::unordered_map<int, int> frequencies;

    for (int num : nums) {
        ++frequencies[num];
    }

    // 2. Calculate frequency
    // Needs to be a min queue because we need to only get the largest elements to stay
    // Stored in { freq, num } format
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;

    for (const auto& [num, freq] : frequencies) {
        queue.push(std::make_pair(freq, num));
        if (queue.size() > k) queue.pop();
    }

    // 3. Return result
    std::vector<int> result;
    while (not queue.empty()) {
        result.push_back(queue.top().second);
        queue.pop();
    }

    std::sort(result.begin(), result.end());

    return result;
}

auto main() -> int {
    std::vector<int> nums = {1,1,1,2,2,3};
    auto result = topKFrequent(nums, 2);
    for (int& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
```

# Search Insert Position

```cpp
#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

auto main() -> int {
    std::vector<int> nums1 = {2, 4, 6, 8, 10, 12, 14, 16, 18};

    std::cout << searchInsert(nums1, 11) << std::endl;
    std::cout << searchInsert(nums1, 10) << std::endl;
    std::cout << searchInsert(nums1, 9) << std::endl;
}
```

# Design Twitter

```cpp
#include <vector>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <queue>

class Twitter {
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push(std::make_pair(timestamp, tweetId));
        ++timestamp;
    }
    
    auto getNewsFeed(int userId) -> std::vector<int> {
        std::priority_queue<std::pair<int, int>> combined;

        if (tweets.find(userId) != tweets.end()) {
            auto temp = tweets[userId];
            while (not temp.empty()) {
                combined.push(temp.top());
                temp.pop();
            }
        }

        for (auto followeeId : following[userId]) {
            if (tweets.find(followeeId) != tweets.end()) {
                auto temp = tweets[followeeId];
                while (not temp.empty()) {
                    combined.push(temp.top());
                    temp.pop();
                }
            }
        }

        std::vector<int> feed;
        while (not combined.empty() and feed.size() < 10) {
            feed.push_back(combined.top().second);
            combined.pop();
        }
        
        return feed;
    }
    
    // FollowerID follows FolloweeID
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    // FollowerID unfollows FolloweeID    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
private:
    // Timestamp
    int timestamp;

    // Stores all following for a user
    std::unordered_map<int, std::unordered_set<int>> following;

    // Stores tweets for a user
    // [user]: { timestamp, tweetId }
    std::unordered_map<int, std::priority_queue<std::pair<int, int>>> tweets;
};

int main() {
    return 0;
}```

# Valid Sudoku

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    int SUDOKU_SIZE = 9;

    // Step 1: Check rows
    for (int i = 0; i < SUDOKU_SIZE; ++i) {
        std::unordered_set<char> seen;
        for (int j = 0; j < SUDOKU_SIZE; ++j) {
            char c = board[i][j];
            if (c == '.') continue;
            if (seen.find(c) != seen.end()) return false;
            seen.insert(c);
        }
    }

    // Step 2: Check columns
    for (int j = 0; j < SUDOKU_SIZE; ++j) {
        std::unordered_set<char> seen;
        for (int i = 0; i < SUDOKU_SIZE; ++i) {
            char c = board[i][j];
            if (c == '.') continue;
            if (seen.find(c) != seen.end()) return false;
            seen.insert(c);
        }
    }

    // Step 3: Check 3x3 sub-boxes
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            std::unordered_set<char> seen;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    char c = board[boxRow + i][boxCol + j];
                    if (c == '.') continue;
                    if (seen.find(c) != seen.end()) return false;
                    seen.insert(c);
                }
            }
        }
    }

    return true;
}

int main() {

}
```

# Insert Delete Getrandom O1

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (numbers.find(val) != numbers.end()) return false;

        // Insert into numbers and lookups
        numbers[val] = size;
        lookups.push_back(val);

        // Increment size
        ++size;
        return true;
    }
    
    bool remove(int val) {
        if (numbers.find(val) == numbers.end()) return false;

        // 1. Erase element
        int index = numbers[val];
        numbers.erase(val);

        // If it's not the last element, perform swap.
        if (index != lookups.size() - 1) {
            int to_replace = lookups.back();
            lookups[index] = to_replace;
            numbers[to_replace] = index;
        }
        
        lookups.pop_back();
        --size;
        return true;
    }
    
    int getRandom() {
        int random = rand() % size;
        return lookups[random];
    }
private:
    int size = 0;
    // { value, index in lookups }
    std::unordered_map<int, int> numbers;
    std::vector<int> lookups;
};

int main() {
    return 0;
}
```

# Combination Sum

```cpp
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

// auto find_combinations(int start, int sum, int target, std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
//     if (sum == target) {
//         result.push_back(current);
//         return;
//     }

//     for (int i = start; i < candidates.size(); ++i) {
//         if (candidates[i] + sum > target) break;

//         current.push_back(candidates[i]);
//         find_combinations(i, sum + candidates[i], target, candidates, current, result);
//         current.pop_back();
//     }
// }

// auto combinationSum(std::vector<int>& candidates, int target) -> std::vector<std::vector<int>> {
//     std::vector<std::vector<int>> result;
//     std::vector<int> current;

//     std::sort(candidates.begin(), candidates.end());

//     find_combinations(0, 0, target, candidates, current, result);

//     return result;
// }

// void backtrack(int curr_index, int curr_sum, std::vector<int> curr_numbers, std::vector<int>& candidates, int& target, std::vector<std::vector<int>>& results) {
//     for (int i = curr_index; i < candidates.size(); ++i) {
//         // Add to curr_sum
//         int new_sum = curr_sum + candidates[i];

//         if (new_sum > target) {
//             return;
//         } else if (new_sum == target) {
//             curr_numbers.push_back(candidates[i]);
//             std::sort(curr_numbers.begin(), curr_numbers.end());
//             results.push_back(curr_numbers);
//             curr_numbers.pop_back();
//         } else {
//             curr_numbers.push_back(candidates[i]);
//             backtrack(i, new_sum, curr_numbers, candidates, target, results);
//             curr_numbers.pop_back();
//         }
//     }
// }

// auto combinationSum(std::vector<int>& candidates, int target) -> std::vector<std::vector<int>> {
//     std::vector<std::vector<int>> results;
//     // std::sort(candidates.begin(), candidates.end());
//     // curr_index, curr_sum, curr_numbers, candidates, target, results
//     // adding curr_sum as a parameter because using std::accumulate causes too much overload
//     backtrack(0, 0, {}, candidates, target, results);
//     return results;
// }

// {2, 3, 6, 7}, 7

// 2                     | 3     | 6 | 7
// 2 2           | 2 3   | 3 3
// 2 2 2 | 2 2 3 | 

void dfs(
    std::vector<int>& candidates, int target, int start, 
    std::vector<int>& currCombination, std::vector<std::vector<int>>& results
    ) {
    
    // Valid combination found if target == 0
    if (target == 0) {
        results.push_back(currCombination);
        return;
    }
    
    for (int i = start; i < candidates.size(); ++i) {
        // Cannot form a sum if the whole sum exceeds the target
        if (candidates[i] > target) {
            break;
        }
        
        // Choose the candidate and add it to the current combination
        currCombination.push_back(candidates[i]);

        // Recur with the updated target and same index (i) because we can reuse the same element
        dfs(candidates, target - candidates[i], i, currCombination, results);

        // Backtrack: remove the last element added before exploring the next candidate
        currCombination.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> results;
    std::vector<int> currCombination;
    std::sort(candidates.begin(), candidates.end());

    dfs(candidates, target, 0, currCombination, results);
    return results;
}

auto main() -> int {
    std::vector<int> candidates = {2, 3, 6, 7};
    std::vector<std::vector<int>> combinations = combinationSum(candidates, 7);

    for (std::vector<int> combination : combinations) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
```

# Is Subsequence

```cpp
#include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t) {
    // Return true is s is a subsequence of t
    int s_index = 0;

    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == s[s_index]) {
            ++s_index;
        }
    }

    return s_index == s.size();
}

int main() {
    std::cout << std::boolalpha << isSubsequence("abc", "ahbgdc") << std::endl; // true
    std::cout << std::boolalpha << isSubsequence("axc", "ahbgdc") << std::endl; // false
}
```

# Decode String

```cpp
#include <string>
#include <stack>
#include <utility>
#include <algorithm>
#include <iostream>

auto decodeString(std::string s) -> std::string {
    // 3[a]2[bc]
    // 3[a2[c]]
    // 2[abc]3[cd]ef

    return "";
}

auto main() -> int {
    std::cout << decodeString("s");
}
```

# Median Arrays

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

auto findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) -> double {
    return 1.0;
}

auto main() -> int {
    auto nums1 = std::vector<int>{1, 2};
    auto nums2 = std::vector<int>{3, 4};

    auto result = findMedianSortedArrays(nums1, nums2);
    std::cout << result << std::endl;
}

// auto findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) -> double {
//     auto nums = nums1;
//     int index1, index2 = 0;

//     nums.insert(nums.end(), nums2.begin(), nums2.end());
//     std::sort(nums.begin(), nums.end());

//     if (nums.size() % 2 == 0) {
//         int index1 = nums.size() / 2;
//         int index2 = index1 - 1;
//         return (static_cast<double>(nums[index1]) + static_cast<double>(nums[index2])) / 2;
//     } else {
//         int index = nums.size() / 2;
//         return static_cast<double>(nums[index]);
//     }
// }```

# Combination Sum Ii

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// 10,1,2,7,6,1,5
// 1 1 2 5 6 7 10

void backtrack(std::vector<int>& candidates, std::vector<std::vector<int>>& result, std::vector<int> curr_vector, int start, int curr_sum, int target) {
    if (curr_sum == target) {
        result.push_back(curr_vector);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] + curr_sum > target) break;
        
        // Stops duplicate element being added 'on the same level'.
        if (i > start and candidates[i] == candidates[i - 1]) continue;

        curr_vector.push_back(candidates[i]);
        backtrack(candidates, result, curr_vector, i + 1, curr_sum + candidates[i], target);
        curr_vector.pop_back();
    }
}

auto combinationSum2(std::vector<int> candidates, int target) -> std::vector<std::vector<int>> {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> result;
    backtrack(candidates, result, {}, 0, 0, target);
    return result;
}

void print_result(std::vector<std::vector<int>> result) {
    for (const auto& vec : result) {
        for (int num : vec) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

int main() {
    auto result1 = combinationSum2({10,1,2,7,6,1,5}, 8);
    auto result2 = combinationSum2({2,5,2,1,2}, 5);
    print_result(result1);
    std::cout << std::endl;
    print_result(result2);
}
```

# First Missing Positive

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

auto firstMissingPositive(std::vector<int>& nums) -> int {
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 and nums[i] <= n and nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1;
}

auto main() -> int {
    std::vector<int> nums = {7,8,9,11,12};
    std::cout << firstMissingPositive(nums) << std::endl;
    
    nums = {1, 2, 0};
    std::cout << firstMissingPositive(nums) << std::endl;
    
    nums = {3, 4, -1, 1};
    std::cout << firstMissingPositive(nums) << std::endl;
}
```

# Partition Equal Subset Sum

```cpp
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

bool canPartition(std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    sum = sum / 2;  // New sum

    // Now, from the current nums, make a DP like the 0/1 Knapsack Problem.
    std::sort(nums.begin(), nums.end());

    // e.g. if 2, 3, 5, 10 -> Check if we can make 10
    
    // We call this the (0/1 Knapsack Problem)

    // Capacity   →  0    1    2    3    4    5    6    7    8    9   10
    // Items ↓
    // 0 items       0    0    0    0    0    0    0    0    0    0    0
    // Item 1 (1, 2) 0    0    2    2    2    2    2    2    2    2    2
    // Item 2 (2, 3) 0    0    2    3    3    5    5    5    5    5    5
    // Item 3 (3, 5) 0    0    2    3    3    5    5    5    5    5   10 -> end
    // Item 4 (4,10) 0    

    // Capacity   →  0    1    2    3    4    5    6
    // Items ↓
    // 0 items       0    0    0    0    0    0    0
    // Item 1 (1, 2) 0    0    2    2    2    2    2
    // Item 2 (2, 2) 0    0    2    2    4    4    4
    // Item 3 (3, 3) 0    0    2    3    3
    // Item 4 (4, 5) 0    0    2    3    3

    std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(sum + 1, 0));

    // Loop 1:     Item loop
    // Loop 2: Capacity loop
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 1; j <= sum; ++j) {
            // i) item number, j) capacity
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Either include or exclude current item
                dp[i][j] = std::max(dp[i - 1][j], nums[i - 1] + dp[i - 1][j - nums[i - 1]]);
            }

            if (dp[i][j] == sum) {
                std::cout << i << ", " << j << std::endl;
                return true;
            }
        }
    }

    return false;
}

auto main() -> int {
    std::vector<int> nums;

    nums = {1, 5, 11, 5};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;

    nums = {1, 2, 3, 5};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;
    
    nums = {3, 9, 1, 7, 4};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;

    nums = {1, 2, 5};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;

    nums = {2, 2, 3, 5};
    std::cout << std::boolalpha << canPartition(nums) << std::endl;
}
```

# Pacific Atlantic Water Flow

```cpp
#include <iostream>
#include <vector>
#include <utility>

void dfs(std::vector<std::vector<int>>& heights, int i, int j, std::vector<std::vector<bool>>& reachable) {
    int m = heights.size(), n = heights[0].size();
    reachable[i][j] = true;
    std::vector<std::pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    for (auto dir : directions) {
        int x = i + dir.first, y = j + dir.second;

        // Check bounds and if the cell is already visited
        if (x < 0 or x >= m or y < 0 or y >= n or reachable[x][y]) continue;

        // Only move if neighbour's height is not less than current cell's height
        if (heights[x][y] < heights[i][j]) continue;

        dfs(heights, x, y, reachable);
    }
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
    if (heights.empty())
        return {};
    int m = heights.size(), n = heights[0].size();

    std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
    std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));
    
    // DFS from borders
    for (int i = 0; i < m; ++i) {
        dfs(heights, i, 0, pacific);        // Left column
        dfs(heights, i, n-1, atlantic);     // Right column
    }

    for (int j = 0; j < n; ++j) {
        dfs(heights, 0, j, pacific);        // Top row
        dfs(heights, m-1, j, atlantic);     // Bottom row
    }
    
    // Collect cells that can reach both oceans
    std::vector<std::vector<int>> result;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pacific[i][j] && atlantic[i][j])
                result.push_back({i, j});
        }
    }
    return result;
}

void print_result(std::vector<std::vector<int>> result) {
    for (auto vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    print_result(pacificAtlantic(heights));
}
```

# Trapping Rain Water

```cpp
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int trap(std::vector<int> height) {
    if (height.empty()) {
        return 0;
    }

    int l = 0;
    int r = height.size() - 1;
    int leftMax = height[l];
    int rightMax = height[r];
    int res = 0;

    while (l < r) {
        if (leftMax < rightMax) {
            l++;
            leftMax = std::max(leftMax, height[l]);
            res += leftMax - height[l];
        } else {
            r--;
            rightMax = std::max(rightMax, height[r]);
            res += rightMax - height[r];
        }
    }
    return res;
}

int trap1(std::vector<int> height) {
    // input     0 1 0 2 1 0 1 3 2 1 2 1
    // maxLeft   0 0 1 1 2 2 2 2 3 3 3 3
    // maxRight  3 3 3 3 3 3 3 2 2 2 1 0
    // min(L, R) 0 0 1 1 2 2 2 2 2 2 1 0
    // output    0 0 1 0 1 2 1 0 0 1 0 0

    int n = height.size();
    if (n == 0) return 0;

    std::vector<int> maxLeft(n), maxRight(n);
    maxLeft[0] = height[0];
    for (int i = 1; i < n; ++i) {
        maxLeft[i] = std::max(maxLeft[i - 1], height[i]);
    }

    maxRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxRight[i] = std::max(maxRight[i + 1], height[i]);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int curr_min = std::min(maxLeft[i], maxRight[i]);
        if (curr_min > height[i]) {
            result += curr_min - height[i];
        }
    }

    return result;
}

int main() {
    std::cout << trap({0,1,0,2,1,0,1,3,2,1,2,1}) << std::endl;
}
```

# Longest Repeating Character Replacement

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int characterReplacement(std::string s, int k) {
    if (s.size() == 0) return 0;

    // Initialise elements

    int max_length = 0;
    int left = 0;
    std::unordered_map<char, int> freq_count;
    int max_freq = 0;

    // AABABBA            map      max
    // A            -> A: 1       | A
    // AA           -> A: 2       | A
    // AAB          -> A: 2, B: 1 | A
    // AABA         -> A: 3, B: 1 | A
    // AABAB    (X) -> A: 3, B: 2 | A
    //   BAB        -> A: 1, B: 2 | B
    //   BABB       -> A: 1, B: 3 | B
    //   BABBA  (X) -> A: 2, B: 3 | B
    //     BBA      -> A: 1, B: 2 | B

    for (int right = 0; right < s.size(); ++right) {
        ++freq_count[s[right]];
        max_freq = std::max(max_freq, freq_count[s[right]]);

        while ((right - left + 1) - max_freq > k) {
            --freq_count[s[left]];
            ++left;
        }

        // Update curr_max_char
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    std::string str1 = "ABAB";
    std::string str2 = "AABABBA";
    std::string str3 = "ABCDDDCBBBBBBBB";
    std::cout << characterReplacement(str1, 2) << std::endl;    // AAAA
    std::cout << characterReplacement(str2, 1) << std::endl;    // AABBBBA or AAAABBA
    std::cout << characterReplacement(str3, 2) << std::endl;
}
```

# Find All Anagrams

```cpp
#include <string>
#include <vector>
#include <iostream>

auto findAnagrams(std::string s, std::string p) -> std::vector<int> {
    std::vector<int> result;
    if (s.size() < p.size()) return result;

    std::vector<int> s_count(26, 0);
    std::vector<int> p_count(26, 0);

    // s is original string, p is 'ab' string
    int count = 0;
    for (char& ch : s) {
        if (count == p.size()) break;
        ++s_count[ch - 'a'];
        ++count;
    }

    for (char& ch : p) {
        ++p_count[ch - 'a'];
    }

    // Finding 'abc', s_size is 10, p_size is 3.
    // 0 1 2 3 4 5 6 7 8 9
    // c b a e b a b a c d

    for (int i = 0; i <= s.size() - p.size(); ++i) {
        // Check equality
        if (s_count == p_count) {
            result.push_back(i);
        }

        // Update s_count, but if last element, break out of for loop
        if (i + p.size() == s.size()) break;

        --s_count[s[i] - 'a'];
        ++s_count[s[i + p.size()] - 'a'];
    }

    return result;
}

void print_result(std::vector<int>& result) {
    for (int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

auto main() -> int {
    std::vector<int> result;
    result = findAnagrams("cbaebabacd", "abc");
    print_result(result);

    result = findAnagrams("abab", "ab");
    print_result(result);
}
```

# String Compression

```cpp
#include <vector>
#include <string>
#include <iostream>

int compress(std::vector<char>& chars) {
    int index = 0;

    // Pseudocode
    // 
    // When iterating:
    // - Keep track of curr_character, and start_index of that character
    // 
    // - If char_count == 1, don't do anything
    // - If char_count >= 1, ++char_count, ++end_index
    // - When next char is different OR end of string:
    //     - Start writing from start_index + 1
    //     - Fill remaining chars until end_index as ' '
    // - After while loop finished, remove all ' 's using std::remove and erase

    while (index < chars.size()) {
        char curr_character = chars[index];
        int char_count = 1;

        // 1. Finding the occurrences for each character
        int start_index = index;
        int end_index = index + 1;
        while (end_index < chars.size() and chars[end_index] == curr_character) {
            ++char_count;
            ++end_index;
        }

        index = end_index;
        // std::cout << curr_character << ": " << char_count << std::endl;
        // std::cout << "S: " << start_index << ", E: " << end_index << std::endl;

        // 2. Replace with Number

        // Continue if there is no chars to replace
        if (char_count == 1) continue;

        // Start writing from start_index + 1
        std::string count_string = std::to_string(char_count);
        for (int i = 0; i < count_string.size(); ++i) {
            ++start_index;
            chars[start_index] = count_string[i];
        }

        // 3. Remove junk chars
        for (int i = start_index + 1; i < end_index; ++i) {
            chars[i] = ' ';
        }
    }

    // 4. Remove all spaces
    chars.erase(std::remove(chars.begin(), chars.end(), ' '), chars.end());
    return chars.size();
}

void print_chars(std::vector<char>& chars) {
    for (const char& c : chars) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<char> chars1 = {'a','a','b','b','c','c','c'};
    std::cout << compress(chars1) << ": ";
    print_chars(chars1);

    std::vector<char> chars2 = {'a'};
    std::cout << compress(chars2) << ": ";
    print_chars(chars2);

    std::vector<char> chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    std::cout << compress(chars3) << ": ";
    print_chars(chars3);

    std::vector<char> chars4 = {'a','b','b','b','b','b','b','b','b','b','b','b','b','c','c','c','c'};
    std::cout << compress(chars4) << ": ";
    print_chars(chars4);
}
```

# Jump Game 2

```cpp
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
```

# Permutations

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> perms = {{}};

    // Initial: perms = {{}}
    //   First: perms = {{1}}
    //  Second: perms = {{1,2}, {2,1}}
    //   Third: perms = {{3,2,1}, {2,3,1}, {2,1,3}, {3,1,2}, {1,3,2}, {1,2,3}}

    for (int num : nums) {
        std::vector<std::vector<int>> new_perms;
        for (const auto& p : perms) {
            for (int i = 0; i <= p.size(); i++) {
                std::vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, num);
                new_perms.push_back(p_copy);
            }
        }
        perms = new_perms;
    }
    return perms;
}

auto print_result(std::vector<std::vector<int>> result) {
    for (auto vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    auto nums = std::vector<int>{1, 2, 3, 4};
    auto result = permute(nums);
    print_result(result);
}
```

# Lfu Cache

```cpp
#include <iostream>
#include <unordered_map>
#include <list>

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min_freq = 0;
    }
    
    int get(int key) {
        // Return -1 if not found
        if (key_value_freq.find(key) == key_value_freq.end()) return -1;

        int value = key_value_freq[key].first;
        int freq = key_value_freq[key].second;

        // Update frequency for the key
        key_value_freq[key].second = freq + 1;

        // Remove key from current frequency list
        freq_keys[freq].erase(key_iter[key]);

        // Update freq_keys and key_iter
        freq_keys[freq + 1].push_front(key);
        key_iter[key] = freq_keys[freq + 1].begin();

        // If current frequency list becomes empty && it was the min frequency, update min_freq
        if (freq_keys[min_freq].empty()) ++min_freq;

        return value;
    }
    
    void put(int key, int value) {
        // Tiny error handling
        if (capacity <= 0) return;

        // Updating value, if key exists
        // Calling get over here also updates the frequency
        if (get(key) != -1) {
            key_value_freq[key].first = value;
            return;
        }

        // Inserting new value, if key doesn't exist

        // Size exceeded - must remove least used
        if (key_value_freq.size() == capacity) {
            // Get LRU key at min frequency
            int key_to_remove = freq_keys[min_freq].back();

            // Remove everything associated with that key
            key_value_freq.erase(key_to_remove);
            freq_keys[min_freq].pop_back();
            key_iter.erase(key_to_remove);
        }

        // Insert new key with frequency 1
        key_value_freq[key] = {value, 1};
        freq_keys[1].push_front(key);
        key_iter[key] = freq_keys[1].begin();

        // Reset min frequency to 1 for the new key
        min_freq = 1;
    }
private:
    int capacity;
    int min_freq;

    // { key, { value, frequency } }
    std::unordered_map<int, std::pair<int, int>> key_value_freq;
    // { frequency, { list of keys } }
    std::unordered_map<int, std::list<int>> freq_keys;
    // { key, iterator to freq_keys }
    std::unordered_map<int, std::list<int>::iterator> key_iter;
};


int main() {
    return 0;
}```

# Rotate Image

```cpp
#include <vector>
#include <iostream>

// void rotate(std::vector<std::vector<int>>& matrix) {
//     // if
//     // 1 2 3
//     // 4 5 6
//     // 7 8 9

//     // read 1 -> 2 -> 3
//     // then paste it as
//     // ? ? 1      ? 4 1
//     // ? ? 2  ->  ? 5 2
//     // ? ? 3      ? 6 3

//     int size = static_cast<int>(matrix.size());

//     std::vector<std::vector<int>> updated(size, std::vector<int>(size, 0));

//     for (int i = 0; i < size; ++i) {
//         for (int j = 0; j < size; ++j) {
//             updated[j][size - 1 - i] = matrix[i][j];
//         }
//     }

//     matrix = updated;
// }

void rotate(std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    std::vector<std::vector<int>> new_matrix(size, std::vector<int>(size, 0));

    // (0,0) (0,1) (0,2)
    // (1,0) (1,1) (1,2)
    // (2,0) (2,1) (2,2)

    // (2,0) (1,0) (0,0)
    // (2,1) (1,1) (0,1)
    // (2,2) (1,2) (0,2)

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            new_matrix[j][size - 1 - i] = matrix[i][j];
        }
    }

    matrix = new_matrix;
}

void print_matrix(std::vector<std::vector<int>>& matrix) {
    for (auto it1 = matrix.begin(); it1 != matrix.end(); ++it1) {
        auto line = *it1;
        for (auto it2 = line.begin(); it2 != line.end(); ++it2) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    std::vector<std::vector<int>> matrix1 = {{1,2,3}, {4,5,6}, {7,8,9}};
    std::vector<std::vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix1);
    rotate(matrix2);    
    print_matrix(matrix1);
    print_matrix(matrix2);
}
```

# Group Anagrams

```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

auto groupAnagrams(std::vector<std::string>& strs) -> std::vector<std::vector<std::string>> {
    std::unordered_map<std::string, std::vector<std::string>> strings;

    for (const auto& str : strs) {
        std::string sorted = str;
        std::sort(sorted.begin(), sorted.end());

        strings[sorted].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& [key, val] : strings) {
        result.push_back(val);
    }

    return result;
}

auto main() -> int {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> grouped = groupAnagrams(words);

    for (const auto& group : grouped) {
        for (const std::string& word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

# Longest Palindromic Substring

```cpp
#include <string>

auto longestPalindrome(std::string s) -> std::string {
    std::string result = "";
    int max_len = 0;
    int left, right;

    for (int i = 0; i < s.size(); ++i) {
        // 1. Odd
        left = i;
        right = i;
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            int str_len = right - left + 1;
            if (str_len > max_len) {
                result = s.substr(left, str_len);
                max_len = str_len;
            }
            --left;
            ++right;
        }

        // 2. Even
        left = i;
        right = i + 1;
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            int str_len = right - left + 1;
            if (str_len > max_len) {
                result = s.substr(left, str_len);
                max_len = str_len;
            }
            --left;
            ++right;
        }
    }

    return result;
}

int main() {
    return 0;
}
```

# Maximum Subarray

```cpp
#include <vector>
#include <climits>
#include <iostream>

int maxSubArray(std::vector<int>& nums) {
    int max = INT_MIN;
    int sum = 0;

    for (int num : nums) {
        sum += num;
        max = std::max(max, sum);

        if (sum < 0) sum = 0;
    }

    return max;
}

auto main() -> int {
    std::vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> nums2 = {5,4,-1,7,8};

    std::cout << maxSubArray(nums1) << std::endl;
    std::cout << maxSubArray(nums2) << std::endl;
}
```

# Spiral Matrix

```cpp
#include <vector>
#include <iostream>

auto spiralOrder(std::vector<std::vector<int>>& matrix) -> std::vector<int> {
    auto result = std::vector<int>{};

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    int i = 0;
    int j = 0;
    int direction = 0;
    // 0: right
    // 1: down
    // 2: left
    // 3: top

    while (left <= right and top <= bottom) {
        result.push_back(matrix[i][j]);

        if (direction == 0) {
            if (j == right) {
                ++i;
                direction = 1;
                ++top;
            } else {
                ++j;
            }
        } else if (direction == 1) {
            if (i == bottom) {
                --j;
                direction = 2;
                --right;
            } else {
                ++i;
            }
        } else if (direction == 2) {
            if (j == left) {
                --i;
                direction = 3;
                --bottom;
            } else {
                --j;
            }
        } else {
            if (i == top) {
                ++j;
                direction = 0;
                ++left;
            } else {
                --i;
            }
        }
    }

    return result;
}

auto main() -> int {
    std::vector<int> row1 = {1,2,3,4};
    std::vector<int> row2 = {5,6,7,8};
    std::vector<int> row3 = {9,10,11,12};
    std::vector<std::vector<int>> matrix = {};
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    
    std::vector<int> order = spiralOrder(matrix);
    for (int num : order) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
```

# Diameter Of Binary Tree

```cpp
#include <iostream>
#include <algorithm>
#include "TreeNode.h"

// 
//     1
//    / \
//   2   3
//  / \
// 4   5

// dfs function returns the maximum height
int dfs(TreeNode* root, int& result) {
    if (not root) return 0;

    int left = dfs(root->left, result);
    int right = dfs(root->right, result);

    result = std::max(result, left + right);
    
    return 1 + std::max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int result = 0;
    dfs(root, result);
    return result;
}

int main() {

}
```

# Jump Game

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

bool canJump(std::vector<int>& nums) {
    // A naive solution could be initialising a vector indicating something is reachable or not
    // But all we need is the farthest variable

    int farthest = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > farthest) return false;
        farthest = std::max(farthest, i + nums[i]);
    }

    return true;
}

auto main() -> int {
    auto nums1 = std::vector<int>{2,3,1,1,4};           // true
    auto nums2 = std::vector<int>{3,2,1,0,4};           // false
    auto nums3 = std::vector<int>{8,2,4,4,4,9,5,2,5,8}; // 

    std::cout << std::boolalpha << canJump(nums1) << std::endl;
    std::cout << std::boolalpha << canJump(nums2) << std::endl;
    std::cout << std::boolalpha << canJump(nums3) << std::endl;
}
```

# Merge Intervals

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

auto merge(std::vector<std::vector<int>>& intervals) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;

    if (intervals.empty()) return result;

    std::sort(intervals.begin(), intervals.end());

    bool first = true;
    std::vector<int> curr = intervals[0];

    for (std::vector<int> interval : intervals) {
        // Skipping first interval
        if (first) {
            first = false;
            continue;
        }

        // Overlapping case
        if (curr[0] < interval[0] and curr[1] > interval[1]) continue;

        if (curr[1] >= interval[0]) {
            // If curr and interval are mergeable
            curr[1] = interval[1];
        } else {
            // If curr and interval are not mergeable
            result.push_back(curr);
            curr = interval;
        }
    }

    result.push_back(curr);
    return result;
}

auto print_result(std::vector<std::vector<int>> intervals) {
    for (std::vector<int> interval : intervals) {
        std::cout << interval[0] << " " << interval[1] << std::endl;
    }
}

auto main() -> int {
    std::vector<std::vector<int>> intervals1 = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    auto merged1 = merge(intervals1);
    print_result(merged1);
    std::cout << std::endl;

    std::vector<std::vector<int>> intervals2 = {
        {1,4},
        {4,5}
    };
    auto merged2 = merge(intervals2);
    print_result(merged2);
    std::cout << std::endl;
}
```

# Subarray Sum Equals K

```cpp
#include <vector>
#include <numeric>
#include <iostream>

// Works if everything is positive
int subarraySum_initial(std::vector<int>& nums, int k) {
    // k = 6
    // 3, 2, 1, 5, 1, 4, 1
    int count = 0;
    int left = 0, right = 0;
    int curr_sum = nums[0];

    while (left != nums.size() and right != nums.size()) {
        std::cout << "For left = " << left << " and right = " << right << ", curr_sum is " << curr_sum << std::endl;

        // Check if current value = k
        if (curr_sum == k) ++count;

        // Case 0: right = nums.size() - 1
        // ++left, curr_sum -= nums[left]
        if (right == nums.size() - 1) {
            curr_sum -= nums[left];
            ++left;
        }

        // Case 1: curr_sum < k
        // ++right, curr_sum += nums[right]
        else if (curr_sum < k) {
            ++right;
            curr_sum += nums[right];
        }

        // Case 2: curr_sum = k
        // ++left, ++right, curr_sum += nums[right], curr_sum -= nums[left]
        else if (curr_sum == k) {
            ++right;
            curr_sum += nums[right];
            curr_sum -= nums[left];
            ++left;
        }

        // Case 3: curr_sum > k
        // ++left, curr_sum -= nums[left]
        else {
            curr_sum -= nums[left];
            ++left;
        }
    }

    return count;
}

// Answer
int subarraySum(std::vector<int>& nums, int k) {
    
}

auto main() -> int {
    std::vector<int> nums;
    
    nums = {1,1,1};
    std::cout << subarraySum(nums, 2) << std::endl;

    nums = {1,2,3};
    std::cout << subarraySum(nums, 3) << std::endl;

    nums = {1,8,1,5,3,2,2,2,3,5,1};
    std::cout << subarraySum(nums, 9) << std::endl;

    //      0 1 2 3 4 5 6
    nums = {3,2,1,5,1,4,1};
    std::cout << subarraySum(nums, 6) << std::endl;
}
```

# Permutation In String

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

bool checkInclusion(std::string s1, std::string s2) {
    std::unordered_map<char, int> s1_count;
    std::unordered_map<char, int> s2_count;
    int s1_length = s1.size();
    int s2_length = s2.size();

    for (int i = 0; i < s1_length; ++i) {
        ++s1_count[s1[i]];
        ++s2_count[s2[i]];
    }

    for (int i = 0; i <= s2_length - s1_length; ++i) {
        if (s1_count == s2_count) return true;

        if (i + s1_length < s2_length) {
            if (--s2_count[s2[i]] == 0) {
                s2_count.erase(s2[i]);
            }
            ++s2_count[s2[i + s1_length]];
        }
    }

    return false;
}

int main() {
    std::cout << std::boolalpha << checkInclusion("ab", "eidbaooo") << std::endl;
    std::cout << std::boolalpha << checkInclusion("ab", "eidboaoo") << std::endl;
}
```

# Subtree Of Another Tree

```cpp
#include <iostream>
#include "TreeNode.h"

// 
//       3
//      / \
//     4   5        4
//    / \          / \
//   1   2        1   2
//  / \   \      / |  | \
// X   X   0    X  X  X  X
//        / \
//       X   X
// 
// root and not subRoot
//     1      1
//    / \    / \
//   1   X  X   X
//  / \
// X   X
// Conditions
// - Start comparing when root's val is equal to subroot
// - Traverse through logic of subRoot
bool compare(TreeNode* root, TreeNode* subRoot) {
    // Same logic of returning true for nullptr
    if (not root and not subRoot) return true;

    // Handling error cases where root and subRoot are different
    if (not root and subRoot) return false;
    if (root and not subRoot) return false;
    if (root->val != subRoot->val) return false;

    return compare(root->left, subRoot->left) and compare(root->right, subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (not subRoot) return true;
    if (not root) return false;

    // Shouldn't be something like
    // return compare(root, subRoot)
    // because if this returns false, we still want to compare for root->left and root->right
    if (compare(root, subRoot)) return true;
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    // Main tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Subtree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    if (isSubtree(root, subRoot)) {
        std::cout << "subRoot is a subtree of root!" << std::endl;
    } else {
        std::cout << "subRoot is NOT a subtree of root." << std::endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    delete subRoot->left;
    delete subRoot->right;
    delete subRoot;

    return 0;
}
```

# Can Place Flowers

```cpp
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
```

# Unique Paths

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 1));

    if (m == 1 or n == 1) {
        return 1;
    }

    if (m == 2 or n == 2) {
        return std::max(m, n);
    }

    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
    }

    return matrix[m - 1][n - 1];
}

auto main() -> int {
    std::cout << uniquePaths(3, 7) << std::endl;
    std::cout << uniquePaths(2, 3) << std::endl;
}
```

# Design Circular Queue

```cpp
#include <iostream>
#include <vector>

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        
    }
    
    bool deQueue() {
        
    }
    
    int Front() {
        if (count == 0) return -1;
        return queue[front];
    }
    
    int Rear() {
        if (count == 0) return -1;
        return queue[back];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
private:
    // capacity and number of elements
    int capacity;
    int count = 0;

    // indexes for front and back
    int front = 0;
    int back = 0;

    // queue structure
    std::vector<int> queue;
};

int main() {
    return 0;
}```

# Minimum Path Sum

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

int minPathSum(std::vector<std::vector<int>>& grid) {
    int cols = grid[0].size();
    int rows = grid.size(); 

    std::vector<std::vector<int>> sum(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 and j == 0) {
                sum[i][j] = grid[i][j];
            } else if (i == 0) {
                sum[i][j] = grid[i][j] + sum[i][j - 1];
            } else if (j == 0) {
                sum[i][j] = grid[i][j] + sum[i - 1][j];
            } else {
                sum[i][j] = grid[i][j] + std::min(sum[i][j - 1], sum[i - 1][j]);
            }
        }
    }

    return sum[rows - 1][cols - 1];
}

auto main() -> int {
    std::vector<std::vector<int>> grid1 = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    std::cout << minPathSum(grid1) << std::endl;

    std::vector<std::vector<int>> grid2 = {
        {1,2,3},
        {4,5,6}
    };

    std::cout << minPathSum(grid2) << std::endl;
}
```

# Maximum Average Subarray 1

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

double findMaxAverage(std::vector<int>& nums, int k) {
    // Make initial sum
    // Iterate using while loop
    // Do one plus and minus each for efficiency

    int curr_sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
    int max = curr_sum;

    for (int i = k; i < nums.size(); ++i) {
        curr_sum -= nums[i - k];
        curr_sum += nums[i];

        max = std::max(max, curr_sum);
    }

    double result = static_cast<double>(max) / k;
    return result;
}

int main() {
    std::vector<int> nums1 = {1,12,-5,-6,50,3};
    std::cout << findMaxAverage(nums1, 4) << std::endl;

    std::vector<int> nums2 = {5};
    std::cout << findMaxAverage(nums2, 1) << std::endl;
}
```

# Palindromic Substrings

```cpp
#include <iostream>
#include <string>
#include <vector>

int countSubstrings(std::string s) {
    // 1. Odd palindromes
    // 2. Even palindromes

    // DP
    // Problem   : dp[i][j] represents if substring i~j is a palindrome or not
    // Initial   : dp[i][i] = true, dp[i][i + 1] = true IF s[i] == s[i + 1]
    // Recurrence: if dp[i][j] == true AND s[i - 1] == s[j + 1], dp[i - 1][j + 1] = true (aligning to size)

    // e.g. dp[2][2] = true, s[1] == s[3], dp[1][3] = true

    // *****
    //  ****
    //   ***
    //    **
    //     *

    int size = s.size();
    int count = 0;

    // 1. For loop for odd size
    for (int i = 0; i < size; ++i) {
        // must be i-j >= 0, i+j < size, s[i-j] == s[i+j]
        int j = 0;
        while (i - j >= 0 and i + j < size and s[i - j] == s[i + j]) {
            ++j;
            ++count;
        }
    }

    // 2. For loop for even size
    for (int i = 0; i < size - 1; ++i) {
        int j = 0;
        while (i - j >= 0 and i + 1 + j < size and s[i - j] == s[i + 1 + j]) {
            ++j;
            ++count;
        }
    }

    return count;
}

int main() {
    std::cout << countSubstrings("abc") << std::endl;   // 3
    std::cout << countSubstrings("aaa") << std::endl;   // 6
}
```

# Dota Senate

```cpp
#include <iostream>
#include <string>
#include <queue>

auto predictPartyVictory(std::string senate) -> std::string {
    std::queue<int> radiants;
    std::queue<int> dires;

    for (int i = 0; i < senate.size(); ++i) {
        if (senate[i] == 'R') radiants.push(i);
        else dires.push(i);
    }

    int offset = senate.size();

    // std::cout << radiants.size() << ", " << dires.size() << std::endl;

    while ((not radiants.empty()) and (not dires.empty())) {
        int curr_radiant = radiants.front();
        int curr_dire = dires.front();

        // std::cout << curr_radiant << ", " << curr_dire << std::endl;

        radiants.pop();
        dires.pop();

        if (curr_radiant < curr_dire) {
            radiants.push(offset);
        } else {
            dires.push(offset);
        }
        ++offset;
    }

    return radiants.empty() ? "Dires" : "Radiants";
}

int main() {
    std::cout << predictPartyVictory("RRDDD") << std::endl;
    std::cout << predictPartyVictory("RD") << std::endl;
    std::cout << predictPartyVictory("RDD") << std::endl;
    std::cout << predictPartyVictory("RRR") << std::endl;
}
```

# Valid Parentheses String

```cpp
#include <iostream>
#include <stack>
#include <string>

bool checkValidString(std::string s) {
    std::stack<int> left, star;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            left.push(i);
        } else if (s[i] == '*') {
            star.push(i);
        } else {
            if (left.empty() and star.empty()) return false;
            
            if (not left.empty()) {
                left.pop();
            } else {
                star.pop();
            }
        }
    }
    
    while (not left.empty() and not star.empty()) {
        if (left.top() > star.top()) return false;
        left.pop();
        star.pop();
    }

    return left.empty();
}

int main() {

}
```

# Valid Palindrome Ii

```cpp
#include <iostream>
#include <string>

bool isPalindrome(const std::string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

bool validPalindrome(std::string s) {
    int left = 0;
    int right = s.size() - 1;
    int one_ignored = false;

    // Main loop starts here
    while (left <= right) {
        std::cout << left << ": " << s[left] << ", " << right << ": " << s[right] << std::endl;

        // Characters are different
        if (s[left] != s[right]) {
            // Check both left and right
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        --right;
        ++left;
    }

    return true;
}

int main() {
    // std::cout << std::boolalpha << validPalindrome("aba") << std::endl;
    // std::cout << std::boolalpha << validPalindrome("abca") << std::endl;
    // std::cout << std::boolalpha << validPalindrome("abc") << std::endl;
    std::cout << std::boolalpha << validPalindrome("eceec") << std::endl;
}
```

# Max Area Of Island

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// void dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, int i, int j, int& curr_area, int horizontal, int vertical) {
//     std::vector<std::pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//     visited[i][j] = true;
//     ++curr_area;

//     for (const auto& direction : directions) {
//         int x = i + direction.first;
//         int y = j + direction.second;

//         // For the DFS to be valid - 
//         // 0. x and y should be within bounaries
//         // 1. Next grid must be 1
//         // 2. Next grid must not be visited

//         if (x >= 0 and x < vertical and y >= 0 and y < horizontal and grid[x][y] == 1 and visited[x][y] == false) {
//             dfs(grid, visited, x, y, curr_area, horizontal, vertical);
//         }
//     }
    
//     return;
// }

// int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
//     std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
//     int max_area = 0;

//     for (int i = 0; i < grid.size(); ++i) {
//         for (int j = 0; j < grid[0].size(); ++j) {
//             if (not visited[i][j] and grid[i][j] == 1) {
//                 int curr_area = 0;
//                 dfs(grid, visited, i, j, curr_area, grid[0].size(), grid.size());
//                 max_area = std::max(max_area, curr_area);
//             }
//         }
//     }

//     return max_area;
// }

int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
    // Check boundaries and whether the cell is water (or already visited)
    if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == 0) return 0;
    
    // Mark current cell as visited by setting it to 0
    grid[i][j] = 0;
    
    // Recursively visit all four directions and add their area
    return 1 + dfs(grid, i - 1, j) 
             + dfs(grid, i + 1, j) 
             + dfs(grid, i, j - 1) 
             + dfs(grid, i, j + 1);
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int max_area = 0;
    
    // Loop over every cell in the grid
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            // If the cell is land, calculate the island's area
            if (grid[i][j] == 1) {
                int curr_area = dfs(grid, i, j);
                max_area = std::max(max_area, curr_area);
                
                // std::cout << "Island starting at (" << i << ", " << j << ") has area: " << curr_area << std::endl;
            }
        }
    }
    
    return max_area;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    std::cout << maxAreaOfIsland(grid) << std::endl;
}
```

# Climbing Stairs

```cpp
#include <iostream>
#include <vector>

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    std::vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n-1];
}

auto main() -> int {
    std::cout << climbStairs(3) << std::endl;
    std::cout << climbStairs(4) << std::endl;
    std::cout << climbStairs(5) << std::endl;
}```

# Kth Largest Element In Stream

```cpp
#include <iostream>
#include <vector>
#include <queue>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) {
        size = k;
        
        // Push all the numbers in scores, then pop everything until size is k.
        for (int num : nums) {
            scores.push(num);
        }

        while (scores.size() > k) {
            scores.pop();
        }
    }
    
    int add(int val) {
        if (scores.size() >= size) {
            scores.push(val);
            scores.pop();
            return scores.top();
        } else {
            scores.push(val);
            return scores.top();
        }
    }

    void print() {
        auto scores_copy = scores;
        while (not scores_copy.empty()) {
            std::cout << scores_copy.top() << " ";
            scores_copy.pop();
        }
        std::cout << std::endl;
    }
private:
    int size;
    std::priority_queue<int, std::vector<int>, std::greater<int>> scores;
};

int main() {
    std::vector<int> nums = {};
    KthLargest* obj = new KthLargest(1, nums);

    std::cout << obj->add(-3) << std::endl;
    std::cout << obj->add(-2) << std::endl;
    std::cout << obj->add(-4) << std::endl;
    std::cout << obj->add(0) << std::endl;
    std::cout << obj->add(4) << std::endl;
}
```

# Binary Search

```cpp
#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target < nums[mid]) {
            right = mid - 1;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums = {-1,0,3,5,9,12};
    std::cout << search(nums, 9) << std::endl;
    std::cout << search(nums, 2) << std::endl;
}
```

# Edit Distance

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int minDistance(std::string word1, std::string word2) {
    int height = word1.size() + 1;
    int width = word2.size() + 1;
    
    std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));
    
    for (int i = 0; i < width; ++i) {
        dp[0][i] = i;
    }

    for (int i = 0; i < height; ++i) {
        dp[i][0] = i;
    }

    for (int i = 1; i < height; ++i) {      // rows
        for (int j = 1; j < width; ++j) {   // columns
            // Same
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            
            // Different
            else {
                dp[i][j] = std::min({
                    dp[i - 1][j - 1] + 1,   // Replace
                    dp[i - 1][j] + 1,       // Insert
                    dp[i][j - 1] + 1        // Delete
                });
            }
        }
    }

    return dp[height - 1][width - 1];
}

auto main() -> int {
    std::cout << minDistance("horse", "ros") << std::endl;
    std::cout << minDistance("intention", "execution") << std::endl;
}

/**
 * Brainstorming
 * 
 * Base cases: just increment by 1
 * Recurrence:
 * 
 * e.g. "horse" -> "ros"
 * 
 * Insert, Delete, Change, Do nothing
 * 
 * h -> r: 1 (change)
 * h -> ro: 2 (change + insert)
 * h -> ros: 3 (change + insert + insert)
 * 
 * ho -> r: 2 (change + delete)
 * ho -> ro: 1 (change)
 * ho -> ros: 2 (change + insert)
 * 
 *   . r o s
 * . 0 1 2 3
 * h 1 1 2 3
 * o 2 2 1 ?
 * 
 * h -> ros: 3 operations | ho -> ros: 4 operations
 * h -> ro : 2 operations | ho -> ros: 
 * ho -> ro: 1 operation  | ho -> ros: 2 operations
 */
```

# Find Pivot Index

```cpp
#include <vector>
#include <iostream>
#include <numeric>

int pivotIndex(std::vector<int>& nums) {
    // Loop through nums, keep track of left_sum = 0 & right_sum = std::accumulate()
    
    int left_sum = 0;
    int right_sum = std::accumulate(nums.begin(), nums.end(), 0) - nums[0];

    for (int i = 0; i < nums.size(); ++i) {
        // std::cout << i << ": " << left_sum << ", " << right_sum << std::endl;

        if (left_sum == right_sum) return i;

        left_sum += nums[i];
        
        if (i + 1 == nums.size()) break;
        right_sum -= nums[i + 1];
    }

    return -1;
}

int main() {
    std::vector<int> nums1 = {1,7,3,6,5,6};
    std::cout << pivotIndex(nums1) << std::endl;

    std::vector<int> nums2 = {1,2,3};
    std::cout << pivotIndex(nums2) << std::endl;

    std::vector<int> nums3 = {2,1,-1};
    std::cout << pivotIndex(nums3) << std::endl;

    std::vector<int> nums4 = {-1,-1,-1,-1,-1,0};
    std::cout << pivotIndex(nums4) << std::endl;
}
```

# Set Matrix Zeroes

```cpp
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>

void change_zeroes(std::vector<std::vector<int>>& matrix, int i, int j) {
    // horizontal
    for (int n = 0; n < matrix[0].size(); ++n) {
        matrix[i][n] = 0;
    }

    // vertical
    for (int n = 0; n < matrix.size(); ++n) {
        matrix[n][j] = 0;
    }
}

void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::vector<std::pair<int, int>> coordinates;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == 0) {
                coordinates.push_back(std::make_pair(i, j));
            }
        }
    }

    for (std::pair<int, int> coordinate : coordinates) {
        change_zeroes(matrix, coordinate.first, coordinate.second);
    }
}

auto print_matrix(std::vector<std::vector<int>>& matrix) {
    for (std::vector<int> line : matrix) {
        for (int num : line) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    std::vector<std::vector<int>> matrix1 = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    setZeroes(matrix1);
    print_matrix(matrix1);
    std::cout << std::endl;

    std::vector<std::vector<int>> matrix2 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes(matrix2);
    print_matrix(matrix2);
}
```

# Asteroid Collision

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

auto asteroidCollision(std::vector<int>& asteroids) -> std::vector<int> {
    if (asteroids.empty()) return asteroids;

    std::stack<int> stack;
    stack.push(asteroids[0]);

    for (int i = 1; i < asteroids.size(); ++i) {
        int curr = asteroids[i];

        if (stack.empty()) {
            stack.push(curr);
            continue;
        }

        int top = stack.top();

        if ((top < 0 and curr < 0) or (top > 0 and curr > 0) or (top < 0 and curr > 0)) {
            stack.push(curr);
        } else {
            bool collided = false;
            while (not stack.empty() and stack.top() > 0 and curr < 0) {
                int absTop = std::abs(stack.top());
                int absCurr = std::abs(curr);

                if (absTop == absCurr) {
                    stack.pop();
                    collided = true;
                    break;
                } else if (absTop < absCurr) {
                    stack.pop();
                } else {
                    collided = true;
                    break;
                }
            }
            if (not collided) {
                stack.push(curr);
            }
        }
    }

    std::vector<int> result;
    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void print_result(std::vector<int>& result) {
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> asteroids1 = {5,10,-5};
    std::vector<int> asteroids2 = {8,-8};
    std::vector<int> asteroids3 = {10,2,-5};
    std::vector<int> asteroids4 = {-2, -1, 1, 2};

    auto result1 = asteroidCollision(asteroids1);
    auto result2 = asteroidCollision(asteroids2);
    auto result3 = asteroidCollision(asteroids3);
    auto result4 = asteroidCollision(asteroids4);

    print_result(result1);
    print_result(result2);
    print_result(result3);
    print_result(result4);

    return 0;
}
```

# Daily Temperatures

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <utility>

auto dailyTemperatures(std::vector<int>& temperatures) -> std::vector<int> {
    std::stack<std::pair<int, int>> days;

    if (temperatures.size() == 1) return {0};

    // Stack of { temperature, index }
    // 
    // 73,74,75,71,69,72,76,73
    //  1, 1, 4, 2, 1, 1, 0, 0
    // 
    // 1. Push {73, 1}
    // 2. while (days.top() < temperatures[i]) pop
    // 3. value should be (i - curr.second)

    std::vector<int> result(temperatures.size(), 0);
    days.push(std::make_pair(temperatures[0], 0));

    for (int i = 1; i < temperatures.size(); ++i) {
        // Keep popping
        while (not days.empty() and days.top().first < temperatures[i]) {
            auto curr = days.top();
            days.pop();
            result[curr.second] = i - curr.second;
        }

        days.push(std::make_pair(temperatures[i], i));
    }

    return result;
}

void print_result(const std::vector<int>& result) {
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> temperatures1 = {73,74,75,71,69,72,76,73};
    std::vector<int> temperatures2 = {30,40,50,60};
    std::vector<int> temperatures3 = {30,60,90};

    print_result(dailyTemperatures(temperatures1));
    print_result(dailyTemperatures(temperatures2));
    print_result(dailyTemperatures(temperatures3));
}
```

# Search Matrix

```cpp
#include <vector>
#include <iostream>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int horizontal = matrix[0].size();
    int vertical = matrix.size();
    
    int left = 0;
    int right = horizontal * vertical - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int m = mid / horizontal;
        int n = mid % horizontal;

        int val = matrix[m][n];

        // std::cout << "left: " << left << ", right: " << right << ", mid: " << mid << " m: " << m << ", n: " << n << ", val: " << val << std::endl;

        if (val == target) {
            return true;
        } else if (val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

auto main() -> int {
    std::vector<std::vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    std::cout << std::boolalpha << searchMatrix(matrix, 3) << std::endl;
    std::cout << std::boolalpha << searchMatrix(matrix, 13) << std::endl;
}
```

# Delete And Earn

```cpp
#include <iostream>
#include <vector>

int deleteAndEarn(std::vector<int>& nums) {
    int max_element = *std::max_element(nums.begin(), nums.end());

    std::vector<int> points(max_element + 1, 0);

    for (int num : nums) {
        points[num] += num;
    }

    // P.S. In {2,2,3,3,3,4}, picking '3' means you can pick all 3 instances of 3
    // Not much different to the House Robber problem

    // DP
    // Definition: dp[i] = max points you can earn when you pick
    // Base Case : dp[0] = 0, dp[1] = max(points[0], points[1]) [ no dp[i-2] to pick ]
    // Recurrence: dp[i] = max(dp[i-1], dp[i-2] + points[i])

    std::vector<int> dp(max_element + 1, 0);
    for (int i = 0; i <= max_element; ++i) {
        if (i == 0) {
            dp[i] = points[0];
        } else if (i == 1) {
            dp[i] = std::max(points[0], points[1]);
        } else {
            dp[i] = std::max(dp[i-1], dp[i-2] + points[i]);
        }
    }

    return std::max(dp[max_element], dp[max_element-1]);
}

int main() {
    
}
```

# Min Cost Climbing Stairs

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int minCostClimbingStairs(std::vector<int>& cost) {
    int size = cost.size();
    if (size == 2) return std::min(cost[0], cost[1]);

    // 0,0   2,5,5,9  ,10,11,12 ,12
    // 2,100,3,4,5,100,1 ,1 ,100,1

    // dp[2] = 2
    // dp[3] = 2 + 3
    // dp[4] = 
    // dp[5] = 
    // dp[6] = 

    std::vector<int> dp(size + 1, 0);
    dp[0] = 0, dp[1] = 0;

    for (int i = 2; i < size + 1; ++i) {
        if (cost[i-2] + dp[i-2] > cost[i-1] + dp[i-1]) {
            dp[i] = cost[i-1] + dp[i-1];
        } else {
            dp[i] = cost[i-2] + dp[i-2];
        }
    }

    return dp[size];
}

int main() {
    std::vector<int> cost1 = {10,15,20};
    std::vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    std::cout << minCostClimbingStairs(cost1) << std::endl;
    std::cout << minCostClimbingStairs(cost2) << std::endl;
}
```

# Sort Colours

```cpp
#include <vector>
#include <iostream>

void sortColors(std::vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

auto main() -> int {
    std::vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
```

# Minimum Window Substring

```cpp
#include <string>
#include <iostream>
#include <unordered_map>
#include <climits>

auto minWindow(std::string s, std::string t) -> std::string {
    int left = 0;
    int right = 0;
    int max = s.size() - 1;
    std::string result = "";
    int max_size = INT_MAX;

    std::unordered_map<char, int> frequency;

    while (left != max && right != max) {
        // Check if all characters exist
        std::unordered_map<char, int> curr_frequency = frequency;

        bool chars_exist = true;
        for (char c : t) {
            if (curr_frequency[c] <= 0) {
                chars_exist = false;
            }
            curr_frequency[c]--;
        }

        if (chars_exist) {
            std::string substring = s.substr(left, right - left + 1);
            if (substring.length() < max_size) {
                result = substring;
                max_size = substring.length();
            }

            frequency[t[left]]--;
            ++left;
        } else {
            frequency[t[right]]++;
            ++right;
        }
    }

    return result;
}

auto main() -> int {
    std::cout << minWindow("ADOBECODEBANC", "ABC") << std::endl;
    std::cout << minWindow("a", "a") << std::endl;
    std::cout << minWindow("a", "aa") << std::endl;
    
}
```

# Subsets

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void backtrack(std::vector<std::vector<int>>& result, int index, std::vector<int>& curr, std::vector<int>& nums) {
    result.push_back(curr);

    for (int i = index; i < nums.size(); ++i) {
        curr.push_back(nums[i]);
        backtrack(result, i + 1, curr, nums);
        curr.pop_back();
    }
}

auto subsets(std::vector<int>& nums) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;
    std::vector<int> curr;
    backtrack(result, 0, curr, nums);
    
    return result;
}

auto print_result(std::vector<std::vector<int>>& result) {
    for (auto vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    std::vector<int> nums = {1,2,3};
    std::vector<std::vector<int>> result = subsets(nums);

    print_result(result);
}
```

# Word Search

```cpp
#include <vector>
#include <string>
#include <iostream>

bool path_find(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, int x, int y, int curr, const std::string& word) {
    if (curr == word.size()) {
        return true;
    }

    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] || board[x][y] != word[curr]) {
        return false;
    }

    visited[x][y] = true;

    bool found = path_find(board, visited, x - 1, y, curr + 1, word) ||  // up
                 path_find(board, visited, x + 1, y, curr + 1, word) ||  // down
                 path_find(board, visited, x, y - 1, curr + 1, word) ||  // left
                 path_find(board, visited, x, y + 1, curr + 1, word);    // right

    // If found is false, return it back
    if (not found) {
        visited[x][y] = false;
    }

    return found;
}

bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
    int x_size = board.size();
    int y_size = board[0].size();

    std::vector<std::vector<bool>> visited(x_size, std::vector<bool>(y_size, false));

    for (int x = 0; x < x_size; ++x) {
        for (int y = 0; y < y_size; ++y) {
            if (board[x][y] == word[0] and path_find(board, visited, x, y, 0, word)) {
                return true;
            }
        }
    }

    return false;
}

auto main() -> int {
    auto board = std::vector<std::vector<char>>{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::cout << std::boolalpha << exist(board, "ABCCED") << std::endl;
    std::cout << std::boolalpha << exist(board, "SEE") << std::endl;
    std::cout << std::boolalpha << exist(board, "ABCB") << std::endl;
}
```

# Hand Of Straights

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool isNStraightHand(std::vector<int> hand, int groupSize) {
    // 1,2,3,6,2,3,4,7,8
    // 1,2,2,3,3,4,6,7,8

    // 1: 1 | 0 | 0 | 0
    // 2: 2 | 1 | 0 | 0
    // 3: 2 | 1 | 0 | 0
    // 4: 1 | 1 | 0 | 0
    // 6: 1 | 1 | 1 | 0
    // 7: 1 | 1 | 1 | 0
    // 8: 1 | 1 | 1 | 0

    // 1,2,3,4,5,6,7,9
    // 1: 1 | 0 | 
    // 2: 1 | 0 | 
    // 3: 1 | 0 | 
    // 4: 1 | 0 | 
    // 5: 1 | 1 | 
    // 6: 1 | 1 | 
    // 7: 1 | 1 | 
    // 9: 1 | 1 | 

    // 1: 1 | 0 | 0 | 0
    // 2: 2 | 1 | 0 | 0
    // 3: 2 | 1 | 0 | 0
    // 4: 1 | 1 | 0 | 0
    // 6: 1 | 1 | 1 | 0
    // 7: 1 | 1 | 1 | 0
    // 8: 1 | 1 | 1 | 0

    // 1. Get the count
    // 2. Each round, delete the count of numbers
    // 3. If failed to delete, return false.
    //    Otherwise (proceed up to end of group)

    int size = hand.size();
    if (size % groupSize != 0) return false;

    // Get count
    std::unordered_map<int, int> count;
    for (const int& num : hand) {
        ++count[num];
    }

    // Loop through numbers
    std::sort(hand.begin(), hand.end());
    for (const int& num : hand) {
        if (count[num] <= 0) continue;

        // Start loop
        for (int i = num; i < num + groupSize; ++i) {
            if (count[i] <= 0) return false;
            --count[i];
        }
    }

    return true;
}

int main() {
    std::cout << std::boolalpha << isNStraightHand({3,2,1,2,3,4,3,4,5,9,10,11}, 3) << std::endl;
    std::cout << std::boolalpha << isNStraightHand({1,2,3,4,5}, 4) << std::endl;
    std::cout << std::boolalpha << isNStraightHand({1,2,3,4,5,6,8,9}, 4) << std::endl;
    std::cout << std::boolalpha << isNStraightHand({1,2,3,4,5,6,8,9}, 2) << std::endl;
}
```

# Koko Eating Bananas

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int minEatingSpeed(std::vector<int>& piles, int h) {
    int min = 1, max = *max_element(piles.begin(), piles.end());
    int ans = max;

    while (min <= max) {
        int mid = (min + max) / 2;
        int count = 0;
        for (int i : piles) {
            count += (i + mid - 1) / mid;
        }
        if (count <= h) {
            ans = mid;
            max = mid - 1;
        } else
            min = mid + 1;
    }
    return ans;
}

int main() {
    std::vector<int> piles1 = {3,6,7,11};
    std::vector<int> piles2 = {30,11,23,4,20};
    std::vector<int> piles3 = {30,11,23,4,20};

    std::cout << minEatingSpeed(piles1, 8) << std::endl;    // 4
    std::cout << minEatingSpeed(piles2, 5) << std::endl;    // 30
    std::cout << minEatingSpeed(piles3, 6) << std::endl;    // 23
}
```

# Subsets Ii

```cpp
#include <iostream>
#include <vector>

void backtrack(std::vector<std::vector<int>>& results, std::vector<int>& nums, std::vector<int> result, int start) {
    results.push_back(result);

    for (int i = start; i < nums.size(); ++i) {
        if (i > start and nums[i] == nums[i-1]) continue;

        if (result.size() < nums.size()) {
            result.push_back(nums[i]);
            backtrack(results, nums, result, i + 1);
            result.pop_back();
        }
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> results;
    backtrack(results, nums, {}, 0);
    return results;
}

int main() {

}
```

# Number Of Recent Calls

```cpp
#include <iostream>
#include <queue>

class RecentCounter {
 public:
    RecentCounter() {}
    
    int ping(int t) {
        pings.push(t);
        
        while (not pings.empty() and pings.front() < t - 3000) {
            pings.pop();
        }

        return pings.size();
    }
 private:
    std::queue<int> pings;
};

int main() {
    RecentCounter* counter = new RecentCounter();

    std::cout << counter->ping(1) << std::endl;
    std::cout << counter->ping(100) << std::endl;
    std::cout << counter->ping(3001) << std::endl;
    std::cout << counter->ping(3002) << std::endl;

    delete counter;
}
```

# K Closest Points To Origin

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

auto kClosest(std::vector<std::vector<int>> points, int k) -> std::vector<std::vector<int>> {
    std::priority_queue<std::pair<int, int>> maxHeap;

    for (int i = 0; i < points.size(); ++i) {
        maxHeap.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        if (maxHeap.size() > k) maxHeap.pop();
    }

    std::vector<std::vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
    }
    return result;
}

void print_result(std::vector<std::vector<int>> result) {
    for (auto vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    print_result(kClosest({{1, 3}, {2, -2}}, 1));
    print_result(kClosest({{3, 3}, {5, -1}, {-2, 4}}, 2));
}
```

# Validate Binary Search Tree

```cpp
#include <iostream>
#include <vector>
#include "TreeNode.h"

void dfs(std::vector<int>& values, TreeNode* node) {
    if (not node) return;

    dfs(values, node->left);
    values.push_back(node->val);
    dfs(values, node->right);
}

bool isValidBST(TreeNode* root) {
    std::vector<int> values;
    dfs(values, root);

    if (values.size() == 1) return true;

    for (int i = 1; i < values.size(); ++i) {
        if (values[i-1] >= values[i]) return false;
    }

    return true;
}

int main() {

}
```

# Time Based Key Value Store

```cpp
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

class TimeMap {
 public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        stores[key][timestamp] = value;
    }
    
    std::string get(std::string key, int timestamp) {
        // Returns an iterator to the first element with key > timestamp
        auto it = stores[key].upper_bound(timestamp);
        
        if (it == stores[key].begin()) {
            return "";
        } else {
            return prev(it)->second;
        }
    }
 private:
    std::unordered_map<std::string, std::map<int, std::string>> stores;
};

int main() {
    TimeMap* timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);
    std::cout << "answer: " << timeMap->get("foo", 1) << std::endl;
    std::cout << "answer: " << timeMap->get("foo", 3) << std::endl;
    timeMap->set("foo", "bar2", 4);
    std::cout << "answer: " << timeMap->get("foo", 4) << std::endl;
    std::cout << "answer: " << timeMap->get("foo", 5) << std::endl;
}
```

# Rotten Oranges

```cpp
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <unordered_set>

int orangesRotting(std::vector<std::vector<int>>& grid) {
    // 1. Start graph traversals from 2's

    // 2. Conduct BFS. BFS should be structure of {{x, y}, minute}

    // 3. Check for any 1's after graph traversal finished.
    // - 1 X: return 'max minute'
    // - 1 O: return -1

    std::queue<std::pair<std::pair<int, int>, int>> queue;

    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[0].size(); ++y) {
            if (grid[x][y] == 2) {
                queue.push({{x, y}, 0});
            }
        }
    }

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int max_minute = 0;

    while (not queue.empty()) {
        auto [coords, minute] = queue.front();
        auto [x, y] = coords;
        queue.pop();

        for (const auto& d : directions) {
            int new_x = x + d[0];
            int new_y = y + d[1];

            if (new_x >= 0 and new_y >= 0 and new_x < grid.size() and new_y < grid[0].size() and grid[new_x][new_y] == 1) {
                grid[new_x][new_y] = 2;
                int new_minute = minute + 1;
                
                queue.push({{new_x, new_y}, new_minute});
                if (max_minute < new_minute) max_minute = new_minute;
            }
        }
    }

    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[0].size(); ++y) {
            if (grid[x][y] == 1) {
                return -1;
            }
        }
    }

    return max_minute;
}

auto main() -> int {
    std::vector<std::vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    std::cout << orangesRotting(grid) << std::endl;

    grid = {{2,1,1},{0,1,1},{1,0,1}};
    std::cout << orangesRotting(grid) << std::endl;

    grid = {{0, 2}};
    std::cout << orangesRotting(grid) << std::endl;
}
```

