/*Minimum Subtree

Description
Given a binary tree, find the subtree with minimum sum.
Return the root of the subtree.

Notice
LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with minimum sum
and the given binary tree is not an empty tree.

Example
Given a binary tree:

       1
    /     \
 -5       2
 / \    /  \
0  2  -4  -5
return the node 1.*/




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
     * @param root the root of binary tree
     * @return the root of the minimum subtree
     *
     * 要点：
     * 1. divide and conquer
     * 2. 计算子树的过程中，保留全局的min
     *
     */
    TreeNode* findSubtree(TreeNode* root) {
        TreeNode* min_root = NULL;
        int min_sum = INT_MAX;

        tree_sum(root, min_sum, min_root);

        return min_root;

    }

    // return: subtree sum.
    // min_sum and min_root will be updated if smaller min found
    int tree_sum(TreeNode* root, int &min_sum, TreeNode* &min_root) {
        if (root == NULL) {
            return 0;  // min_sum and min_root not updated
        }
        int root_sum = root->val + tree_sum(root->left,min_sum, min_root) +
                       tree_sum(root->right, min_sum, min_root);
        if (root_sum < min_sum) {
            min_sum = root_sum;
            min_root = root;
        }
        return root_sum;
    }
};