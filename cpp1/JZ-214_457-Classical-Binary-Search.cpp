/*Classical Binary Search

Description
Find any position of a target number in a sorted array.
Return -1 if target does not exist.

Example
Given [1, 2, 2, 4, 5, 5].

For target = 2, return 1 or 2.

For target = 5, return 4 or 5.

For target = 6, return -1.

Challenge
O(logn) time
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

1. 如果target在里面，返回任意一个,start, end 的位置无规律
2. 如果target不在里面，
       在数组范围里：start,end分别指向<target(最后一个）和>target的位置（第一个）
       target比数组所有数都大：start，end指向数组最后两个数
       target比数组所有数都小：start，end指向数组前两个数
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here

        if (A.size() == 0 ) return -1;

        int start =0;
        int end = A.size() - 1;

        while ( start + 1 < end )  {
            int mid = start + (end-start)/2;
            if (target == A[mid]) {
                return mid;
            } else if (target < A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
/*        为什么还需要做下面的判断？
        因为前面while 循环是相邻退出，
        有种情况是，start和end中间有一个已经指向target，但是start和end相邻，
        所以没有机会进入到while循环里做判断
*/
        if (target == A[start]) return start;
        if (target == A[end]) return end;
        return -1;
    }
};