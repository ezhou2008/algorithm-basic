
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
class Solution_1 {
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a complete binary tree, or false.
     *
     * 利用complete tree的特性（heap就是complete tree)
     * 如果每个节点的子节点的index为：  left = 2*i, right = 2*+1
     * 这样的话，如果root的index 为1，按层遍历的话，并count，每个节点的index和count是相等的。
     * 如果不等的话，就不是complete tree。
     */
    bool isComplete(TreeNode* root) {
        // Write your code here
        if (root == NULL) return true;

        // pair<node, index>
        queue<pair<TreeNode*,int>> node_q;
        node_q.push( make_pair(root,1) );
        int node_counts = 0;

        while (!node_q.empty()) {
            pair<TreeNode*,int> Cur = node_q.front();
            node_q.pop();
            node_counts++;

            // printf("cur node = %d, count=%d\n", Cur.first->val, node_counts);
            if (Cur.second != node_counts) {
                return false;
            }

            if (Cur.first->left) {
                node_q.push( make_pair(Cur.first->left, Cur.second*2 ) );
            }
            if (Cur.first->right) {
                node_q.push( make_pair(Cur.first->right, Cur.second*2+1 ) );
            }
        }
        return true;
    }

};

class Solution_2 {
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a complete binary tree, or false.
     *
     * 层遍历
     * 对于每个节点，
     *  1. 如果已经有了left_only的节点的话，再发现有full，和left_only-->return false
     *          full（left and right both exits)
     *  2. 一旦发现right only, --->return false
     */
    bool isComplete(TreeNode* root) {
        // Write your code here
        if (root == NULL) return true;
        queue<TreeNode*> node_q;
        node_q.push(root);

        bool left_only_found = false;
        while (!node_q.empty()) {
            TreeNode* pCur = node_q.front();
            node_q.pop();

            if (pCur->left && pCur->right) {
                if (left_only_found ) {
                    return false;
                } else {
                    node_q.push(pCur->left);
                    node_q.push(pCur->right);
                }
            }
            //left only
            if (pCur->left && !pCur->right) {
                if(left_only_found) {
                    return false;
                } else {
                    left_only_found = true;
                    node_q.push(pCur->left);
                }
            }
            // right only
            if(!pCur->left && pCur->right) {
                return false;
            }
        }
        return true;
    }
};