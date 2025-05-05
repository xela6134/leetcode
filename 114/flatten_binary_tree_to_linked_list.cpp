#include <iostream>
#include "TreeNode.h"

TreeNode* prev = nullptr;

void flattening(TreeNode* curr) {
    if (not curr) return;
    
    // std::cout << "Working with " << curr->val << std::endl;

    TreeNode* left = curr->left;
    TreeNode* right = curr->right;

    if (not prev) {
        prev = curr;
    } else {
        prev->right = curr;
        prev->left = nullptr;
        prev = curr;
    }

    if (curr->left) flattening(left);
    // std::cout << "Lol" << std::endl;
    if (curr->right) flattening(right);
}

void flatten(TreeNode* root) {
    flattening(root);
}

int main() {

}
