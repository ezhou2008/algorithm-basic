/*Remove duplicates from an unsorted linked list
Write a removeDuplicates() function which takes a list
and deletes any duplicate nodes from the list. The list is not sorted.

For example if the linked list is 12->11->12->21->41->43->21
then removeDuplicates() should convert the list to 12->11->21->41->43.*/

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
     * @return: head node
     *
     * 方案：
     *      使用hash table来确定节点是否是duplicate
     * 另外：
     *      1. 使用dummy head，因为真正的head可能被删除
     *      2. 要删除一个节点，只要找到其前驱节点即可
     *
     * 另外：最直观的方案就是对于每个节点，扫描整个list找出其duplicat
     *
     * 注意：每种duplicates保留一个
     */
    ListNode *removeDuplicates(ListNode *head) {
        //1. sort, then traversal
        //2. using hash_table

        ListNode dummy(INT_MAX);
        dummy.next = head;

        unordered_set<int> node_val_hash;

        ListNode* pCur = &dummy;
        while (pCur->next) {
            if (node_val_hash.find(pCur->next->val) != node_val_hash.end()) {
                // duplicates found for pCur->next, remove it from list
                pCur->next = pCur->next->next;
            } else {
                // not found, insert to hash table
                node_val_hash.insert( pCur->next->val );
                // pcur move on
                pCur = pCur->next;
            }
        }

        return dummy.next;
    }
};

