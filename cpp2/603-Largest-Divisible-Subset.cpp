/*
Largest Divisible Subset

Description
Given a set of distinct positive integers, find the largest subset
such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.

Notice

If there are multiple solutions, return any subset is fine.

Example
Given nums = [1,2,3], return [1,2] or [1,3]

Given nums = [1,2,4,8], return [1,2,4,8]

Tags
        Dynamic Programming
*/


class Solution {
public:
    /**
     * @param nums a set of distinct positive integers
     * @return the largest subset
     * 要点：
     *      1. local/global概念
     *      2. 先sort以简化操作
     *      3. 记录max的路径，以便back tracking
     *         题目还要求输出最大的集合（不仅仅是数目）
     */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // 首先sort
        sort( nums.begin(), nums.end());

        // local largest set, 必须包括nums[i]
        vector<int> local_ls(nums.size(),1);
        // 记录前驱，以便back tracking
        vector<int> pre_idx(nums.size(),-1);

        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (local_ls[j]+1 > local_ls[i]) {
                        local_ls[i] = local_ls[j] + 1;
                        pre_idx[i] = j;
                    }
                }
            }
        }

        // 找出global最大，及其位置
        vector<int> result;
        int global_idx  = -1;
        int global_ls = INT_MIN;
        for (int i=0; i<nums.size();i++) {
            if (local_ls[i] >= global_ls) {
                global_ls = local_ls[i];
                global_idx = i;
            }
        }

        // backtracking 找出最大路径
        while (global_idx >= 0) {
            result.push_back(nums[global_idx]);
            global_idx = pre_idx[global_idx];
        }
        return result;
    }
};

