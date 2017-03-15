/*
Move Zeroes

Description
Given an array nums, write a function to move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

Notice

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Have you met this question in a real interview? Yes
Example
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should
be [1, 3, 12, 0, 0].

Tags
        Two Pointers Array
Related Problems
Easy Remove Element
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here

/*        int p_nz = 0;  // pointers to next non-zero
        int left = 0;
        while (left < nums.size()) {
            if (nums[left] != 0) {
                swap(nums[left], nums[p_nz++]);
            }
            left++;
        }*/

        int p_nz = -1;  // pointers to last non-zero
        int left = 0;
        while (left < nums.size()) {
            if (nums[left] != 0) {
                swap(nums[left], nums[++p_nz]);
            }
            left++;
        }
    }
};

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here

        int p_nz = 0;

        for (int i=0; i<nums.size();i++) {
            if (nums[i] !=0 ) {
                swap(nums[i], nums[p_nz++]);
            }
        }
    }
};

