#include <iostream>
#include <algorithm>
#include "TreeNode.h"

// 
//     1
//    / \
//   2   3
//  / \
// 4   5

// dfs function returns the maximum height
int dfs(TreeNode* root, int& result) {
    if (not root) return 0;

    int left = dfs(root->left, result);
    int right = dfs(root->right, result);

    result = std::max(result, left + right);
    
    return 1 + std::max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int result = 0;
    dfs(root, result);
    return result;
}

int main() {

}
