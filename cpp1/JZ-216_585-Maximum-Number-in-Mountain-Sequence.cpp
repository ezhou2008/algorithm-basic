/*Maximum Number in Mountain Sequence

Description
Given a mountain sequence of n integers which increase firstly
and then decrease, find the mountain top.

Example
Given nums = [1, 2, 4, 8, 6, 3] return 8
Given nums = [10, 9, 8, 7], return 10
*/


class Solution {
public:
    /**
     * @param nums a mountain sequence which increase firstly and then decrease
     * @return then mountain top
     *
     * 基本同find peak element
     * 不同的是，需要考虑单向下降和单向上升的情况
     */
    int mountainSequence(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        // if (nums.size() == 2) {
        //     return max(nums[0],nums[1]);
        // }

        int start = 0;
        int end = nums.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            // if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            //     return nums[mid];
            // }
            if (nums[mid] < nums[mid-1]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        printf("s[%d]= %d , e[%d]= %d\n", start, nums[start], end, nums[end]);
        if (nums[start] >= nums[end]) {
            return nums[start];
        } else {
            return nums[end];
        }
    }
};