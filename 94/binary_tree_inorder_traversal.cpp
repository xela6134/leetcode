#include <iostream>
#include <vector>
#include "TreeNode.h"

void dfs(std::vector<int>& nodes, TreeNode* node) {
    if (not node) return;

    dfs(nodes, node->left);
    nodes.push_back(node->val);
    dfs(nodes, node->right);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> nodes;
    dfs(nodes, root);
    return nodes;
}

int main() {
    
}
