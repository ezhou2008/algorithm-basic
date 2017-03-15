/*Binary Tree Level Order Traversal

Description

Given a binary tree, return the level order traversal
of its nodes' values. (ie, from left to right, level by level).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
    / \
  9  20
    /  \
   15   7


return its level order traversal as:

[
[3],
[9,20],
[15,7]
]
Challenge
Challenge 1: Using only 1 queue to implement it.

Challenge 2: Use DFS algorithm to do it.
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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> node_q;
        node_q.push(root);

        while ( !node_q.empty() ) {
            vector<int> cur_res;
/*
            important：node_q的size 在不断的变化，所以需要提前将目前的size 保存
*/
            int q_size = node_q.size();
            for (int i=0; i<q_size; i++) {
                TreeNode* cur_node = node_q.front();
                node_q.pop();

                cur_res.push_back( cur_node->val );
                if (cur_node->left) {
                    node_q.push( cur_node->left );
                }
                if (cur_node->right) {
                    node_q.push( cur_node->right );
                }
            }
            result.push_back( cur_res );
        }

        return result;
    }
};
