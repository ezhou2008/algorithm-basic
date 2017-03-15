/*Binary Tree Maximum Path Sum

Description

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example
Given the below binary tree:

1
/ \
2   3
return 6.
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
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int all_max, root_max;
        helper(root, all_max, root_max);
        return all_max;
    }

    void helper(TreeNode* root, int &all_max, int &root_max ){
        //base case
        if (root == NULL) {
            all_max = INT_MIN;
            root_max = INT_MIN;
            return;
        }

        int all_max_l, all_max_r;
        int root_max_l, root_max_r;
        //divide
        helper(root->left, all_max_l, root_max_l);
        helper(root->right, all_max_r, root_max_r);

        //conqure
/*
        从 root到其左右子树任意以节点path的最大值（同Binary Tree Maximum Path Sum II）

        下面写法有问题：
        root_max = max(root->val, root->val+max(root_max_l, root_max_r));
        如果max(root_max_l,root_max_r)返回的是INT_MIN，而且root->val是负值的话，就会溢出。
*/
        root_max = root->val + max(0, max(root_max_l, root_max_r));
/*
        从左子树到右子树（或者从右子树到左子树）并包括root 在内的路径的path的最大值
*/
        int tmp = root->val + max(0, root_max_l) + max(0,root_max_r);
/*
        所有路径的最大值：max(左子树最大， 右子树最大，包括root在内的最大)
*/
        all_max = max( max(all_max_l,all_max_r), tmp);
        // printf(" root = %ld, root_max = %ld, all_max = %ld\n", (long)root->val, root_max, all_max);

        return;
    }
};