/*Binary Search Tree Iterator

Description
Design an iterator over a binary search tree with the following rules:

Elements are visited in ascending order (i.e. an in-order traversal)
next() and hasNext() queries run in O(1) time in average.

Example
For the following binary search tree, in-order traversal
by using iterator is [1, 6, 10, 11, 12]

10
/    \
1      11
\       \
  6       12
Challenge
Extra memory usage O(h), h is the height of the tree.

Super Star: Extra memory usage O(1)
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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 *
 *
 *
 *
 *    同in-order模版
 *
 */
class BSTIterator {
public:
    stack<TreeNode*> node_s;
    TreeNode* cur_node;
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        cur_node = root;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return cur_node || !node_s.empty();

    }

    //@return: return next node
    TreeNode* next() {
        // write your code here
        while ( cur_node ) {
            node_s.push(cur_node);
            cur_node = cur_node->left;
        }

        TreeNode* ret_node = node_s.top();
        node_s.pop();

        cur_node = ret_node->right;
        return ret_node;

    }
};