/*Last Position of Target

Description
Find the last position of a target number in a sorted array.
Return -1 if target does not exist.

Example
Given [1, 2, 2, 4, 5, 5].

For target = 2, return 2.

For target = 5, return 5.

For target = 6, return -1.
*/



class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     *
     *
通用的二分法模板
1. start + 1 < end
2. start + (end - start) / 2
3. A[mid] ==, <, > (？target）
4. A[start] A[end] ? target

结果：
[1,4,4,5,7,7,8,9,9,10], 4

1. 如果target在里面，只有一个指针指向last index of target（start）
     (如果数组后两个为target的话，start，end指向这两个）
2. 如果target不在里面，
       在数组范围里：start,end分别指向<target(最后一个）和>target的位置（第一个）
       target比数组所有数都大：start，end指向数组最后两个数
       target比数组所有数都小：start，end指向数组前两个数
     */

    int lastPosition(vector<int>& A, int target) {
        if (A.size() == 0) return -1;

        int start = 0;
        int end = A.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (target == A[mid]) {
/* 继续向后寻找 */
                start = mid;
            } else if (target < A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
/* end的判断必须在start 前面 */
        if (A[end] == target) return end;
        if (A[start] == target) return start;

        return -1;
    }
};