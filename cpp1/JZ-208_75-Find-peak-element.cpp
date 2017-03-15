/*Find Peak Element

Description

There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].

We define a position P is a peek if:
A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.

The array may contains multiple peeks, find any of them.

Example
Given [1, 2, 1, 3, 4, 5, 7, 6]

Return index 1 (which is number 2) or 6 (which is number 7)

Challenge
Time complexity O(logN)
*/


class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     *
     * 保留有解的一边
     * 分四种情况：
     * 1. 下坡，peak在mid左边
     * 2. 上坡，peak在mid右边
     * 3. 谷底，peak在两边都有（为简化代码，选择左边，同1）
     * 3. peak，直接返回（或者同2也可以）
     *
     *
     */
    int findPeak(vector<int> A) {
        if (A.size() == 0) return -1;
/*        注意：start和end不可能是第一个和最后一个，因为条件是
        "A[0] < A[1] && A[A.length - 2] > A[A.length - 1]."
        而且：代码里有A[mid-1]和A[mid+1]，也必须排除第一个和最后一个
*/
        int start = 1;
        int end = A.size() - 2;

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
//            peak直接返回
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) {
                return mid;
            }
//            下坡或者谷底
            if (A[mid] < A[mid-1]) {
                end = mid;
            } else { // 上坡
                start = mid;
            }
        }

/*        也可以是下面条件：
 *        if (A[start] > A[start-1] && A[start] > A[start+1]) {
*/
        if (A[start] > A[end]) {
            return start;
        } else {
            return end;
        }

    }
};
