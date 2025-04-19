#include <iostream>
#include "TreeNode.h"

bool dfs(TreeNode* left, TreeNode* right) {
    if (not left and not right) return true;
    if ((left and not right) or (not left and right)) return false;
    if (left->val != right->val) return false;

    return dfs(left->left, right->right) and dfs(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return dfs(root->left, root->right);
}

int main() {

}
