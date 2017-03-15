/*
Check two given binary trees are identical or not.
Assuming any number of tweaks are allowed.
A tweak is defined as a swap of the children of one node in the tree.
Example
    1             1
   / \           / \
  2   3   and   3   2
 /                   \
4                     4
are identical.
    1             1
   / \           / \
  2   3   and   3   4
 /                   \
4                     2
are not identical.
Note
There is no two nodes with the same value in the tree.
Challenge
O(n) time
Tags Expand
Binary Tree
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
     * @aaram a, b, the root of binary trees.
     * @return true if they are tweaked identical, or false.
     *
     * divide and conquer(bottom up)
     * 要点：tweaked identical = mirrored OR indentical
     *
     *
     */
    bool isTweakedIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here

        if (a == NULL && b == NULL) {
            return true;
        }

        if (a == NULL || b == NULL ) {
            return false;
        }

        if (a->val != b->val) {
            return false;
        }

        // indentical
        if ( isTweakedIdentical(a->left, b->left) && isTweakedIdentical(a->right,b->right) ) {
            return true;
        }
        // mirror
        if ( isTweakedIdentical(a->left, b->right) && isTweakedIdentical(a->right,b->left) ) {
            return true;
        }
        return false;

    }
};