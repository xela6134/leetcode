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
