/*Given a singly linked list, find middle of the linked list.
For example, if given linked list is 1->2->3->4->5 then output should be 3.

If there are even nodes, then there would be two middle nodes,
we need to print first middle element.
For example, if given linked list is 1->2->3->4->5->6 then output should be 4.
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
class Solution_tmplate_记住{
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     *
     * 1. 模版，一定记住
     * 2. 一次遍历
     *      使用快慢指针，快指针一次走2步，慢指针一次1步，快指针到尾部(or NULL)的话，慢指针就指向middle
     * 4. 链表个数为奇数的话，只有一个midlle，偶数的话，有两个middle（first，second middle）
     * 5. 方法1（本solution）
     *    slow pointer 从head开始,
     *    fast pointer 从head－>next同时开始，
     *    2.1. fast到list尾部或者为null时，此时slow指向middle或者first middle
     *    2.2  最后fast指针为null －> list的个数为奇数过，slow指向middle
     *         最后fast为尾部（fast->next＝＝null） －> list的个数为偶数，slow指向first middle
     *    2.3 e.g.
     *      1        = 1  ->最后fast points to NULL
     *      1,2      = 1  ->最后fast points to last node
     *      1,2,3    = 2  ->最后fast points to NULL
     *      1,2,3,4  = 2  ->最后fast points to last node
     *      1,2,3,4,5 =3  ->最后fast points to NULL
     * 5. 方法2（下面solution，这个方法的结论＊＊＊＊＊一定要记住＊＊＊＊＊＊，其它的需要根据这个结论调整）
     *    slow和fast都从head开始的话，最后返回的就是middle或者second middle
     *    最后fast==NULL -> list length == even
     *       fast pointes to list end -> list len == odd
     * 6. 根据需要选择上面两种方法，或者调整slow和fast的相对位置.
     *    ******优选选first middle******
     */
    ListNode *middleNode(ListNode *head) {
        if (head == NULL) return head;

/*
        注意：fast 从head－>next开始, 到指向最后一个节点
*/
        ListNode* slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


class Solution{
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     *
     * 一次遍历
     *      使用快慢指针，快指针一次走2步，慢指针一次1步，快指针到尾部的话，慢指针就指向middle
     * slow和fast都从head开始
     *
     */
    ListNode *middleNode(ListNode *head) {
        if (head == NULL) return head;

        ListNode *p1 = head, *p2 = head;

        while (p1->next && p2->next) {
            p1 = p1->next;
            if (p1->next) {
                p1 = p1->next;
            } else {
                break;
            }
            p2 = p2->next;
        }

        return p2;

    }
};

class Solution{
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     *
     * 两次遍历
     *      先计算list长度，再从头移动到midlle
     *
     */
    ListNode *middleNode(ListNode *head) {
        if (head == NULL) return head;

        ListNode* pCur = head;

        int list_len = 0;
        while (pCur) {
            list_len++;
            pCur = pCur->next;
        }

        pCur = head;
        int middle = (list_len+1)/2;
//        int middle = list_len/2 + list_len%2;
        for( int i = 0; i < middle-1; i++) {
            pCur = pCur->next;
        }

        return pCur;

    }
};

