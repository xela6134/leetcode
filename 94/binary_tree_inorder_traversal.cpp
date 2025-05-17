#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> nodes;
    TreeNode* curr = root;
    std::vector<int> result;

    while (not nodes.empty() or curr) {
        while (curr) {
            nodes.push(curr);
            curr = curr->left;
        }

        curr = nodes.top();
        nodes.pop();

        result.push_back(curr->val);
        // curr = nodes.top();
        curr = curr->right;
    }

    return result;
}

int main() {
    
}
