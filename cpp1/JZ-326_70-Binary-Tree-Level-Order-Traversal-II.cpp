/*Binary Tree Level Order Traversal II

Description

Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

Example
Given binary tree {3,9,20,#,#,15,7},

        3
       / \
      9  20
        /  \
      15   7


return its bottom-up level order traversal as:

[
[15,7],
[9,20],
[3]
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
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;

        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> node_q;
        node_q.push(root);

        while ( !node_q.empty() ) {
            int q_size = node_q.size();
            vector<int> level_arr;
            for (int i=0; i<q_size; i++) {
                TreeNode* cur_node = node_q.front();
                node_q.pop();

                level_arr.push_back(cur_node->val);

                if (cur_node->left) {
                    node_q.push(cur_node->left);
                }
                if (cur_node->right) {
                    node_q.push(cur_node->right);
                }
            }
            res.push_back(level_arr);
        }
/*
        bottom-up level order traversal
*/
        reverse(res.begin(), res.end());
        return res;
    }
};