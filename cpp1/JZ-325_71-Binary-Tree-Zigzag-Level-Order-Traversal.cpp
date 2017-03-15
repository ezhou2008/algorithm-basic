/*
Binary Tree Zigzag Level Order Traversal

Description
Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).

Example
Given binary tree {3,9,20,#,#,15,7},

       3
     / \
    9  20
        /  \
      15   7


return its zigzag level order traversal as:

[
[3],
[20,9],
[15,7]
]
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values
     * level tranversal基础上，交替反转结果即可
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> node_q;
        node_q.push(root);
        bool r_l = false;

        while ( !node_q.empty() ) {
            int q_size = node_q.size();
            vector<int> level_res;
            for (int i=0; i<q_size; i++) {
                TreeNode* cur_node = node_q.front();
                node_q.pop();

                level_res.push_back(cur_node->val);
                if (cur_node->left) {
                    node_q.push(cur_node->left);
                }
                if (cur_node->right) {
                    node_q.push(cur_node->right);
                }
            }
            if (r_l) {
                reverse(level_res.begin(),level_res.end());
            }
            r_l = !r_l;
            res.push_back(level_res);
        }
        return res;
    }
};