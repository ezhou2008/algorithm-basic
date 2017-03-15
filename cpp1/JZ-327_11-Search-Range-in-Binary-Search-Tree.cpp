/*Search Range in Binary Search Tree

Description

Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree.
Find all the keys of tree in range k1 to k2. i.e.
print all x such that k1<=x<=k2 and x is a key of given BST. Return all the keys in ascending order.

Example
If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].

       20
      /  \
     8   22
    / \
  4   12
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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     *
     * 在inorder traversal 基础上输出即可
     *
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {

        vector<int> result;

        if (root == NULL) return result;

        //inorder traversal

        stack<TreeNode*> node_s;
        TreeNode* cur_node = root;

        while ( !node_s.empty() || cur_node ){
            while (cur_node) {
                node_s.push(cur_node);
                cur_node = cur_node->left;
            }

            // pop out from stack
            cur_node = node_s.top();
            node_s.pop();

            if (cur_node->val <= k2 && cur_node->val >= k1) {
                result.push_back(cur_node->val);
            }

            if (cur_node->val > k2) {
                break;
            }

            //check if cur_node->val is in range

            cur_node = cur_node->right;
        }

        return result;


    }

};