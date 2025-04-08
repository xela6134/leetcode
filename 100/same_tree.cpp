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

// logic that nullptr's return true
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (not p and not q) return true;

    if (p and q and p->val == q->val) {
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    } else {
        // if p and not q, or
        //    not p and q,
        // this won't be a valid test case anyways
        return false;
    }
}

int main() {

}
