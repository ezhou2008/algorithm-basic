/*Two Sum - Unique pairs

Description
Given an array of integers, find how many unique pairs
in the array such that their sum is equal to a specific target number.
Please return the number of pairs.

Have you met this question in a real interview? Yes
        Example
Given nums = [1,1,2,45,46,46], target = 47
return 2

1 + 46 = 47
2 + 45 = 47*/
class Solution {
public:
    /**
     * @param nums an array of integer
     * @param target an integer
     * @return an integer
     */
    int twoSum6(vector<int> &nums, int target) {
        // Write your code here
        sort(nums.begin(), nums.end());

        int p_count = 0;
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                p_count++;

                // skip all duplicates...
                int cur_val = nums[left];
                while (nums[left] == cur_val) {
                    left++;
                }
                cur_val = nums[right];
                while (nums[right] == cur_val) {
                    right--;
                }

/*                left++;right--;
                while (nums[left] == nums[left-1]) {
                    left++;
                }
                while (nums[right] == nums[right+1]) {
                    right--;
                }*/

            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return p_count;
    }
};