/*Binary Tree Preorder Traversal

Description

Given a binary tree, return the preorder traversal of its nodes' values.

Example
Given:

1
/ \
  2   3
/ \
4   5
return [1,2,4,5,3].

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

class Solution_divide_conquer {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     *
     */

/*
    divide and conquer template
    ---------------------------
    divide&conquer(input I)
    begin
    if (size of input is small enough) then
            solve directly;
    return;
    endif
            divide I into two or more parts I1, I2,...;
    call divide&conquer(I1) to get a subsolution S1;
    call divide&conquer(I2) to get a subsolution S2;
    ...
    Merge the subsolutions S1, S2,...into a
            global solution S;
    end
    ---------------------------
     和递归解法的区别（都是基于递归）：
     1. Divdie&conquer是bottom up,  递归解法是 top down
     2. divide&conquer: result in return value
        递归：           result in parameter

*/

     vector<int> preorderTraversal(TreeNode *root) {
         vector<int> res;
/*
        规模很小，直接解决
*/
         if (root == NULL) {
             return res;
         }
/*
         divide
*/
         vector<int> left_res, right_res;
         if (root->left) {
              left_res = preorderTraversal(root->left);
         }
         if (root->right) {
             right_res = preorderTraversal(root->right);
         }

/*
        conquer
*/

         res.push_back(root->val);
         copy(left_res.begin(), left_res.end(), back_inserter(res));
         copy(right_res.begin(), right_res.end(), back_inserter(res));
         return res;
     }
};

class Solution_recursive {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     *
     *
     *
     */
     vector<int> preorderTraversal(TreeNode *root) {
         vector<int> res;
         pre_trans(root, res);

         return res;
     }

    void pre_trans(TreeNode* root, vector<int> &result) {
/*
         递归出口
*/
        if (root == NULL) {
            return;
        }

        result.push_back(root->val);
        pre_trans(root->left, result);
        pre_trans(root->right, result);
    }

};

class Solution_NonRecursive {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     *
     * 此解法是 top down
     *
     */

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        stack<TreeNode*> node_stack;
        node_stack.push(root);

        while( !node_stack.empty() ) {
            TreeNode* pCur = node_stack.top();
            node_stack.pop();

            res.push_back(pCur->val);

/*
            right 子树必须先push to statck, 因为左子树要先输出
*/
            if (pCur->right) {
                node_stack.push(pCur->right);
            }
            if (pCur->left) {
                node_stack.push(pCur->left);
            }
        }

        return res;
    }
};
