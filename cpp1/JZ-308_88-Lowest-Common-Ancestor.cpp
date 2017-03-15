/*Lowest Common Ancestor

Description

Given the root and two nodes in a Binary Tree.
Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth
which is the ancestor of both nodes.

Notice

Assume two nodes are exist in tree.

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
 * 要点：
 * 1. 分别在左右子树找A和B
 *      如果，A，B分别在左右子树，返回root
 *      否则，返回左子树或者右子树
 * 2. 用devide and conquer
 *    divide and conquer是bottom up, 符合 lowest common的定义。
 *    不能用traversal，因为traversal是top down，找出来的就不是 lowest common
 *
 * The idea is to traverse the tree starting from root.
 * If any of the given keys (n1 and n2) matches with root,
 *      then root is LCA (assuming that both keys are present).
 * If root doesn’t match with any of the keys, we recur for left and right subtree.
 *      The node which has one key present in its left subtree and
 *      the other key present in right subtree is the LCA.
 * If both keys lie in left subtree, then left subtree has LCA also,
 *      otherwise LCA lies in right subtree.
 * }
 *
 * e.g.:
 *  {4,3,7,#,#,5,6}, 3, 5
 *  output:
 *  root =  4
        root =  3
            root==A || root==B, return 3
        root =  7
            root =  5
                root==A || root==B, return 5
            root =  6
                root = NULL, return NULL
                root = NULL, return NULL
            root= 6, return: NULL
        root= 7, return: 5
    root= 4, return:

    e.g. :
    {4,3,7,#,#,5,6}, 5, 6
    root =  4
        root =  3
            root = NULL, return NULL
            root = NULL, return NULL
        root= 3, return: NULL
        root =  7
            root =  5
                root==A || root==B, return 5
            root =  6
                root==A || root==B, return 6
        root= 7, return: 7
    root= 4, return: 7

    e.g.:
    {4,3,7,#,#,5,6}, 6, 7

    root =  4
        root =  3
            root = NULL, return NULL
            root = NULL, return NULL
        root= 3, return: NULL
        root =  7
        root==A || root==B, return 7
    root= 4, return: 7
 */

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {

/*
         simple case
*/
        if (root == NULL) return NULL;
/*
        divide
*/
        TreeNode* left = lowestCommonAncestor(root->left, A, B);
        TreeNode* right = lowestCommonAncestor(root->right, A,B);
/*
        conquer
*/
        // 如果root是A或者B的话，ancestor就是root了，
        // 这个判断可以放在对left和right的递归前面
        if (root == A || root == B) return root;
        // 分别在左右子树找到A,B,ancestoer就是root
        if ( left && right) {
            return root;
        }
        // 在一个子树里找到，ancestor就是子树的root了
        return left?left:right;

    }
};