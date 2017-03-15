/*
Binary Tree Longest Consecutive Sequence II

Description
Given a binary tree, find the length of the longest consecutive sequence path.
The path could be start and end at any node in the tree

Example
     1
    / \
  2   0
 /
3
Return 4 // 0-1-2-3-4

Tags
Binary Tree Depth First Search
Related Problems
Medium Binary Tree Longest Consecutive Sequence III 35 %
Easy Binary Tree Longest Consecutive Sequence 30 %
Hard Binary Tree Path Sum III
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
    int gcs = 0;
    /**
     * @param root the root of binary tree
     * @return the length of the longest consecutive sequence path
     *
     * 和I区别是：任意节点到任意节点
     *
     * 要点：1. divide and conquer
     *      2. 计算local 值，保留全局值
     */
    int longestConsecutive2(TreeNode* root) {
        helper(root);
        return gcs;
    }

    // return <consecutive_ascending, cosecutive_descending>
    // consecutive_ascending: root开始的递增的consecutive sequence（local含义）
    // cosecutive_descending: root开始的递减的consecutive sequence（local含义）
    pair<int,int> helper(TreeNode* root) {
        if (root == NULL) {
            return make_pair(0,0);
        }

        pair<int,int> left = helper (root->left);
        pair<int,int> right = helper(root->right);

        // 计算root开始的local consecutive_ascending sequence
        int lcs_a = 1; // 至少包括root
        if (root->left && root->val + 1 == root->left->val) {
            lcs_a = max(lcs_a, left.first+1);
        }
        if (root->right && root->val + 1 == root->right->val) {
            lcs_a = max(lcs_a, right.first+1);
        }

        // 计算root开始local cosecutive_descending sequence
        int lcs_d = 1; // 至少包括root
        if (root->left && root->val - 1 == root->left->val) {
            lcs_d = max(lcs_d, left.second+1);
        }
        if (root->right && root->val - 1 == root->right->val) {
            lcs_d = max(lcs_d, right.second+1);
        }

/*
 *      gcs = max(gcs, lcs_a);
        gcs = max(gcs, lcs_d);
        if ( root->left && root->right) {
            if (root->left->val == root->val+1 && root->val == root->right->val+1) {
                gcs = max(gcs, left.first+1+right.second);
            }
            if (root->left->val+1 == root->val && root->val+1 == root->right->val) {
                gcs = max(gcs, left.second+1+right.first);
            }
        }
*/
        // 上面注释掉的代码有些多余，下面一行就可以替代
        // 原因是lcs_a和lcs_d只可能在两边，除非只有一个子树，所以longest path可以直接算出
        // 计算＊＊＊包括root在内＊＊＊的local longest consecutive sequence,全局值取最大
        gcs = max(gcs, lcs_a+lcs_d-1);

        return make_pair(lcs_a, lcs_d);
    }
};