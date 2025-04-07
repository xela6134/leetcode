#include <iostream>
#include "TreeNode.h"

// 
//       3
//      / \
//     4   5        4
//    / \          / \
//   1   2        1   2
//  / \   \      / |  | \
// X   X   0    X  X  X  X
//        / \
//       X   X
// 
// root and not subRoot
//     1      1
//    / \    / \
//   1   X  X   X
//  / \
// X   X
// Conditions
// - Start comparing when root's val is equal to subroot
// - Traverse through logic of subRoot
bool compare(TreeNode* root, TreeNode* subRoot) {
    if (not root and not subRoot) return true;
    if (not root or not subRoot or root->val != subRoot->val) return false;

    return compare(root->left, subRoot->left) and compare(root->right, subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (not subRoot) return true;
    if (not root) return false;

    if (compare(root, subRoot)) return true;
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    // Main tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Subtree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    if (isSubtree(root, subRoot)) {
        std::cout << "subRoot is a subtree of root!" << std::endl;
    } else {
        std::cout << "subRoot is NOT a subtree of root." << std::endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    delete subRoot->left;
    delete subRoot->right;
    delete subRoot;

    return 0;
}
