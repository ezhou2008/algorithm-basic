/*Binary Tree Path Sum II

Description
Your are given a binary tree in which each node
contains a value. Design an algorithm to get all
paths which sum to a given value. The path does not
need to start or end at the root or a leaf, but it must
go in a straight line down.

Example
Given a binary tree:

     1
    / \
   2   3
  /   /
 4   2
for target = 6, return

[
[2, 4],
[1, 3, 2]
]*/

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
     * @param target an integer
     * @return all valid paths
     *
     * 要点：
     * 1. dfs＋backtracking
     * 2. 对于path进行反向搜索，找出需要的结果＊＊＊重要的技巧＊＊＊
     * 3. 题意：path起始可以是中间节点
     *
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode *root, int target) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        vector<int> root_path;
        helper(root, root_path, res, target);

        return res;
    }

    void helper(TreeNode* root, vector<int> &path,
                vector<vector<int>> &result, int target) {
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);

/*
        对于path进行反向搜索，找出需要的结果
*/
        int sum = 0;
        for (int i = path.size()-1; i>=0; i--) {
            sum += path[i];
            if (sum == target) {
                result.push_back(vector<int>(path.begin()+i,path.end()));
            }
        }

        helper(root->left, path, result, target);
        helper(root->right, path, result, target);

        path.pop_back(); //backtracking
    }
};