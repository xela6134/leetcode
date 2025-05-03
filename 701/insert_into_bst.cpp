#include <iostream>
#include "TreeNode.h"

void insert(TreeNode* node, int val, bool& found) {
    if (not node or found) return;
    
    // Left side
    if (node->val > val) {
        if (not node->left) {
            node->left = new TreeNode(val);
            found = true;
            return;
        }
        
        insert(node->left, val, found);
    }
    
    // Right side
    else {
        if (not node->right) {
            node->right = new TreeNode(val);
            found = true;
            return;
        }
        
        insert(node->right, val, found);
    }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    bool found = false;

    if (not root) {
        return new TreeNode(val);
    }

    insert(root, val, found);
    return root;
}

int main() {

}
