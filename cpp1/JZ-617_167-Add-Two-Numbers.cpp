/*Add Two Numbers

Description
You have two numbers represented by a linked list,
where each node contains a single digit.
The digits are stored in reverse order,
such that the 1's digit is at the head of the list.
Write a function that adds the two numbers and returns the sum as a linked list.

Example
Given 7->1->6 + 5->9->2. That is, 617 + 295.

Return 2->1->9. That is 912.

Given 3->1->5 and 5->9->2, return 8->0->8.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution_better {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     *
     * 1. 稍作优化的版本
     * 2. 没有借用l1, sum list的节点都是new出来
     *    先new一个value为0的节点(如果没进位的话），后逐个加上来l1, l2
     * 3. 这个版本更简洁，好懂写
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        dummy.next = new ListNode(0);
        ListNode* cur_sum = &dummy;

        ListNode* l1_last_node = NULL;
        while (l1 || l2) {
/*
            如果没有的话，再生成（进位会导致当前节点存在）
*/
            if (cur_sum->next == NULL) {
                cur_sum->next = new ListNode(0);
            }
            cur_sum = cur_sum->next;

            if (l1) {
                cur_sum->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                cur_sum->val += l2->val;
                l2 = l2->next;
            }
/*
            处理进位
*/
            if (cur_sum->val >= 10) {
                cur_sum->next = new ListNode(cur_sum->val/10);
                cur_sum->val %= 10;
            }

        }

        return dummy.next;

    }
};
class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     *
     * 1. 要点：借用来存储sum结果
     * 2. 如果有进位的话，优先加到l1下一个，否则加到l2的下一个，如果都没有下一个的话，就new一个节点
     *
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        dummy.next = l1;

        ListNode* l1_last_node = NULL;
        while (l1 && l2) {
            l1->val += l2->val;
            if (l1->val >= 10) {
                if (l1->next) {
                    l1->next->val += l1->val/10;
                } else if (l2->next) {
                    l2->next->val += l1->val/10;
                } else {
                    l1->next = new ListNode(l1->val/10);
                }
                l1->val %= 10;
            }

            // save last node of l1
            l1_last_node = l1;

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2) {
            l1_last_node->next = l2;
        }

        return dummy.next;

    }
};


