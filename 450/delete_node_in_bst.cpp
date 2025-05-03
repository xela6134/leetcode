#include <iostream>
#include "TreeNode.h"

//     5
//    / \
//   3   8
//      /
//     6

//     6
//    / \
//   3   8
//      /
//     6   ← duplicate

//     6
//    / \
//   3   8

void deletion(TreeNode*& node, int key) {
    if (not node) return;

    if (node->val > key) {
        deletion(node->left, key);
    } else if (node->val < key) {
        deletion(node->right, key);
    } else {
        // Node found
        if (not node->left and not node->right) {
            node = nullptr;
        } else if (not node->left) {
            node = node->right;
        } else if (not node->right) {
            node = node->left;
        } else {
            // Replace with inorder successor (smallest in right subtree)
            TreeNode* succ = node->right;
            while (succ->left) {
                succ = succ->left;
            }
            node->val = succ->val;

            deletion(node->right, succ->val);
        }
    }
}

TreeNode* deleteNode(TreeNode* root, int key) {
    deletion(root, key);
    return root;
}

int main() {

}
