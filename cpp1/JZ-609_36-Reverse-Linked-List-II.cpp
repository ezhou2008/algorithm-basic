/*Reverse Linked List II

Description
Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

Example
Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.

Challenge
Reverse it in-place and in one-pass*/

/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution_recommend {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     *
     * Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
     *
     * 这个solution效率稍低点，但逻辑比较清晰，不容易出错
     * 1. 将链表分成3部分，反转中间部分，然后将三部分连接起来
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {

        if (head == NULL || head->next == NULL || m==n) {
            return head;
        }

/*
        step1 分割链表
*/

        // 必须使用dummy head的原因是m可能为1，这样的话，第一部分链表就为空
        // 如果不使用dummy的话，对于这种情况处理就比较麻烦，容易出错
        ListNode dummy1(0);
        dummy1.next = head;
        // first_tail 从dummy1开始，这样的话，如果m＝1，则first_tail = dummy, 表示第一部分为空
        ListNode* first_tail = &dummy1;
        for (int i = 0; i < m-1; i++) {
            first_tail = first_tail->next;
        }
        // tail points to (m-1)th node
        ListNode* mid_l_head = first_tail->next;
        first_tail->next = NULL;

        ListNode* mid_l_tail = mid_l_head;
        for(int i = 0; i < n-m; i++) {
            mid_l_tail = mid_l_tail->next;
        }

        ListNode* last_l_head = mid_l_tail->next;
        mid_l_tail->next = NULL;
/*
        step2 reverse middle list
*/
        mid_l_head = reverse(mid_l_head);

/*
        step3 merge all together
*/
        first_tail->next = mid_l_head;
        while (mid_l_head->next) {
            mid_l_head = mid_l_head->next;
        }
        //merget last to final list
        mid_l_head->next = last_l_head;

        return dummy1.next;

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


class Solution_2 {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     *
     * 和上面solution差不多，更简洁些
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {

        if (head == NULL || head->next == NULL || m==n) {
            return head;
        }

/*分隔链表，第一部分m个节点
*/
        // 必须使用dummy head的原因是m可能为1，这样的话，第一部分链表就为空
        // 如果不使用dummy的话，对于这种情况处理就比较麻烦，容易出错
        ListNode dummy1(0);
        dummy1.next = head;
        // first_tail 从dummy1开始，这样的话，如果m＝1，则first_tail = dummy, 表示第一部分为空
        ListNode* first_tail = &dummy1;
        for (int i = 0; i < m-1; i++) {
            first_tail = first_tail->next;
        }
        // tail points to (m-1)th node
        ListNode* mid_l_head = first_tail->next;
        // first_tail->next = NULL;

/*＊＊＊反转第二部分前n-m+1个＊＊＊＊＊＊
*/
        ListNode dummy2(0);
        ListNode* mid_l_tail = mid_l_head;
        for(int i = 0; i < n-m+1; i++) {
            ListNode* tmp = dummy2.next;
            dummy2.next = mid_l_head;
            mid_l_head = mid_l_head->next;
            dummy2.next->next = tmp;
        }
        // 加上没有反转的部分
        mid_l_tail->next = mid_l_head;

/*合并链表
*/        first_tail->next = dummy2.next;

        return dummy1.next;

    }

};
