/*Insert Node in a Binary Search Tree

Description

Given a binary search tree and a new tree node,
insert the node into the tree. You should keep the tree
still be a valid binary search tree.

Notice
You can assume there is no duplicate values in this tree + node.

Example
Given binary search tree as follow, after Insert node 6, the tree should be:

  2             2
 / \           / \
1   4   -->  1   4
    /           / \
  3            3   6
Challenge
Can you do it without recursion?*/


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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     *
     * divide and conquer，返回子树的根节点
     *
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == NULL) {
            return node;
        }

        if (node->val < root->val) {
/*
 *          对于叶子节点，root－>left指向新加入的节点
            对于非叶子节点，root->left不为空，root->left只是重新赋值一次而已，没有关系
*/
//            返回的是子树的根节点
            root->left = insertNode(root->left, node);
        } else {
            root->right = insertNode(root->right, node);
        }
        return root;
    }
};

class Solution_更容易理解_递归 {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (node == NULL ) {
            return root;
        }
        if (root == NULL) {
            return node;
        }
        if (node->val < root->val) {
            if (root->left) {
                insertNode(root->left,node);
            } else {
                root->left = node;
            }
        } else {
            if (root->right) {
                insertNode(root->right,node);
            } else {
                root->right = node;
            }
        }
        return root;
    }
};