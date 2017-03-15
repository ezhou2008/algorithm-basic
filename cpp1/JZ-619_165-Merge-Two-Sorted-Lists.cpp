/**Merge Two Sorted Lists

Description
Merge two sorted (ascending) linked lists and return it as a new sorted list.
The new sorted list should be made by splicing together the nodes of the two
lists and sorted in ascending order.

Example
Given 1->3->8->11->15->null, 2->null , return 1->2->3->8->11->15->null.*/


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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     *
     * 1题意：合并两个有序链表
     *         模拟一轮归并排序
     * 2. 使用dummy head
     * 3. 可以作为模版记住
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode dummy(0);

        ListNode* curNode = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curNode->next = l1;  // 注意：curNode->next是next，下面都next
                l1 = l1->next;
            } else {
                curNode->next = l2;
                l2 = l2->next;
            }
            curNode = curNode->next;
        }

        if (l1) { // 不能用while，直接把链表挂在curNode后面就可以了,否则就是死循环
            curNode->next = l1;
        }
        if (l2){
            curNode->next = l2;
        }

        return dummy.next;

    }
};