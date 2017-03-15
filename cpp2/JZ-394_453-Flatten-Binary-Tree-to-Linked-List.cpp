/*Flatten Binary Tree to Linked List

Description
Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.

Notice
Don't forget to mark the left child of each node to null.
Or you will get Time Limit Exceeded or Memory Limit Exceeded.

Example
                1
                 \
       1          2
      / \          \
     2   5    =>    3
    / \   \          \
   3   4   6          4
                       \
                        5
                        \
                          6
Challenge
Do it in-place without any extra memory.*/

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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     *
     * divide and conqure（比较简洁）
     */
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        // save root->left and root->right, 因为后面被修改
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // 连接起来left subtree
        root->left = NULL;
        root->right = left;

        // 移动到left subtree的尾部
        left = root;  // left可能为null，所以下面的while循环从root开始
        while(left->right) {
            left = left->right;
        }

        // 连接上right subtree
        left->right = right;
    }
};