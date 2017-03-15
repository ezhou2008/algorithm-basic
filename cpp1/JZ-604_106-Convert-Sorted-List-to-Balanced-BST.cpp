/*Convert Sorted List to Balanced BST

Description
Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.

Example
               2
1->2->3  =>   / \
             1   3
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
     * @param head: The first node of linked list.
     * @return: a tree node
     *
     * divide and conquer
     *
     * 1. 将list分成left list， 中点，right list
     *    left and right 个数最多差1（在list为奇数个节点时）
     * 2. middle生成root节点，left, right 分别递归
     * 3. left and right挂到root 上
     *
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

/*
        分隔list
*/
        // find middle
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = head->next;
        ListNode* slow = &dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // slow 指向middle前一个节点
        // middle 有可能为空
        ListNode* middle = slow->next;
        ListNode* list_r = middle->next;
        slow->next = NULL;
        // list_l不能设为head，因为可能为空
        ListNode* list_l = dummy.next;

/*
        conquer
*/
        TreeNode* root = new TreeNode(middle->val);
        root->left =  sortedListToBST(list_l);
        root->right = sortedListToBST(list_r);
        return root;
    }

};


