/*Nth to Last Node in List

Description
Find the nth to last element of a singly linked list.

The minimum number of nodes in list is n.

Example
Given a List  3->2->1->5->null and n = 2, return node  whose value is 1.
*/

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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     *
     *  1. 使用两个指针扫描，
     *      当第一个指针p1扫描到第N个结点后（n从1开始）
     *      第二个指针p2从表头（表头即为第一个节点）与第一个指针同时向后移动，
     *      当第一个指针指向最后节点时，（移动过len - n个节点）
     *      另一个指针就指向倒数第n个结点了, 从表头开始就是 ＝ len - n ＋ 1(head)
     *
     *  o--o--o--o--o--o--o--o--o--o--o
     *  |        |  |  |              |
     *  1        n  1  2             l-n
     *           p1    倒数n          倒数1
     *
     *
     *  o--o--o--o--o--o--o--o--o--o--o
     *  |        |  |  |              |
     *  1    l-n-1 l-n l-n+1
     *  p2              倒数n          倒数1
     *
     *
     *  2. 走了多少步要小心，否则很容易出错
     */
    ListNode *nthToLast(ListNode *head, int n) {

        ListNode* p1 = head;
        // 扫描到n的位置，就需要移动n-1次（从head开始）
        for (int i = 0; i < n-1 && p1; i++) {
            p1 = p1->next;
        }
        if (p1 == NULL) {
            return NULL;
        }

        ListNode* p2 = head;
        while (p1->next) { //表示p1移动到最后节点，如果是while(p1)表示p1移动到空节点
            p2 = p2->next;
            p1 = p1->next;
        }

        return p2;


    }
};


