#include <iostream>
#include <queue>
#include <algorithm>
#include "TreeNode.h"

TreeNode* invertTree(TreeNode* root) {
    if (not root) return nullptr;
    
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (not queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();

        std::swap(node->left, node->right);

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
    }

    return root;
}

int main() {

}
