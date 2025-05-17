#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> stk;
    stk.push(root);

    // Postorder is Left -> Right -> Root
    // If we do Root -> Right -> Left, then reverse
    // We can get postorder traversal

    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();

        result.push_back(node->val); // Process root

        // Push left first, then right (so right is processed first)
        if (node->left) stk.push(node->left);
        if (node->right) stk.push(node->right);
    }

    // Reverse the result to get Left -> Right -> Root
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {

}
