/*
Subtree with Maximum Average

Description
Given a binary tree, find the subtree with maximum average. Return the root of the subtree.

Notice
LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with maximum average.

Example
Given a binary tree:

        1
      /   \
    -5     11
   / \   /  \
  1   2 4    -2
return the node 11.
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right>;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right> = NULL;
 *     }
 * }
 */
class Solution {
public:
    TreeNode* max_avg_node = NULL;
    pair<int,int> max_avg_data = make_pair(0, 0);
public:
    /**
     * @param root the root of binary tree
     * @return the root of the maximum average of subtree
     *
     * 要点：
     * 1. divide and conquer
     * 2. 迭代过程中记录最大的值
     * 3. subtree average = subtree_sum/subtree_count
     */
    TreeNode* findSubtree2(TreeNode* root) {
        // Write your code here
        helper(root);
        return max_avg_node;
    }

    // return <subtree sum, subree node #>
    pair<int,int> helper(TreeNode* root) {
        if (root == NULL) {
            return make_pair(0,0);
        }

        pair<int,int> left_data = helper(root->left);
        pair<int,int> right_data = helper(root->right);

        int root_sum = left_data.first + right_data.first + root->val;
        int root_count = left_data.second + right_data.second + 1;

        // printf("root = %d, sum = %d, count = %d\n", root->val, root_sum, root_count);

/*
        乘法改除法，避免浮点运算
        max_avg_node == NULL 这个条件别忘，不然得不出正确的结果，因为此时 ">" 两边都是0
*/
        if (max_avg_node == NULL || root_sum*max_avg_data.second > root_count*max_avg_data.first) {
            max_avg_data = make_pair(root_sum, root_count);
            max_avg_node = root;
        }
        // printf("max root = %d, sum =%d, count = %d\n", root->val, max_avg_data.first,
        // max_avg_data.second);

        return make_pair(root_sum, root_count);
    }

};
