#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int dfs(struct TreeNode* node, int current) {
    if (node == NULL) {
        return 0;
    }

    current = current * 10 + node->val;

    // If it's a leaf node, return the number formed
    if (node->left == NULL && node->right == NULL) {
        return current;
    }

    // Recurse left and right
    return dfs(node->left, current) + dfs(node->right, current);
}

int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}
