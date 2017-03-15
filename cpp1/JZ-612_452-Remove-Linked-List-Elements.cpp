/*Remove Linked List Elements

Description
Remove all elements from a linked list of integers that have value val.

Example
Given 1->2->3->3->4->5->3, val = 3, you should return the list as 1->2->4->5*/
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
     * @param val an integer
     * @return a ListNode
     *
     * 1. 使用dummy head，因为真正的head可能被删除
     * 2. 要删除一个节点，只要找到其前驱节点即可
     *
     */
    ListNode *removeElements(ListNode *head, int val) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* pCur = &dummy;
        while(pCur->next) {
            if (pCur->next->val == val) {
//                删除 pCur->next
                pCur->next = pCur->next->next;
            } else {
                pCur = pCur->next;
            }
        }

        return dummy.next;
    }
};