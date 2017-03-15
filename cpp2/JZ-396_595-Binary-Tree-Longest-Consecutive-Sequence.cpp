/*Binary Tree Longest Consecutive Sequence

Description

Judge
Given a binary tree, find the length of the
longest consecutive sequence path.

The path refers to any sequence of nodes from some starting
node to any node in the tree along the parent-child connections.
The longest consecutive path need to be from parent to child
(cannot be the reverse).

Example
For example,

    1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

    2
    \
     3
    /
   2
  /
1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the length of the longest consecutive sequence path
     * 1. 要点：利用global和local的概念
     * 2. 计算local的过程中, 保留global
     *
     * 注意：longest consecutive sequence是递增＋1序列，
     *  比如： 1，2，3，4，5等， 2,4,6不是的
     *
     *
     */
    int longestConsecutive(TreeNode* root) {
        int global_lcs = 0;
        helper(root, global_lcs);
        return global_lcs;
    }

    // pair<longest consecutive path, scending order = true>
    int helper(TreeNode* root, int &global_lcs) {
        if (root == NULL) {
            return 0;
        }

        int left = helper(root->left, global_lcs);
        int right =  helper(root->right, global_lcs);

        int local_lcs = 1; // root only
        if (root->left && root->val+1 == root->left->val) { // root+left
            local_lcs = max(local_lcs, left+1);
        }
        if (root->right && root->val+1 == root->right->val) { // root+right
            local_lcs = max(local_lcs, right+1);
        }
        global_lcs = max(global_lcs, local_lcs);
        return local_lcs;
    }
};