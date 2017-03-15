/*Copy List with Random Pointer

Description
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.

Example
Challenge
Could you solve it with O(1) space?*/


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution_recommended {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     *
     * hash map方案
     * 1. 依次复制node，存储original node和copy node的mapping
     * 2. setup random pointer by looking up mapping table
     *
     */
    RandomListNode *copyRandomList(RandomListNode *head) {

        unordered_map<RandomListNode*, RandomListNode*> node_map;
/*
        1. 依次复制node，存储original node和copy node的mapping
*/

        RandomListNode dummy(0);
        RandomListNode *cur_copy = &dummy;
        RandomListNode* head_bak = head;
        while (head) {
            cur_copy->next = new RandomListNode(head->label);
            node_map[head] = cur_copy->next;
            head = head->next;
            cur_copy = cur_copy->next;
        }
/*
        2. setup random pointer by looking up mapping table
*/
        head = head_bak;
        while (head) {
            if (head->random) {
                node_map[head]->random = node_map[head->random];
            }
            head = head->next;
        }

        return dummy.next;
    }
};


class Solution_tricky {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     *
     * 使用 tricky 方案[O(1) space]
     *
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        /***
            1. copy list and insert it in original list
                1---1'---2---2'---3---3'----
            2. fix random pointer of nodes in copied nodes since all nodes are now ready
            3. detach copied list from original list
        ***/
        //step 1 copy list and insert it in original list

        //save head pointer for further reference
        RandomListNode* head_bak = head;
        while(head){
            //clone current node
            RandomListNode* p_new = new RandomListNode(head->label);
            //insert copied node in head and head->next
            p_new->next = head->next;
            head->next = p_new;

            //pointer move 2 step forward
            head = head->next->next;
        }//end while(head)

        //step 2 fix random pointer of nodes in copied nodes since all nodes are now ready
        head = head_bak;
        while (head) {
            if(head->random) {
                head->next->random = head->random->next;
            }
            //pointer move 2 step forward
            head = head->next->next;
        }

        //step 3 detach copied list from original list
        //1---1'---2---2'---3---3'----
        RandomListNode dummy_h(INT_MIN);
        RandomListNode* pRes = &dummy_h;
        head = head_bak;
        while(head){
            //attach copied node to result list
            pRes->next = head->next;

            //detach copied node
            head->next = head->next->next;

            //both pointers move 1 step forward
            head = head->next;
            pRes = pRes->next;
        }

        //retunr
        return dummy_h.next;
    }
};