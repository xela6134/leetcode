#include <iostream>
#include "TreeNode.h"

//     1
//    / \
//   2   3
//  / \
// X   X
// 
//     1
//    / \
//   2   3
//  / \
// X   X

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (not p and not q) return true;

    if (p and q and p->val == q->val) {
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    } else {
        return false;
    }
}

int main() {

}
