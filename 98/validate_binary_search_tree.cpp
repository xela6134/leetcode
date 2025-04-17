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
