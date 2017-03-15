/*Remove Nth Node From End of List

Description
Given a linked list, remove the nth node from the end of list and return its head.

Notice
The minimum number of nodes in list is n.

Example
Given linked list: 1->2->3->4->5->null, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5->null.

Challenge
Can you do it without getting the length of the linked list?*/


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
class Solution_traditional {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     *
     * A. 一般人能想到的方案
     * 两次遍历
     * 1. 先找出list的长度
     * 2. 再找nth element
     *
     * B. 由于head可能被删除，所以增加dummy head，这样处理起来方便简洁
     * c. 要删一个节点，只要找到其前驱节点即可
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {

        // dummy -> head -> 1 -> 2

        ListNode dummyNode(0);

        dummyNode.next = head;

        ListNode* curNode = &dummyNode;
        int list_len = 0;
        while (curNode->next) {
            list_len++;
            curNode = curNode->next;
        }

        if (list_len < n) {
            return dummyNode.next;
        }

        curNode = &dummyNode;
        for (int i = 0; i < list_len-n; i++) {
            curNode = curNode->next;
        }

//        curNode指向target node的前驱节点
        curNode->next = curNode->next->next;

        return dummyNode.next;

    }
};


class Solution_new {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     *
     * A. 一般人想不到的办法：
     *
     *     题意：删除链表中倒数第n个结点，尽量只扫描一遍。
     *  使用两个指针扫描，当第一个指针扫描到第N个结点后，
     *  第二个指针从表头与第一个指针同时向后移动，
     *  当第一个指针指向空节点时，另一个指针就指向倒数第n个结点了
     *
     *
     *  d->1->2->3..n....x->NULL
     *     p2       p1
     *         p2          p1=NULL
     *   p1 移动过list_len-n位置到list尾部
     *   p2 的位置为list_len-n位置，即倒数n个位置
     *
     * B. 由于head可能被删除，所以增加dummy head，这样处理起来方便简洁
     * c. 要删一个节点，只要找到其前驱节点即可
     *
     * */
    ListNode *removeNthFromEnd(ListNode *head, int n) {

        ListNode dummyNode(0);

        dummyNode.next = head;

        ListNode* p1 = &dummyNode;
        for (int i = 0; i < n && p1; i++) {
            p1 = p1->next;
        }
        //p1 points to nth element if exits
        if ( p1 == NULL ) { // p1 == NULL意味着list的长度<n
            return dummyNode.next;
        }
        // move one step so that p2 points to the element before target
        // p1多走一步，p2就少走一步
        p1 = p1->next;

        ListNode* p2 = &dummyNode;
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;

        }
        // p2 指向"nth node from the end"的前驱节点
        p2->next = p2->next->next;

        return dummyNode.next;

    }


};



