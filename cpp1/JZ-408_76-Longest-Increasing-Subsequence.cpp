/*Longest Increasing Subsequence

Description
Given a sequence of integers, find the longest increasing subsequence (LIS).

You code should return the length of the LIS.

Clarification
What's the definition of longest increasing subsequence?

The longest increasing subsequence problem is to find
a subsequence of a given sequence in which the subsequence's
elements are in sorted order, lowest to highest, and in
which the subsequence is as long as possible.
This subsequence is not necessarily contiguous, or unique.

https://en.wikipedia.org/wiki/Longest_increasing_subsequence

Example
For [5, 4, 1, 2, 3], the LIS is [1, 2, 3], return 3
For [4, 2, 4, 5, 3, 7], the LIS is [2, 4, 5, 7], return 4

Challenge
Time complexity O(n^2) or O(nlogn)
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     *
     * 基本思想：
     * 1. 定义lis(i)为包括i在内的longest increasing subsequnce（local意义上的LIS)
     * 2. 计算lis(i)
     *    和i前面位置的数nums(j)逐一比较，看是否能组成lis，不行的话，就取值1
     *    lis(i) = max{ 1, max[lis(j)+1] } if nums(j) < nums(i) && j=0...i-1
     *
     * 3. 对所有i中找出最大
     *    不一定最后一个位置是最大的，所以需要在数组里挑最大的。
     *
     * 另外：也可以采用local／global的叫法，定义：
     *      g_lis(i)为i 位置的LIS(不一定包括i在内），则：
     *      g_lis(i) = max(lis(i),       =>包括i
     *                     g_lis(i-1)}   =>不包括i
     *      这个表达式实际也就是取lis(i)的最大值
     *
     *
     * e.g.
     *      nums = [1,4,5,6,2,3,0]
     *      LIS:
     *              lis("1")=1 ->{1},
     *              lis("4")=2 ->{1,4},
     *              lis("5")=3 ->{1,4,5}
     *              lis("6")=4 ->{1,4,5,6},
     *              lis("2")=2 ->{1,2},
     *              lis("3")=3 ->{1,2,3},
     *              lis("0")=1 ->{0}
     *       max = 4
     * 注意：
     * subsequence不需要连续
     */
    int longestIncreasingSubsequence(vector<int> nums) {

        if (nums.size() == 0) return 0;
        // state and init
        // 注意初始化为1，比较自然也方便
        vector<int> LIS(nums.size(), 1);

        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i]) { // 注意是<, 不是<=,也就是1，1，1这种不是increasing sequence
                    // 由于所有的都初始化为1，所以第一次肯定是LIS[J]+1大
                    LIS[i] = max(LIS[j]+1,LIS[i]);
                } // 如果没有满足条件的，LIS[i]就取初始化的值
                  // 如果有满足条件的值，最后结果肯定>1,1也就没有必要想下面递推公式里那样参与max
                  // lis(i) = max{ 1, max[lis(j)+1] } if nums(j) < nums(i) && j=0...i-1

            }
        }
/*
        找出最大者
*/
        return *max_element(LIS.begin(), LIS.end());
    }
};