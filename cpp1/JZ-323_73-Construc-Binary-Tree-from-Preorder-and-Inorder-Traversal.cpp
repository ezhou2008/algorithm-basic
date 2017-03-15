/*
Construct Binary Tree from Preorder and Inorder Traversal

Description

Given preorder and inorder traversal of a tree, construct the binary tree.

Notice
You may assume that duplicates do not exist in the tree.

Example
Given in-order [1,2,3] and pre-order [2,1,3], return a tree:

     2
    / \
   1   3
Tags
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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) return NULL;
        if (preorder.size() != inorder.size()) return NULL;
        buildTree_helper(preorder,0,preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTree_helper(vector<int> &preorder, int left, int right ,
                               vector<int> &inorder, int start, int end) {
        // 注释见下
        if (left > right || start > end) {
            return NULL;
        }
        TreeNode* new_root = new TreeNode(preorder[left]);
        //divide and conquer
/*
        找到root所在的位置
*/
        auto it = find(inorder.begin(), inorder.end(), new_root->val);
        int root_idx = distance(inorder.begin(), it);
/*
        注意范围的界限
        if root_idx == start -> 范围为[left+1,left], [start,start-1], 此时没有左树
        if root_idx == end -> [right+1,right], [end+1,end], 此时没有右树
        也有可能左右树都没有
*/
        new_root->left = buildTree_helper(preorder, left+1,left+1+(root_idx-start-1),
                                          inorder, start, root_idx-1);
        new_root->right = buildTree_helper(preorder, right-(end-root_idx-1),right,
                                           inorder,root_idx+1, end);

        return new_root;
    }



};