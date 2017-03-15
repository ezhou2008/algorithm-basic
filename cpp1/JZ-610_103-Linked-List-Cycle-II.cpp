/*Linked List Cycle II

Description
Given a linked list, return the node where the cycle begins.

If there is no cycle, return null.

Example
Given -21->10->4->5, tail connects to node index 1，return 10

Challenge
Follow up:
Can you solve it without using extra space?*/

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

class Solution_推荐 {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     *
     *  此方案容易记住
     *
     *  使用快慢指针
     *
     *  A               B
     *  o---o---o---o---o---o---o---o
     *                  |            |
     *                  |            |
     *                  o ---o---o---o
     *                           C
     *  1. fast and slow meet at point C
     *  2. slow pointer move along to count the number of nodes of the circle(suppose it is K)
     *  3. find the Kth node from end
     *     2nd pointer move to Kth node from head
     *     1th pointer and 2nd pointer moves the same time until 2nd->next = 1nd
     *     寻找倒数k个节点的变形(假想在b的位置断开list)
     *          基本的题目时前面的指针到list的尾部（2nd->next == NULL)，
     *          这里是环形，假想在b的位置断开list，判断尾部的条件就改成
     *              2nd->next = 1nd
     *
     *
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

/*
判读是否有环
*/

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            if (fast == slow) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        // 没有环（fast到达尾部，或者为null）
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
/*
计算环的长度
*/
        int circle_len = 1;
        ListNode* cur_node = slow->next;
        while (cur_node != slow) {
            circle_len++;
            cur_node = cur_node->next;
        }
/*
找倒数k个节点即是环的起始点，k为环的长度，
*/
        ListNode* p1 = head, *p2 = head;
        for (int i = 0; i < circle_len-1; i++) {
            p2 = p2->next;
        }
        while (p2->next != p1) {
            p2 = p2->next;
            p1 = p1->next;
        }

        return p1;
    }
};




class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     *  此方案比较tricky
     *
     *  使用快慢指针
     *
     *  A               B
     *  o---o---o---o---o---o---o---o
     *                  |            |
     *                  |            |
     *                  o ---o---o---o
     *                           C
     *  fast pointer and slow pointer meet at point C
     *  fast pointer 走过的距离为：df = AB + BC + CB + BC
     *  slow pointer 走过的距离为：ds = AB + BC
     *  df = 2*ds -> AB + BC + CB + BC = 2*AB + 2*BC -> AB = CB
     *  也就是相遇后，同时从A 和 C 点出发，相遇点极为cycle的起始点
     *
     *  如果fast指针从A->next开始，-> df -1 = 2*ds -> CB = AB +1
     *  也就是说CB比AB要长1，如果pointer1和pointer2分别从A和C同时开始走的话，
     *  当pointer1到B时,pointer2在B前一个位置（位于BC上）
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            if (fast == slow) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // 注意时slow->next, 因为距离差1，见前面方案解释
        while (head != slow->next) {
            slow = slow->next;
            head = head->next;
        }
        return head;

    }
};


class Solution_hash_table {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     *
     * 此方案容易想到，但需要额外空间
     *
     *
     * 1. 遍历list，同时将节点存入hash table,
     *    如果发现当前访问的节点在hash table里，就是此节点为环的开始
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        unordered_set<ListNode*> node_hash;

        while (head) { // 前提是必须有环，否则while无法退出
            if (node_hash.find(head) != node_hash.end()) {
                return head;
            } else {
                node_hash.insert(head);
                head = head->next;
            }
        }
        return NULL;
    }
};
