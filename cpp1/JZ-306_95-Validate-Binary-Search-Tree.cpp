/*Validate Binary Search Tree

Description
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
A single node tree is a BST

Example
An example:

2
/ \
1   4
/ \
  3   5
The above binary tree is serialized as {2,1,4,#,#,3,5} (in level order).
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

class Solution_divide_conquer {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */

    bool isValidBST(TreeNode *root) {
        long sub_max, sub_min;
        if (root == NULL) return true;
        return helper(root, sub_max,sub_min);

    }

    bool helper(TreeNode* root, long &sub_max, long &sub_min) {
        if ( root == NULL ) {
            sub_max = LONG_MIN;
            sub_min = LONG_MAX;
            return true;
        }

        long l_sub_max, l_sub_min;
        long r_sub_max, r_sub_min;

        if (helper(root->left, l_sub_max, l_sub_min) &&
            helper(root->right, r_sub_max, r_sub_min) &&
            (l_sub_max < root->val && r_sub_min > root->val) ) {
            sub_max = max((long)root->val,r_sub_max);
            sub_min = min((long)root->val,l_sub_min);
            return true;
        }
        return false;
    }

};