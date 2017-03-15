/*Partition Array II

Description

        Partition an unsorted integer array into three parts:

        The front part < low
        The middle part >= low & <= high
        The tail part > high
        Return any of the possible solutions.

Notice

        low <= high in all testcases.

Have you met this question in a real interview? Yes
        Example
Given [4,3,4,1,2,3,1,2], and low = 2 and high = 3.

Change to [1,1,2,3,2,3,4,4].

([1,1,2,2,3,3,4,4] is also a correct answer, but [1,2,1,2,3,3,4,4] is not)

Challenge
Do it in place.
Do it in one pass (one loop).

Related Problems
Medium Sort Colors 35 %
Medium Partition Array*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @param low an integer
     * @param high an integer
     * @return nothing
     */
    void partition2(vector<int>& nums, int low, int high) {
        // Write your code here
        int left = 0;
        int mid = 0;
        int right = nums.size()-1;
        while (mid <= right) {
            if (nums[mid] < low) {
                swap(nums[left], nums[mid]);
                left++; mid++;
            } else if (nums[mid] >= low && nums[mid] <= high) {
                mid++;
            } else {
                swap(nums[right], nums[mid]);
                right--;
            }
        }
        return;
    }
};