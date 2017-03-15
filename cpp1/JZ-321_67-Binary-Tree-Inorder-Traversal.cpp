/*Binary Tree Inorder Traversal

Description
Given a binary tree, return the inorder traversal of its nodes' values.

        Example
Given binary tree {1,#,2,3},

    1
    \
     2
    /
    3

return [1,3,2].

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

class Solution_NonRecursive_improved_背诵 {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> result;

        stack<TreeNode*> node_s;
        TreeNode* cur_node = root;

        while ( cur_node || !node_s.empty() ) {
/*        先从root到left最远的叶子节点路径上的所有节点入栈
 */
            while (cur_node) {
                node_s.push(cur_node);
                cur_node = cur_node->left;
            }
/*
            处理或输出节点
*/
            cur_node = node_s.top();
            node_s.pop();
            result.push_back(cur_node->val);
/*
            对右子树做递归处理
*/
            cur_node = cur_node->right;
        }
        return result;
    }
};

class Solution_1 {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> result;

        stack<TreeNode*> node_s;
        TreeNode* cur_node = root;

        while (true) {
            while (cur_node) {
                node_s.push(cur_node);
                cur_node = cur_node->left;
            }

            if (node_s.empty()) break;
            cur_node = node_s.top();
            node_s.pop();
            result.push_back(cur_node->val);
/*
            对右子树做递归处理
*/
            cur_node = cur_node->right;
        }
        return result;
    }
};



class Solution_NonRecursive {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        //base cases
        vector<int> result;

        stack<TreeNode*> n_stack;

/*        先从root到left最远的叶子节点路径上的所有节点入栈
 */
        TreeNode* pCur = root;
        while ( pCur ) {
            n_stack.push(pCur);
            pCur = pCur->left;
        }

/*
        对入栈的节点处理
*/
        while ( !n_stack.empty() ) {
            pCur = n_stack.top();
            n_stack.pop();
            result.push_back( pCur->val );
/*
            对右子树做递归处理
            对右节点处理，如果有左节点（比如说退栈到root->right就很有可能），
                同理先把所有left节点入栈
*/

            if (pCur->right) {
                pCur = pCur->right;
                while (pCur) {
                    n_stack.push(pCur);
                    pCur = pCur->left;
                }
            }
        }
        return result;
    }
};

 class Solution_traversal {
     /**
      * @param root: The root of binary tree.
      * @return: Inorder in vector which contains node values.
      */
 public:
     vector<int> inorderTraversal(TreeNode *root) {
         vector<int> res;
         inorder_helper( root, res);
         return res;

     }

     void inorder_helper(TreeNode* root, vector<int> &res) {
         if (root == NULL) return;
         inorder_helper( root->left, res);
         res.push_back( root->val );
         inorder_helper( root->right, res);

     }
 };

 class Solution_divide_conquer {
     /**
      * @param root: The root of binary tree.
      * @return: Inorder in vector which contains node values.
      */
 public:
     vector<int> inorderTraversal(TreeNode *root) {
         vector<int> result;
         if (root == NULL) return result;

         vector<int> l_res = inorderTraversal(root->left);
         vector<int> r_res = inorderTraversal(root->right);

         copy( l_res.begin(), l_res.end(), back_inserter(result) );
         result.push_back( root->val );
         copy( r_res.begin(), r_res.end(), back_inserter(result));
     }
 };