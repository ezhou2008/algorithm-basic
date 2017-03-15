/*Remove Duplicates from Sorted List

Description
Given a sorted linked list, delete all duplicates such that
each element appear only once.

Example
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
     * @return: head node
     *
     * 注意：每种duplicates保留一个
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // dummy head is not necessary since head is NOT possilbe be removed
/*        ListNode dummy(0);
        dummy.next = head;*/
        ListNode* head_bak =  head;

        // 空链表（不用在开始判断链表是否为空）或者到链表最后一个节点推出
        while (head && head->next) {
            if (head->val == head->next->val) {
                // remove next
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }

//        return dummy.next;
        return head_bak;
    }
};