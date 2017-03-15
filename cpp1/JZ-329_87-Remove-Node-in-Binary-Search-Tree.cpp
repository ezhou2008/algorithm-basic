/*Remove Node in Binary Search Tree

Description

Given a root of Binary Search Tree with unique value for each node.
Remove the node with given value. If there is no such a node with
given value in the binary search tree, do nothing. You should keep
the tree still a binary search tree after removal.

Example
Given binary search tree:

    5
   / \
  3   6
 / \
2   4
Remove 3, you can either return:

    5
   / \
  2   6
   \
    4
or

    5
   / \
  4   6
 /
2
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


class Solution_latest {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     * 要点：
     * 1. 分三种情况：target无child，一个child，2个child
     * 2. 添加一个dummy node，因为target可能为root
     *
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // dummy node, root could be deleted
        TreeNode dummy(INT_MAX);
        dummy.left = root;

        pair<TreeNode*,TreeNode*> ret = findNode(&dummy, value);
        TreeNode* parent = ret.first;
        TreeNode* target = ret.second;
        if (!target) {
            return dummy.left;
        }
        removeNode_helper(target,parent);
        return dummy.left;
    }

    // dummy root node ensure parent is not NULL
    void removeNode_helper(TreeNode* target, TreeNode* parent) {
        // target为叶子节点，删除此节点
        if (!target->left && !target->right) {
            if (parent->left == target) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            delete target;
            return;
        }
        // target有两个child
        if (target->left && target->right) {
            // 选择左子树的最大者（也可以选择右子树的最小者），填充target的位置
            // 1. 存在右right tree, choose right most leaf
            // 2. 否则选择root of left subtree
            //
            TreeNode* cur_node = target->left;
            TreeNode* cur_parent = target;
            while ( cur_node->left || cur_node->right) {
                cur_node = cur_node->right;
                cur_parent = cur_node;
            }
            target->val = cur_node->val;
            delete cur_node;
            if (cur_node == cur_parent->left) {
                cur_parent->left = NULL;
            } else {
                cur_parent->right = NULL;
            }
            return;
        }
        // target只有一个child
        if (target->left || target->right) {
            TreeNode* child = (target->left) ? target->left: target->right;
            if (parent->left == target) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            delete target;
            return;
        }
    }

    // return (parent,target), if not found, return (NULL,NULL)
    // start from children of parent(excluding parent)
    pair<TreeNode*,TreeNode*> findNode(TreeNode* parent, int value) {
        if(parent == NULL || (!parent->left && !parent->right)) {
            return make_pair<TreeNode*,TreeNode*>(NULL,NULL);
        }
        if (parent->left && parent->left->val == value) {
            return make_pair(parent,parent->left);
        }
        if (parent->right &&parent->right->val == value) {
            return make_pair(parent,parent->right);
        }

        if (value < parent->val && parent->left) {
            return findNode(parent->left, value);
        }
        if (value > parent->val && parent->right) {
            return findNode(parent->right, value);
        }
        return make_pair<TreeNode*,TreeNode*>(NULL,NULL);
    }

};