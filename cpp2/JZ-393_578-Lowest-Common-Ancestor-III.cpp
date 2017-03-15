/*Lowest Common Ancestor III

Description
Given the root and two nodes in a Binary Tree.
Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest
depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Notice
node A or node B may not exist in tree.

Example
For the following binary tree:

     4
    / \
    3   7
   / \
  5   6
LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7
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
     * @param root: The root of the binary tree.
     * @param A and B: two nodes
     * @return: Return the LCA of the two nodes.
     *
     * 基于./JZ-308_88-Lowest-Common-Ancestor.cpp
     * 区别：
     * 1. 这里a,b可能不存在，jz-308里a,b肯定存在
     *    所以，1.1 这里需要标识出a,b是否存在
     *         1.2 JZ-308里root发现＝＝a或者b的话，就可以返回(a，b肯定存在）
     *              本题必须要继续搜索，当然jz-308也可以继续搜索，不影响结果。
     */
    TreeNode *lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {
        // 特殊情况，先排除掉
        if (A == B) {
            return A;
        }

        bool A_found = false;
        bool B_found = false;
        TreeNode* ret_node = helper(root, A, B, A_found, B_found);
        if (A_found && B_found ) {
            return ret_node;
        } else {
            return NULL;
        }

    }

    TreeNode *helper(TreeNode* root, TreeNode* A, TreeNode* B, bool &A_found, bool &B_found) {
/*
         simple case
*/
        if (root == NULL) return NULL;
/*
        divide
*/
        // 必须放在"if (root == A ) {"前面, 需要全搜索
        TreeNode* left = helper(root->left, A, B, A_found, B_found);
        TreeNode* right = helper(root->right, A, B,A_found, B_found);
/*
        conquer
*/
        if (root == A ) {
            A_found = true;
            return root;
        }
        if (root == B ) {
            B_found = true;
            return root;
        }

        if ( left && right) {
            return root;
        }
        return left?left:right;
    }
};