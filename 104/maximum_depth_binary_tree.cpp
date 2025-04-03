#include <iostream>
#include <algorithm>
#include "TreeNode.h"

int maxDepth(TreeNode* root) {
    if (not root) return 0;

    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main() {

}
