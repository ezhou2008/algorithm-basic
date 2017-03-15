/*Swap Nodes in Pairs

Description
Given a linked list, swap every two adjacent nodes and return its head.

Example
Given 1->2->3->4, you should return the list as 2->1->4->3.

Challenge
Your algorithm should use only constant space.
You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     *
     * 1. 使用dummy head，因为真正的head可能会变化（被swap）
     */
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead(INT_MAX);
        dummyHead.next = head;

        ListNode* pCur = &dummyHead;

        while(pCur->next) { // pcur到尾部退出
            if (pCur->next->next) {
                //exchange pCur->next and pCur->next->next
                head = pCur->next;
                pCur->next = pCur->next->next;
                head->next = pCur->next->next;
                pCur->next->next = head;
                pCur = head;
            } else {
                // 链表为奇数个，目前只剩下尾部一个element，没法再swap了，退出
                break;

            }
        }
        return dummyHead.next;
    }
};