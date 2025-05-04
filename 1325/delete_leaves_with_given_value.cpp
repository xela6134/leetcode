#include <iostream>
#include "TreeNode.h"

// We need post-order traversal for this
void deletion(TreeNode*& root, int target) {
    if (not root) return;

    deletion(root->left, target);
    deletion(root->right, target);

    // remove if turned into a target leaf
    if (not root->left and not root->right and root->val == target) {
        root = nullptr;
    }
}

TreeNode* removeLeafNodes(TreeNode* root, int target) {
    deletion(root, target);
    return root;
}

int main() {

}
