#include <iostream>
#include <algorithm>
#include "TreeNode.h"

int getHeight(TreeNode* root) {
    if (not root) return 0;

    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(TreeNode* root) {
    if (not root) return true;

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if (std::abs(right - left) > 1) return false;

    return isBalanced(root->left) and isBalanced(root->right);
}

int main() {
    
}
