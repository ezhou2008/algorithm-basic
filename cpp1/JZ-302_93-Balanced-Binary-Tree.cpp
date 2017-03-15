/*Balanced Binary Tree

Description

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Given binary tree A = {3,9,20,#,#,15,7}, B = {3,#,20,15,7}

A)  3            B)    3
/ \                  \
  9  20                 20
/  \                / \
   15   7              15  7
The binary tree A is a height-balanced binary tree, but B is not.

Tags
Divide and Conquer Recursion

Related Problems
Medium Validate Binary Search Tree
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
class Solution_a {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     *
     * balance和height＊＊同时＊＊计算
     */
    bool isBalanced(TreeNode *root) {
        int height;
        return helper(root, height);
    }

    bool helper(TreeNode* root, int &height ) {
        if (root == NULL) {
            height = 0;
            return true;
        }

        int left_h, right_h;
        bool left_b = helper(root->left, left_h);
        bool right_b = helper(root->right, right_h);

        height = max(left_h, right_h) +1;
        if (left_b && right_b && abs(left_h - right_h) <=1) {
            return true;
        } else {
            return false;
        }
    }
};


class Solution_b {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false
     *
     * balance和height＊＊分别＊＊计算
     */
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        if (isBalanced(root->left) && isBalanced(root->right)) {
            if ( abs( height(root->left)-height(root->right) )<=1 ) {
                return true;
            }
        }
        return false;
    }
    int height(TreeNode *root){
        if (root == NULL) return 0;
        cout << "height: root = " << root->val << endl;
        return max(height(root->left), height(root->right)) + 1;
    }
};



