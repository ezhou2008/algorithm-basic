/*Construct Binary Tree from Inorder and Postorder Traversal

Description

Given inorder and postorder traversal of a tree, construct the binary tree.

Notice

You may assume that duplicates do not exist in the tree.

Example
Given inorder [1,2,3] and postorder [1,3,2], return a tree:

2
/ \
1   3
Tags*/


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
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     *
     *  基本和"JZ-323_73-Construc-Binary-Tree-from-Preorder-and-Inorder-Traversal"相同
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }
        if (inorder.size() != postorder.size()) {
            return NULL;
        }

        return build_helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);

    }
    TreeNode* build_helper(vector<int> &inorder, int start, int end,
                           vector<int> &postorder, int left, int right) {
        if (start > end || left > right) {
            return NULL;
        }
        TreeNode* new_root = new TreeNode( postorder[right] );

        auto it = find( inorder.begin()+start, inorder.begin()+end,
                        new_root->val);
        int root_idx = distance(inorder.begin(), it);

        //divide and conquer
        new_root->left = build_helper( inorder,start,root_idx-1,
                                       postorder, left,left+(root_idx-start-1));
        new_root->right = build_helper( inorder, root_idx+1,end,
                                        postorder,right-1-(end-root_idx-1),right-1);
        return new_root;

    }
};