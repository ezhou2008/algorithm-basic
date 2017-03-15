/*3Sum Closest

Description
Given an array S of n integers, find three integers in S
such that the sum is closest to a given number, target.
Return the sum of the three integers.

Notice
You may assume that each input would have exactly one solution.

Example
For example, given array S = [-1 2 1 -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Challenge
O(n^2) time, O(1) extra space

Tags
Two Pointers Sort Array*/


class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int N = nums.size();
        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;
        int sum_3 = INT_MAX;

        for ( int i=0; i<=N-3; i++) {
            int left = i+1;
            int right = N-1;
            int cur_t = target - nums[i];
            while (left < right) {
                // printf("i= %d, left = %d, right = %d\n", i,left,right);
                int cur_sum_3 = nums[i]+nums[left]+nums[right];
                if (abs(cur_sum_3-target) < min_diff) {
                    min_diff = abs(cur_sum_3-target);
                    sum_3 = cur_sum_3;
                }
                if (nums[left] + nums[right] == cur_t) {
                    return target;
                } else if (nums[left] + nums[right] < cur_t) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return sum_3;
    }
};
