/*Sort List

Description
Sort a linked list in O(n log n) time using constant space complexity.

Example
Given 1->3->2->null, sort it to 1->2->3->null.

Challenge
Solve it by merge sort & quick sort separately.*/

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
class Solution_merge_sort {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
/*
        important： base cases
        null 或者一个节点直接返回
*/
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // find midlle(first middle)
        // 注意：不能是 second middle,
        // 反例：2->1->null, loop never end（divide无法结束）
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

/*        //divide: split list into to two */
        ListNode* left_l = head;
        ListNode* right_l = slow->next;
        //断开left部分， important
        slow->next = NULL;


/*        //conquer:*/
        left_l = sortList(left_l);
        right_l = sortList(right_l);

        return merge(left_l, right_l);

    }

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* curNode = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                // merge left to final list
                curNode->next = left;
                left = left->next;
            } else {
                // merge right to list
                curNode->next = right;
                right = right->next;
            }
            curNode = curNode->next;
        }
/*        下面别忘记了：肯定有一个先走到null, 另外一个剩余部分需添加 */
        if (left) {
            curNode->next =left;
//            left = left->next;
        }
        if (right) {
            curNode->next = right;
//            right = right->next;
        }

        return dummy.next;
    }
};


