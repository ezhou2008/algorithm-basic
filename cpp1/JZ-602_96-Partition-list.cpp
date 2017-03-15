/*Partition List

Description
Given a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example
Given 1->4->3->2->5->2->null and x = 3,
return 1->2->2->4->3->5->null.*/

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
     * @param x: an integer
     * @return: a ListNode
     *  1. 使用连个链表头，分别将>=x 和 <x的节点串起来
     *  2. 最后将两个链表接起来即可
     */
    ListNode *partition(ListNode *head, int x) {

        //使用两个临时链表，一个将>=x的节点串起来，一个将<x的节点串起来
        //最后将两个链表接起来即可。
        ListNode leftDummy(0);
        ListNode rightDummy(0);
        //这里做法很巧妙，见下面注释
        ListNode *pLeft = &leftDummy;
        ListNode *pRight = &rightDummy;

        while(head){
            if (head->val >=x){
                //这里做法很巧妙，第一个>=x节点将由rightDummy标记
                //后续>=x节点由pRight移动跟踪
                //这种方法不需要专门标记是否是第一个>=x的节点
                pRight->next = head;
                pRight = head;
            }else{
                pLeft->next = head;
                pLeft = head;
            }
            head = head->next;
        }
        pLeft->next = rightDummy.next;
        //必须设为null，否则可能会变成循环链表
        pRight->next = NULL;

        return leftDummy.next;
    }
};


