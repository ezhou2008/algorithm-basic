/*Minimum Depth of Binary Tree

Description

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.

Example
Given a binary tree as follow:

    1
    / \
    2   3
        / \
        4   5
The minimum depth is 2.*/


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;

        if (root->left && root->right) {
            return min( minDepth(root->left), minDepth(root->right) ) + 1;
        } else if (root->left) {
            return minDepth(root->left) + 1;
        } else {
            return minDepth(root->right) + 1;
        }
    }
};

