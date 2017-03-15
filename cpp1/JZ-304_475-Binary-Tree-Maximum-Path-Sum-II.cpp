/*Binary Tree Maximum Path Sum II

Description
Given a binary tree, find the maximum path sum ＊＊from root＊＊.

The path ＊＊may end at any node＊＊ in the tree and contain at least one node in it.

Example
Given the below binary tree:

1
/ \
2   3
return 4. (1->3)
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
class Solution_divide_conquer {
public:
    /**
     * @param root the root of binary tree.
     * @return an integer
     */
    int maxPathSum2(TreeNode *root) {
        if (root == NULL) return 0;
        return root->val + max(0, max( maxPathSum2(root->left), maxPathSum2(root->right)));

    }
};


class Solution_dfs {
public:
    /**
     * @param root the root of binary tree.
     * @return an integer
     */
    int maxPathSum2(TreeNode *root) {
        if (root == NULL) return 0;
        int cur_sum = 0;
        int max_sum = INT_MIN;
        maxPathSum2_helper(cur_sum,max_sum,root);
        return max_sum;
    }

    void maxPathSum2_helper(int &cur_sum, int &max_sum,TreeNode* root) {
        if (root == NULL) {
            return;
        }
        cur_sum += root->val;

        max_sum = max(max_sum, cur_sum);
        maxPathSum2_helper(cur_sum,max_sum,root->left);
        maxPathSum2_helper(cur_sum,max_sum,root->right);

        // backtracking
        cur_sum -= root->val;
    }

/*
    void maxPathSum2_helper(int cur_sum, int &max_sum,TreeNode* root) {
        if (root == NULL) {
            return;
        }
        cur_sum += root->val;

        max_sum = max(max_sum, cur_sum);
        maxPathSum2_helper(cur_sum,max_sum,root->left);
        maxPathSum2_helper(cur_sum,max_sum,root->right);

        // backtracking: 由于cur_sum是传值，backtracking是隐含完成
*/
    }

};