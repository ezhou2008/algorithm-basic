/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
    / \
  2     2
/ \     / \
3  4    4  3
But the following [1,2,2,null,3,null,3] is not:
      1
    / \
  2   2
    \   \
    3    3
Note:
        Bonus points if you could solve it both recursively and iteratively.
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
     * @param root, the root of binary tree.
     * @return true if it is a mirror of itself, or false.
     *
     * 注意： 是左右子树对称，不是左右子树相等
     * 参见：JZ-313_470-Tweaked-Identical-Binary-Tree
     */
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);

    }
    bool isMirror(TreeNode* A, TreeNode* B) {
        if (A == NULL && B == NULL) {
            return true;
        }
        if (A==NULL || B== NULL) {
            return false;
        }
        if (A->val != B->val) {
            return false;
        }

        if (isMirror(A->left,B->right) && isMirror(A->right,B->left)) {
            return true;
        }
        return false;

    }
};