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
