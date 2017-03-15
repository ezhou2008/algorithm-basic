/*Insertion Sort List

Description
Sort a linked list using insertion sort.
Example
Given 1->3->2->0->null, return 0->1->2->3->null.*/
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
     * @return: The head of linked list.
     * 要点：
     * 1. 两个独立链表, 原list 和 新建的sorted list，the two lists没有共有node。
     * 2. 不断的将原list的node插入到 sorted list
     * 3. 返回sorted list
     *
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(0);

        while(head) {
            // 将head节点插入到sorted list（headed by dummy)
            ListNode* curNode = &dummy;
            // 找出插入位置
            while (curNode->next && curNode->next->val < head->val) {
                curNode = curNode->next;
            }

            // 将head插入到curNode后面
            ListNode* head_next = head->next;
            head->next = curNode->next;
            curNode->next = head;
            //head moves on
            head = head_next;
        }

        return dummy.next;

    }
};