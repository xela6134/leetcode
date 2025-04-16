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
