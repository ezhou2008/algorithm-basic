/*Binary Tree Postorder Traversal

Description

Given a binary tree, return the postorder traversal of its nodes' values.

Example
Given binary tree {1,#,2,3},

1
\
     2
/
3

return [3,2,1].

Challenge
Can you do it without recursion?
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

#include <vector>
#include <stack>

using namespace std;

class Solution_divide_conquer {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;

        if (root == NULL) return res;

        vector<int> l_res = postorderTraversal(root->left);
        vector<int> r_res = postorderTraversal(root->right);

        copy(l_res.begin(), l_res.end(), back_inserter(res));
        copy(r_res.begin(), r_res.end(), back_inserter(res));
        res.push_back( root->val );

        return res;
    }
};

 class Solution_recursive {
     /**
      * @param root: The root of binary tree.
      * @return: Postorder in vector which contains node values.
      */
 public:
     vector<int> postorderTraversal(TreeNode *root) {
         vector<int> res;

         post_helper ( root, res);
         return res;

     }

     void post_helper(TreeNode* root, vector<int> &res) {
         if (root == NULL) return;

         post_helper( root->left, res );
         post_helper( root->right, res );
         res.push_back( root->val );
     }
 };

 class Solution_NonRecursive {
     /**
      * @param root: The root of binary tree.
      * @return: Postorder in vector which contains node values.
      */
 public:
     vector<int> postorderTraversal(TreeNode *root) {
         vector<int> res;
         if (root == NULL) return res;

         stack<TreeNode*> n_stack;

         TreeNode* pCur = root;
/*
         使用一个preNode变量记录当前处理节点的子节点
         以便判断当前节点是否应该出栈
*/
         TreeNode* recentVisited = NULL;

         n_stack.push(pCur);

         while ( !n_stack.empty() ) {
/*
             peek栈顶，但不pop
*/
             pCur = n_stack.top();

/*             如果当前节点满足任一条件，则pop out，加入result
             1. 子节点已被访问
             2. 没有子节点
*/
             // 由于左右节点肯定先于parent node访问，找到一个child被访问就意味着两个chidren都被访问，
             // 或者只有一个节点
             if ( (!pCur->left && !pCur->right) ||
                     (recentVisited && (pCur->left == recentVisited || pCur->right == recentVisited)) ) {
                 n_stack.pop();
                 res.push_back( pCur->val );
                 recentVisited = pCur;
                 continue;
             }
/*
             右节点先压栈
*/
             if (pCur->right) {
                 n_stack.push( pCur->right);
             }
/*
             左节点压栈
*/
             if (pCur->left) {
                 n_stack.push( pCur->left);
             }
         }
         return res;

     }
 };
