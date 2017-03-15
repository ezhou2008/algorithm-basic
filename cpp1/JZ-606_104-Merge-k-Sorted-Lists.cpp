/*Merge k Sorted Lists

Description
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.

Example
Given lists:

[
2->4->null,
null,
-1->null
],
return -1->2->4->null.*/

class MinHeap {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     *
     * min-heap 方案
     *
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        //base cases
        if (lists.size() == 0) return NULL;
        //result
        ListNode dummyHead(INT_MIN);
        ListNode* pCur = &dummyHead;

        // put list heads in a container( list/vector/min-heap)
        // 由于list node有next指针，所以只需存储list node 即可
        // (如果是array的话，JZ-803_486-Merge-k-Sorted-Arrays.cpp，就需要辅助的数据结构来保存next关系
        // priority default to max-heap, to define min-heap use greater-than comparator
        auto ListNode_cmp = [](const ListNode* n1, const ListNode* n2)
        {return n1->val > n2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(ListNode_cmp)> min_heap(ListNode_cmp);
        for (ListNode* list_head : lists){
            if (list_head){
                min_heap.push(list_head);
            }
        }
        //go through the container until empty,
        //1. found the min, put it in result,
        //2. delete it from container,
        //   add its next to container
        while(!min_heap.empty()){
            //find the min,put it in result
            ListNode* p_tmp = min_heap.top();
            pCur->next = p_tmp;
            pCur = pCur->next;
            //delete min from container and add its next
            min_heap.pop();
            if (p_tmp->next) min_heap.push(p_tmp->next);
        }
        //just in case
        pCur->next = NULL;

        //return result
        return dummyHead.next;
    }
};

class DivideConquer {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     *
     * 分治法方案
     *
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return merge_k_helper( lists, 0, lists.size()-1 );
    }
    //merge lists[start, end]
    ListNode* merge_k_helper(vector<ListNode*> lists,int start, int end) {
        /*
        base cases
        */
        if (lists.empty()) return NULL;
        if (start >= lists.size() || end >= lists.size()) return NULL;
        if (start > end) return NULL;
        if (start == end) return lists[start];

        /*
        split lists into two and merge
        */
        int mid = start + (end-start)/2;
        ListNode* left = merge_k_helper(lists, start, mid);
        ListNode* right = merge_k_helper(lists, mid+1, end);

        /*
        merge two
        */
        //result list head
        ListNode dummyHead(INT_MIN);
        ListNode* pCur = &dummyHead;

        while(left && right){
            if (left->val < right->val) {
                pCur->next = left;
                left = left->next;
            }else {
                pCur->next = right;
                right = right->next;
            }
            pCur = pCur->next;
        }
        while( left ) {
            pCur->next = left;
            pCur = pCur->next;
            left = left->next;
        }
        while( right ) {
            pCur->next = right;
            pCur = pCur->next;
            right = right->next;
        }
        pCur->next = NULL;

        //return result
        return dummyHead.next;
    }
};

class MergeTwo {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     *
     * list两两合并方案
     *
     */
    //merge two lists
    ListNode* merge_two(ListNode* left, ListNode* right) {
        //base cases
        if (left == NULL) return right;
        if (right == NULL) return left;

        //result list head
        ListNode dummyHead(INT_MIN);
        ListNode* pCur = &dummyHead;

        while(left && right){
            if (left->val < right->val) {
                pCur->next = left;
                left = left->next;
            }else {
                pCur->next = right;
                right = right->next;
            }
            pCur = pCur->next;
        }
        while( left ) {
            pCur->next = left;
            pCur = pCur->next;
            left = left->next;
        }
        while( right ) {
            pCur->next = right;
            pCur = pCur->next;
            right = right->next;
        }
        pCur->next = NULL;

        //return result
        return dummyHead.next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        //base cases
        if (lists.size() == 0) return NULL;

        //merge by two
        int K = lists.size();
        while ( K>1 )
        {
            vector<ListNode*> cur_lists;

            for (int i=0; i<K; i+=2){
                if ( i+1<K ) {
                    cur_lists.push_back( merge_two(lists[i], lists[i+1]) );
                }
            }
            if (K%2 !=0){
                cur_lists.push_back( lists[K-1] );
            }

            //update K(List size)
            lists = move(cur_lists);
            K = lists.size();
        }
        return lists[0];
    }

};