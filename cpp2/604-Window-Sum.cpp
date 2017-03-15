/*Window Sum

Description
        Notes
Testcase
        Judge
Given an array of n integer, and a moving window(size k),
move the window at each iteration from the start of the array,
find the sum of the element inside the window at each moving.

Have you met this question in a real interview? Yes
        Example
For array [1,2,7,8,5], moving window size k = 3.
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20
return [10,17,20]

Tags
        Amazon
Related Problems*/

class Solution {
public:
    /**
     * @param nums a list of integers.
     * @return the sum of the element inside the window at each moving
     */
    vector<int> winSum(vector<int> &nums, int k) {
        vector<int> result;
        if (k==0 && nums.size()==0) {
            return result;
        }

        int sum = 0;
        if (k>nums.size()) {
            k = nums.size();
        }
/*
        注意边界
*/
        for (int i=0; i<=nums.size()-k; i++) {
            if (i==0) {
                for (int j=0; j<k; j++) {
                    sum += nums[j];
                }
            } else {
                sum += (nums[i+k-1]-nums[i-1]);
            }
            result.push_back(sum);
        }  // end for
        return result;
    }
};
