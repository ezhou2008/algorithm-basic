/*Insert into a Cyclic Sorted List

Description
Given a node from a cyclic linked list which has been sorted,
write a function to insert a value into the list such that it
remains a cyclic sorted list. The given node can be any single
node in the list. Return the inserted new node.

Notice

3->5->1 is a cyclic list, so 3 is next node of 1.
3->5->1 is same with 5->1->3

Example
Given a list, and insert a value 4:
3->5->1
Return 5->1->3->4

Tags
Linked List Amazon
Related Problems
Easy Insertion Sort List*/


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
     * @param node a list node in the list
     * @param x an integer
     * @return the inserted new list node
     *
     * 技巧：
     * 1. 需要一个标示来识别链表是否遍历了一次，因为是循环的、
     * 2. 要考虑顺序和逆序
     *    由于起始点不一定，虽然list是sorted，但中间有部分不是sorted的（逆序）
     *    e.g。 3-->3-->5-->5-->1-->1-->2-->3
     *    其中：5-->1不是sorted的
     *
     *
     */
    ListNode* insert(ListNode* node, int x) {
        ListNode* new_node = new ListNode(x);
        if (node == NULL) {
            new_node->next = new_node;
            return new_node;
        }

        ListNode* cur = node;
        ListNode* cur_n = node->next;
        while (cur_n != node) {
            // 顺序
            if (cur->val <= cur_n->val) {
                if (x >= cur->val && x <= cur_n->val) {
                    break;
                }
            }
            // 逆序
            if (cur->val > cur_n->val) {
                if (x > cur->val || x < cur_n->val) {
                    break;
                }
            }
            cur = cur_n;
            cur_n = cur_n->next;
        }

        // 插入
        cur->next = new_node;
        new_node->next = cur_n;
        return new_node;
    }
};