/*Maximum Depth of Binary Tree

Description
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

Example
Given a binary tree as follow:

1
/ \
2   3
/ \
  4   5
The maximum depth is 3.
*/

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
     *
     * Divide and conquer(bottom up)
     *
     */
    int maxDepth(TreeNode *root) {
/*
        binary tree问题通常只需判断roo是否为null
*/
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) +1;
    }
};


class Solution_template {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     *
     * template for max and min depth
     *
     */
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left && root->right) {
            return max( maxDepth(root->left), maxDepth(root->right) ) + 1;
        } else if (root->left) {
            return maxDepth(root->left) + 1;
        } else {
            return maxDepth(root->right) + 1;
        }
    }
};



