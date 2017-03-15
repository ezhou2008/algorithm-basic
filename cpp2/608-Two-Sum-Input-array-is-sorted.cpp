/*
Two Sum - Input array is sorted

Description
        Notes
Testcase
        Judge
Given an array of integers that is already sorted in ascending order,
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that
they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2)
are not zero-based.

Notice

        You may assume that each input would have exactly one solution.

Have you met this question in a real interview? Yes
        Example
Given nums = [2, 7, 11, 15], target = 9
return [1, 2]

Tags
        Two Pointers Hash Table Array Amazon
*/

class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> result(2,-1);
        int left =0;
        int right = nums.size()-1;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                result[0] = left+1;
                result[1] = right+1;
                break;
            } else if( nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
