/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int checkAVL(struct TreeNode* node, long min, long max) {

    if (node == NULL)
        return 0;

    // Check strict BST property
    if (node->val <= min || node->val >= max)
        return -1;

    int leftH = checkAVL(node->left, min, node->val);
    if (leftH == -1)
        return -1;

    int rightH = checkAVL(node->right, node->val, max);
    if (rightH == -1)
        return -1;

    // Check AVL balance without using abs()
    if (leftH - rightH > 1 || rightH - leftH > 1)
        return -1;

    // Return height
    if (leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

bool isAVL(struct TreeNode* root) {

    return checkAVL(root, LONG_MIN, LONG_MAX) != -1;
}

