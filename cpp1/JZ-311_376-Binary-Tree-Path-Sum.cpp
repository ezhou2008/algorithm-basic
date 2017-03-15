/*Binary Tree Path Sum

Description
Given a binary tree, find all paths that sum of the nodes in the path
equals to a given number target.

A valid path is from root node to any of the leaf nodes.

Example
Given a binary tree, and target = 5:

     1
    / \
   2   4
  / \
 2   3
return

[
[1, 2, 2],
[1, 4]
]*/

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
class Solution_traversal {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     *
     * dfs搜索
     *
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> res;
        vector<int> path;
        /* int cur_sum = 0;*/
        path_helper(root, target, path, /*cur_sum,*/ res);
        return res;
    }

    /*cur_sum可以去掉*/
    void path_helper (TreeNode* root, int target, vector<int> &cur_path,
            /*int &cur_sum,*/ vector<vector<int>> &res) {

        if (root == NULL) {
            return;
        }

        cur_path.push_back( root->val );
        target -= root->val;

        if (root->left==NULL && root->right==NULL) {
            if (target == 0) {
                res.push_back( cur_path );
            }
/*
            不能就此return，否则回退部分不能执行到
*/
            // return;
        }

        path_helper(root->left, target, cur_path, /*cur_sum,*/ res);
        path_helper(root->right, target, cur_path, /*cur_sum,*/ res);

        // backtracking
        // cur_sum -= root->val;
        cur_path.pop_back();
    }
};

 class Solution_divide_conquer {
 public:
     /**
      * @param root the root of binary tree
      * @param target an integer
      * @return all valid paths
      */
     vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
         // base case
         vector<vector<int>> res;
         if (root == NULL) return res;

         // solve directly
         if( !root->left && !root->right && root->val == target) {
             vector<int> cur_path;
             cur_path.push_back(root->val);
             res.push_back(cur_path);
         }

         // divide
         vector<vector<int>> l_res, r_res;

         if (root->left) {
             l_res = binaryTreePathSum(root->left, target - root->val);
         }
         if (root->right) {
             r_res = binaryTreePathSum(root->right, target - root->val);
         }

         //conquer
         if (!l_res.empty()) {
             for(auto p : l_res) {
                 vector<int> path;
                 path.push_back(root->val);
                 copy(p.begin(), p.end(), back_inserter(path));
                 res.push_back(path);
             }
         }
         if (!r_res.empty()) {
             for(auto p : r_res) {
                 vector<int> path;
                 path.push_back(root->val);
                 copy(p.begin(), p.end(), back_inserter(path));
                 res.push_back(path);
             }
         }
         return res;
     }
 };