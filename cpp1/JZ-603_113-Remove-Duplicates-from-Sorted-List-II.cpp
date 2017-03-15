/*Remove Duplicates from Sorted List II

Description
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

Example
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.*/

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

class Solution_1 {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     *
     * 使用dummyHead的实现更简洁，不容易出错。
     * 注意：所有duplicates都不保留
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL) return head;

        //增加dummy节点，因为list head 可能会变（比如是duplicated被删除）。
        ListNode dummyHead(0);
        dummyHead.next = head;

        ListNode* pCur = &dummyHead;

        while(pCur->next && pCur->next->next)
        {
            //不是duplicate，pCur继续后移
            if(pCur->next->val != pCur->next->next->val){
                pCur = pCur->next;
            }else{
                int val = pCur->next->val;
                //是duplicated，连续删除直到非duplicated节点
                while(pCur->next && pCur->next->val == val){
                    pCur->next = pCur->next->next;
                }
            }
        } //end while
        return dummyHead.next;
    }
};

class Solution_2 {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     *
     * 另一种写法，和上面差不多（比上面稍稍简洁些）
     */
    ListNode * deleteDuplicates(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* cur_node = head;
        ListNode* pre_node = &dummy;
        while (cur_node) {
            int cur_val = cur_node->val;
            // 判断是否重复节点
            if (cur_node->next && cur_node->next->val == cur_val) {
                // 连续删除重复节点
                while (cur_node && cur_node->val == cur_val) {
                    //delete cur_node
                    pre_node->next = cur_node->next;
                    cur_node = cur_node->next;
                }
            } else { // 不是重复节点，pointer move forward
                pre_node = cur_node;
                cur_node = cur_node->next;
            }
        } //end while
        return dummy.next;
    }
};
