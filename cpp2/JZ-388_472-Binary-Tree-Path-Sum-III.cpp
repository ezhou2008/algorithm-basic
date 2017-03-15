/*Binary Tree Path Sum III

Description
Give a binary tree, and a target number,
find all path that the sum of nodes equal to target,
the path could be start and end at any node in the tree.

Example
Given binary tree:

     1
    / \
   2   3
  /
 4
and target = 6. Return :

[
[2, 4],
[2, 1, 3],
[3, 1, 2],
[4, 2]
]*/

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     *
     * 要点：
     * 1. 遍历树，对每个node做dfs
     * 2. 每个node的dfs包括3种：
     *    沿着左子树方向， 沿着右子树方向，沿着parent方向
     * 3. 和前面主要区别在于：
     *      此题目：1. 对于每个节点都以此节点起始dfs 2. dfs还需要沿parent方向做
     *      前面相关题目：只从root起始做dfs，dfs只做child方向
     */
    vector<vector<int>> binaryTreePathSum3(ParentTreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> results;
        dfs(root, target, results);
        return results;
    }
/*
前向遍历树，每个节点dfs
*/
    void dfs(ParentTreeNode *root, int target, vector<vector<int>> &results) {
        if (root == NULL)
            return;

        vector<int> buffer;
        // root起始沿着子树方向和parent方向的dfs
        findSum(root, NULL, target, buffer, results);

        // 对左右子树递归
        dfs(root->left, target, results);
        dfs(root->right, target, results);
    }

/*
root起始沿着子树方向的dfs ＋ root起始沿着parent方向的dfs
*/
    // up_node:  表示root的上线，＊禁止＊dfs从root到up_node的访问
    //           如果up_node == root->parent, 表示从root开始只能沿着子树方向dfs
    //           如果up_node == NULL, 表示dfs可以沿着所有方向前进
    //                1.  沿着子树方向 2. 沿着parent方向
    // buffer:  当前的path
    void findSum(ParentTreeNode *root, ParentTreeNode *up_node, int target,
                 vector<int> &buffer, vector<vector<int>> &results) {
        // 添加当前node到path里
        buffer.push_back(root->val);
        // 小技巧：这样的话就不用记录当前path（buffer）的sum了
        target -= root->val;

        if (target == 0) {
            results.push_back(buffer);
        }

/*       findSum第一次调用时，由于up_node=NULL, 所以所有方向（下面三个）dfs都可以
         后续的调用只能沿着特定方式
*/
        // root起始沿着parent方向的dfs
        if (root->parent != NULL && root->parent != up_node)
            // findSum: cur_root = root->parent, up_node = root
            findSum(root->parent, root, target, buffer, results);
        // root起始沿着子树方向的dfs
        if (root->left != NULL && root->left  != up_node)
            findSum(root->left, root, target, buffer, results);
        // root起始沿着子树方向的dfs
        if (root->right != NULL && root->right != up_node)
            findSum(root->right, root, target, buffer, results);

        // backtracking
        buffer.pop_back();
    }
};

/*
example：
{1,2,3,4,5,6,7}, 6

       1
     /   \
    2     3
   / \   / \
  4   5 6   7

所有dfs如下：
----dfs node 1----
path=1,
path=1,2,
path=1,2,4,
path=1,2,5,
path=1,3,
path=1,3,6,
path=1,3,7,

----dfs node 2----
path=2,
path=2,1,       =>parent 方向
path=2,1,3,     =>parent 方向
path=2,1,3,6,   =>parent 方向
path=2,1,3,7,   =>parent 方向
path=2,4,       =>left subtree 方向
path=2,5,       =>right subtre 方向

----dfs node 4----
path=4,
path=4,2,
path=4,2,1,
path=4,2,1,3,
path=4,2,1,3,6,
path=4,2,1,3,7,
path=4,2,5,

----dfs
----dfs

----dfs node 5----
path=5,
path=5,2,
path=5,2,1,
path=5,2,1,3,
path=5,2,1,3,6,
path=5,2,1,3,7,
path=5,2,4,

----dfs
----dfs

----dfs node 3----
path=3,
path=3,1,
path=3,1,2,
path=3,1,2,4,
path=3,1,2,5,
path=3,6,
path=3,7,

----dfs node 6----
path=6,
path=6,3,
path=6,3,1,
path=6,3,1,2,
path=6,3,1,2,4,
path=6,3,1,2,5,
path=6,3,7,

----dfs
----dfs

----dfs node 7----
path=7,
path=7,3,
path=7,3,1,
path=7,3,1,2,
path=7,3,1,2,4,
path=7,3,1,2,5,
path=7,3,6,

----dfs
----dfs

输出结果：
[[2,1,3],[2,4],[3,1,2],[4,2],[6]]
*/
