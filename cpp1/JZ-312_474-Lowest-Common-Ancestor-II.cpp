/*Lowest Common Ancestor II

Description

Given the root and two nodes in a Binary Tree.
Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth
which is the ancestor of both nodes.

The node has an extra attribute parent which point to the father of itself.
The root's parent is null.


Example
For the following binary tree:

    4
   / \
  3  7
    / \
  5   6
LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7
*/

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution_1 {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     *
     *  这个和Lowest Common Ancestor的区别在于有parent指针，可以从下而上遍历
     *
     * 要点：
     * 找出a到root的路径，找出b到root的路径
     * 找出两条路径中的最后一个相同节点(反向找）
     *  比如：LCA(3, 5)
     *   path(3) = 3,4
     *   path(5) = 5,3,4
     *
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {
        if (root == NULL) return NULL;
        vector<ParentTreeNode*> path_a = find_path(A);
        vector<ParentTreeNode*> path_b = find_path(B);
        //find the last common in the lists
        int idx_a = path_a.size() - 1;
        int idx_b = path_b.size() - 1;
        int idx_last_common = -1;

        while (idx_a >=0 && idx_b >=0 ) {
            if (path_a[idx_a] == path_b[idx_b]) {
                idx_last_common = idx_a;
                idx_a--; idx_b--;
            } else {
                break;
            }
        }
        if(idx_last_common != -1) {
            return path_a[idx_last_common];
        }

        return NULL;
    }

    vector<ParentTreeNode*> find_path( ParentTreeNode *target ) {
        vector<ParentTreeNode*> res;
        if (target == NULL) return res;

        while(target) {
            res.push_back(target);
            target = target->parent;
        }
        return res;
    }
};



/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution_same_as_LCA {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {
        if (root == A || root == B) return root;
        if (root == NULL) return NULL;

        ParentTreeNode* left = lowestCommonAncestorII(root->left, A, B);
        ParentTreeNode* right = lowestCommonAncestorII(root->right, A,B);

        if ( left && right) {
            return root;
        }
        return left?left:right;
    }
};

/*

 Definition of ParentTreeNode:
 class ParentTreeNode {
    public:
        int val;
        ParentTreeNode *parent, *left, *right;
    }

 */

class Solution_2 {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     *
     * 要点：
     * 沿着A到root的路径扫描，看是否有B,
     * 如果没有的话，B=B->parent,重复扫描
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {
        ParentTreeNode* pCur = A;
        while (pCur) { //until root->parent
            if (B == pCur) {
                return pCur;
            }
            pCur = pCur->parent;
        }

        return lowestCommonAncestorII(root, A, B->parent);
    }
};