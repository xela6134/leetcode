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
