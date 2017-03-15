/*Reverse Linked List

Description
Example
For linked list 1->2->3, the reversed linked list is 3->2->1

Challenge
Reverse it in-place and in one-pass*/


/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     *
     * 1. 使用dummy head
     * 2. 将节点依次插入到dummy head 后面
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode dummy(0);

        while (head) {
            ListNode* dummy_n = dummy.next;
            dummy.next = head;
            ListNode* head_n = head->next;
            head->next = dummy_n;
            head = head_n;
        }

        return dummy.next;
    }
};
