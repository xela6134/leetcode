#include <iostream>
#include "TreeNode.h"

TreeNode* find(TreeNode* root, int small, int large) {
    if (root == nullptr) return nullptr;

    if (small <= root->val and root->val <= large) {
        return root;
    } else if (root->val < small) {
        return find(root->right, small, large);
    } else {
        return find(root->left, small, large);
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < q->val) {
        return find(root, p->val, q->val);
    } else {
        return find(root, q->val, p->val);
    }
}

int main() {

}
