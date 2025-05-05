#include <iostream>
#include <vector>
#include <string>
#include "TreeNode.h"

void dfs(TreeNode* node, std::vector<std::string>& result, std::string curr) {
    if (not node) return;

    // Leaf node, don't add ->
    if (not node->left and not node->right) {
        curr += std::to_string(node->val);
        result.push_back(curr);
    }

    // Not leaf node, add ->
    else {
        curr += std::to_string(node->val);
        curr += "->";
    }

    if (node->left) dfs(node->left, result, curr);
    if (node->right) dfs(node->right, result, curr);
}

std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> result;
    dfs(root, result, "");
    return result;
}

int main() {

}
