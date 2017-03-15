/*Delete Node in the Middle of Singly Linked List

Description
Implement an algorithm to delete a node in the middle of
a singly linked list, given only access to that node.

Example
Given 1->2->3->4, and node 3. return 1->2->4*/
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     *
     * 方案：
     * 由于singly linked list没法后退，所有办法是将next的值赋给要删除的节点，然后删除next节点
     *
     */
    void deleteNode(ListNode *node) {

        if (node == NULL) {
            return;
        }
        // node->next肯定存在，因为node to be deleted is in the middle of list
        if (node->next) {
            // value of next node assigned to node to be deleted
            node->val = node->next->val;
            // delete next node
            node->next = node->next->next;
        }
    }
};