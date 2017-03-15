/*
Two Sum - Less than or equal to target

        Description
Given an array of integers, find how many pairs in the array
such that their sum is less than or equal to a specific target
number. Please return the number of pairs.

Have you met this question in a real interview? Yes
        Example
Given nums = [2, 7, 11, 15], target = 24.
Return 5.
2 + 7 < 24
2 + 11 < 24
2 + 15 < 24
7 + 11 < 24
7 + 15 < 25

Tags
        Two Pointers Sort
*/


class Solution {
public:
    /**
     * @param nums an array of integer
     * @param target an integer
     * @return an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int p_count = 0;

        sort(nums.begin(), nums.end());

        while (left<right) {
            if (nums[left] + nums[right] <= target) {
                p_count += (right-left);
                left++;
            } else {
                right--;
            }
        }
        return p_count;
    }
};
