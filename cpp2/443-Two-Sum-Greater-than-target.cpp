/*
Two Sum - Greater than target

        Description
Notes
        Testcase
Judge
Given an array of integers, find how many pairs in the array
such that their sum is bigger than a specific target number.
Please return the number of pairs.

Have you met this question in a real interview? Yes
        Example
Given numbers = [2, 7, 11, 15], target = 24. Return 1.
(11 + 15 is the only pair)

Challenge
        Do it in O(1) extra space and O(nlogn) time.

Tags
        Two Pointers Sort
*/


class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     *
     * 不考虑重复
     *
     */
    int twoSum2(vector<int> &nums, int target) {
        // Write your code here
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;

        int p_count = 0;
        while (left < right) {
            if (nums[left] + nums[right] <= target) {
                left++;
            } else {
/*                // leftside重复保留一个
                int cur_val = nums[left];
                while (nums[left+1] == cur_val) {
                    left++;
                }
                // right side 重复不保留
                int cur_val = nums[right];
                while (nums[right] == cur_val) {
                    right--;
                }
                p_count +=(right+1-left);*/


                p_count +=(right-left);
                right--;
            }
        }
        return p_count;
    }
};
