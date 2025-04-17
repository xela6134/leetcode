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
