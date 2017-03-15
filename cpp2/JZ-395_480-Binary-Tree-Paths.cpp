/*Binary Tree Paths

Description
Given a binary tree, return all root-to-leaf paths.

Example
Given the following binary tree:

    1
 /   \
2     3
\
 5
All root-to-leaf paths are:

[
"1->2->5",
"1->3"
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
class Solution_backtracking {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     *
     * 要点：dfs＋backtracking
     *
     * 另外，divide and conquer也可以
     *
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res_string;
        if (root == NULL) {
            return res_string;
        }

        vector<vector<TreeNode*>> res;
        vector<TreeNode*> path;
        path.push_back(root);

        helper(path, res);

        for (auto node_arr : res) {
            stringstream ss;
            for (int i=0; i<node_arr.size()-1; i++) {
                ss << node_arr[i]->val << "->";
            }
            ss << (node_arr.back())->val;
            res_string.push_back(ss.str());
        }

        return res_string;
    }


    void helper(vector<TreeNode*>& path, vector<vector<TreeNode*>> &result) {
        TreeNode* root = path.back();
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
            return;
        }

        if (root->left) {
            path.push_back(root->left);
            helper(path, result);
            path.pop_back();
        }

        if (root->right) {
            path.push_back(root->right);
            helper(path, result);
            path.pop_back();
        }
    }
};

class Solution_backtracking_another {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res_string;
        if (root == NULL) {
            return res_string;
        }

        vector<vector<TreeNode*>> res;
        vector<TreeNode*> path;
        // path.push_back(root);
        helper(root,path, res);

        for (auto node_arr : res) {
            stringstream ss;
            for (int i=0; i<node_arr.size()-1; i++) {
                ss << node_arr[i]->val << "->";
            }
            ss << (node_arr.back())->val;
            res_string.push_back(ss.str());
        }

        return res_string;
    }


    void helper(TreeNode* root, vector<TreeNode*>& path, vector<vector<TreeNode*>> &result) {
        // TreeNode* root = path.back();
        if (root == NULL) {
            return;
        }
        path.push_back(root);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
            path.pop_back();
            return;
        }

        helper(root->left,path, result);
        helper(root->right, path, result);
        path.pop_back();

    }
};

class Solution_no_backtracking {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res_string;
        if (root == NULL) {
            return res_string;
        }

        vector<vector<TreeNode*>> res;
        vector<TreeNode*> path;
        // path.push_back(root);
        helper(root,path, res);

        for (auto node_arr : res) {
            stringstream ss;
            for (int i=0; i<node_arr.size()-1; i++) {
                ss << node_arr[i]->val << "->";
            }
            ss << (node_arr.back())->val;
            res_string.push_back(ss.str());
        }

        return res_string;
    }


    void helper(TreeNode* root, vector<TreeNode*> path, vector<vector<TreeNode*>> &result) {
        // TreeNode* root = path.back();
        if (root == NULL) {
            return;
        }
        path.push_back(root);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
            return;
        }


        helper(root->left,path, result);
        helper(root->right, path, result);

    }
};