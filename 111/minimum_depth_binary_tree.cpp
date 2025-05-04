#include <iostream>
#include <climits>
#include "TreeNode.h"

void dfs(TreeNode* node, int& result, int curr) {
    if (not node->left and not node->right) {
        result = std::min(result, curr);
        return;
    }

    if (node->left) dfs(node->left, result, curr + 1);
    if (node->right) dfs(node->right, result, curr + 1);
}

int minDepth(TreeNode* root) {
    if (not root) return 0;
    
    int result = INT_MAX;
    dfs(root, result, 1);
    return result;
}

int main() {

}
