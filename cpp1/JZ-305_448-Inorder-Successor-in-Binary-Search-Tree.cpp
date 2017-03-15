/*Inorder Successor in Binary Search Tree

Description
Given a binary search tree (See Definition) and a node in it,
find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.

Notice

It's guaranteed p is one node in the given tree.
(You can directly compare the memory address to find p)

Example
Given tree = [2,1] and node = 1:

2
/
1
return node 2.

Given tree = [2,1,3] and node = 2:

2
/ \
1   3
return node 3.

Challenge
O(h), where h is the height of the BST.

Tags
Binary Search Tree Binary Tree
Related Problems
Medium Validate Binary Search Tree 22 %
Hard Binary Search Tree Iterator
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_no_recursion {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // write your code here

        if (root == NULL || p==NULL) {
            return NULL;
        }

        TreeNode* result = NULL;
        stack<TreeNode*> node_s;
        TreeNode* cur_node = root;
        bool p_found = false;

        while ( cur_node || !node_s.empty() ) {
            while (cur_node) {
                node_s.push(cur_node);
                cur_node = cur_node->left;
            }
            cur_node = node_s.top();
            node_s.pop();
            if (p_found) {
                result = cur_node;
                return result;
            }
            if (cur_node == p) {
                p_found = true;
            }

            cur_node = cur_node->right;

        }
        return result;
    }

};

class Solution_divide_conquer {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = false;
        return helper(root, p, found);
    }

    TreeNode* helper(TreeNode* root, TreeNode* p, bool &found) {
        if (root == NULL || p == NULL) {
            return NULL;
        }
        TreeNode* res_left=NULL, *res_right = NULL;
        if ((res_left = helper(root->left, p, found)) != NULL) {
            return res_left;
        }
        if (found) {
            return root;
        }
        if (found == false && root == p) {
            found = true;
        }
        if ((res_right = helper(root->right, p, found)) != NULL) {
            return res_right;
        }
    }
};