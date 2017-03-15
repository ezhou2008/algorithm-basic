/*Reorder List
Description
Given a singly linked list L: L0 → L1 → … → Ln-1 → Ln

reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

Example
Given 1->2->3->4->null, reorder it to 1->4->2->3->null.

Challenge
Can you do this in-place without altering the nodes' values?*/
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
     * @return: void
     *
     * 1. split into two list at middle
     * 2. reverse right half
     * 3. merge two left and right list alternatively
     *
     */
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return;
        }

/*        find middle（这里需要的是first middle for even lengh of list */
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow is either the middle or end of fisr half, e.g.
        // 1,2,3 ->slow =2
        // 1,2,3,4 =>slow =2

/*        split list into left and right */
        ListNode* left_list = head;
        ListNode* right_list = slow->next;
        slow->next = NULL;

/*        reverse right list
*/        right_list = reverse(right_list);

/*        merget left and right list alernatively
*/
        // 有可能left list比right list要多一个（list有奇数个元素）
        // 这种情况下，需要在while循环结束后，把多出的元素加到结果list里
        ListNode dummy(0);
        ListNode* cur_node = &dummy;
        while (left_list && right_list) {
            // 加入left list
            cur_node->next = left_list;
            left_list = left_list->next;
            cur_node = cur_node->next;
            // 加入right list
            cur_node->next = right_list;
            right_list = right_list->next;
            cur_node = cur_node->next;
        }
        // 添加left list的最后一个元素
        if (left_list) {
            cur_node->next = left_list;
        }
        head = dummy.next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode dummy(0);
        while (head) {
            ListNode* tmp = dummy.next;
            dummy.next = head;
            head = head->next;
            dummy.next->next = tmp;
        }
        return dummy.next;
    }
};


