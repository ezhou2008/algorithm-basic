/*Maximum Subarray V

Description
Given an integer arrays, find a contiguous subarray which
has the largest sum and length should be between k1 and k2
(include k1 and k2).
Return the largest sum, return 0 if there are fewer than k1
elements in the array.

Notice

Ensure that the result is an integer type.

Have you met this question in a real interview? Yes
Example
Given the array [-2,2,-3,4,-1,2,1,-5,3] and k1 = 2, k2 = 4,
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

Tags
        Subarray Array*/

class Solution {
public:
    /**
     * @param nums an array of integers
     * @param k1 an integer
     * @param k2 an integer
     * @return the largest sum
     * 要点
     * 1. prefix sum
     * 2. 滑动窗口
     * 3. 单调队列（双端）
     *
     */
    int maxSubarray5(vector<int>& nums, int k1, int k2) {
        // Write your code here
        int n = nums.size();
        if (n < k1)
            return 0;

        int result = INT_MIN;

        vector<int> sum(n + 1);
        sum[0] = 0;

/*      双端队列
        sliding window, 填入(i-k2,i-k1]间的数据）大小为k2-k1,用单调queue来实现，大小可能会<k2-k2)
        (i-k1, i]直接的k1个数据是必须要包含在subarray里，所以没必要放入队列
*/
        deque<int> queue;
        for (int i = 1; i <= n; ++i) {
            // 计算prefix sum
            sum[i] = sum[i - 1] + nums[i - 1];
            // 确认back位置的数和i距离不超过k2,否则从队列里删除(保证窗口大小）
            if (!queue.empty() && queue.back() < i- k2) {
                queue.pop_back();
            }
            // 窗口移动, push新元素到queue,prefix_sum数组排列：x----k2----k1----i
            if (i >= k1) { // subarray至少k1个元素
                // 单调递增队列, back(小)---front(大), front插入，back最小
                while (!queue.empty() && sum[queue.front()] > sum[i - k1]) {
                    queue.pop_front();
                }
                queue.push_front(i - k1);
            }

            // [i - k2, i - k1]
            // 计算i位置的最大subarray sum ＝ prefix_sum(i) - 窗口里最小的prefix_sum
            // 并更新result
            if (!queue.empty() && sum[i] - sum[queue.back()] > result) {
                result = max(result, sum[i] - sum[queue.back()]);
            }
        }
        return result;
    }
};