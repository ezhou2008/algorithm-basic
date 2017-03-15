/*Swap Two Nodes in Linked List

Description
Given a linked list and two values v1 and v2. Swap the two nodes
in the linked list with values v1 and v2. It's guaranteed there is
no duplicate values in the linked list. If v1 or v2 does not exist
in the given linked list, do nothing.

Notice
You should swap the two nodes with values v1 and v2.
Do not directly swap the values of the two nodes.

Example
Given 1->2->3->4->null and v1 = 2, v2 = 4.

Return 1->4->3->2->null.*/

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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     *
     * 注意事项：
     *      1. 需要dummy head，因为head可能会改变
     *      2. v1 和 v2 出现的顺序不确定，可能是v1,v2 也可能是v2,v1,所有需要调整顺序
     *      3. v1 和 v2可能相邻
     *         两种情况分别处理: 相邻和不相邻
     *      4. v1 or v2 may not exits
     *
     *
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode dummy(0);
        dummy.next = head;

        ListNode* pre_v1 = NULL, *pre_v2 = NULL;
        ListNode* node_v1 = NULL, *node_v2 = NULL;
        head = &dummy;
        while (head->next) {
/*
            先找的节点定义为v1，后找的节点定义为v2，这样就不用调整顺序了
*/
            if (head->next->val == v1 || head->next->val == v2) {
                if (node_v1 == NULL) {  // 只有v1找到了
                    pre_v1 = head;
                    node_v1 = pre_v1->next;
                } else { // v1和v2均找到
                    pre_v2 = head;
                    node_v2 = pre_v2->next;
                    break;
                }
            }
            head = head->next;
        }

        // if v1 or v2 not exits, do nothing
        if( !node_v1 || !node_v2) {
            return dummy.next;
        }

        // printf("pre_v1 = %d, v1 = %d, pre_v2 = %d, v2 = %d\n",
        //     pre_v1->val, node_v1->val, pre_v2->val, node_v2->val);


        if (node_v1->next == node_v2) { // v1和v2相邻
            pre_v1->next = node_v2;
            ListNode* v2_next = node_v2->next;
            node_v2->next = node_v1;
            node_v1->next = v2_next;
        } else { // v1和v2不相邻
            pre_v1->next = node_v2;
            ListNode* v2_next = node_v2->next;
            node_v2->next = node_v1->next;
            pre_v2->next = node_v1;
            node_v1->next = v2_next;
        }
        return dummy.next;
    }
};