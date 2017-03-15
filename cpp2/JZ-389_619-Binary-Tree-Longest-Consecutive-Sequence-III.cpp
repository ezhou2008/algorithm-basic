/*Binary Tree Longest Consecutive Sequence III

Description
It's follow up problem for Binary Tree Longest Consecutive Sequence II

Given a k-ary tree, find the length of the longest consecutive sequence path.
The path could be start and end at any node in the tree

Example
An example of test data: k-ary tree 5<6<7<>,5<>,8<>>,4<3<>,5<>,3<>>>,
denote the following structure:


      5
   /     \
  6      4
 /|\    /|\
7 5 8  3 5 3

Return 5, // 3-4-5-6-7
*/

/**
 * Definition for a multi tree node.
 * struct MultiTreeNode {
 *     int val;
 *     vector<TreeNode*> children;
 *     MultiTreeNode(int x) : val(x) {}
 * };
 */
class Solution {
public:
    int gcs = 0;
    /**
     * @param root the root of k-ary tree
     * @return the length of the longest consecutive sequence path
     *
     * 几乎和II一样
     *
     * */
    int longestConsecutive3(MultiTreeNode* root) {
        helper(root);
        return gcs;
    }

    // return <consecutive_ascending, cosecutive_descending>
    // consecutive_ascending: root开始的递增的consecutive sequence（local含义）
    // cosecutive_descending: root开始的递减的consecutive sequence（local含义）
    pair<int,int> helper(MultiTreeNode* root) {
        if (root == NULL) {
            return make_pair(0,0);
        }

        // 计算root开始的local consecutive_ascending sequence
        int lcs_a = 1; // 至少包括root
        int lcs_d = 1; // 至少包括root
        for (auto sub : root->children) {
            pair<int,int> sub_data = helper (sub);
            if (sub && root->val + 1 == sub->val) {
                lcs_a = max(lcs_a, sub_data.first+1);
            }
            if (sub && root->val - 1 == sub->val) {
                lcs_d = max(lcs_d, sub_data.second+1);
            }
        }
        // 计算root开始local cosecutive_descending sequence
        gcs = max(gcs, lcs_a+lcs_d-1);

        return make_pair(lcs_a, lcs_d);
    }
};