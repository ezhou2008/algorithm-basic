/*Wood Cut

Description

Given n pieces of wood with length L[i] (integer array).
Cut them into small pieces to guarantee you could have equal
or more than k pieces with the same length. What is the longest
length you can get from the n pieces of wood? Given L & k,
return the maximum length of the small pieces.

Notice

You couldn't cut wood into float length.

If you couldn't get >= k pieces, return 0.

Example
For L=[232, 124, 456], k=7, return 114.

Challenge
O(n log Len), where Len is the longest length of the wood.
*/

class Solution {
public:
    //max number of pieces that L can be cut into(each pieces is cut_len length)
    //零头不算
    int get_pieces(vector<int> &L, int cut_len) {
        int ret = 0;
        for (int i=0; i<L.size(); i++) {
            ret += L[i]/cut_len;
        }
        return ret;
    }

    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     *
     *
     * 要点:
     * 1. 要找到最大的length当然是切的越少越好，但是要满足>=k pieces
     * 2. 是用二分法，从最大的length开始search，找到第一个满足  >=k pieces的 length
     *
     * get the last len that could result in >=k pieces cut
     */
    int woodCut(vector<int> L, int k) {

        int max_len = INT_MIN;
        for (int i=0; i<L.size(); i++) {
            max_len = max(max_len, L[i]);
        }

        int start = 1;
        int end = max_len;

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            // k对于start，mid, end而已是降序
            // ==k继续向后寻最后的＝k(可能有更大的len)
            // >k 需要向后需要更小的>=k的值（更大的lenth)
            // <k 需要向前找大的k（小些的length）
            if (get_pieces(L,mid) >= k) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (get_pieces(L, end) >= k) return end;
        if (get_pieces(L, start) >= k) return start;

        return 0;
    }
};