/*
Maximum Subarray IV

Description
Given an integer arrays, find a contiguous subarray
which has the largest sum and length should be greater
or equal to given length k.
Return the largest sum, return 0 if there are fewer than
k elements in the array.

Notice
Ensure that the result is an integer type.

Example
Given the array [-2,2,-3,4,-1,2,1,-5,3] and k = 5,
the contiguous subarray [2,-3,4,-1,2,1] has the largest sum = 5.

Tags
        Subarray Array
*/


class Solution {
public:
    /**
     * @param nums an array of integers
     * @param k an integer
     * @return the largest sum
     *
     * 基本原理同maximum subarray
     *
     * 递推：
     * local_ms_k(i) = k_sum(i) + max(local_ms_1(i-k),0),
     *                  local_ms_1(i)为基本maximum subarray
     * g_ms_k(i) = max{g_ms_k(i-1), local_ms_k(i)}
     *
     * 要点：
     * subarray len = {k or k+(>=1)} = {k or >=k+1} = {>=k}
     *
     */
    int maxSubarray4(vector<int>& nums, int k) {
        // Write your code here
        int N = nums.size();
        if (N < k) {
            return 0;
        }

        // 计算k sum
        vector<int> k_sum(N,0);
        k_sum[0] = nums[0];
        for (int i=1; i<N; i++) {
            if (i < k) {
                k_sum[i] = k_sum[i-1] + nums[i];
            } else {
                k_sum[i] = k_sum[i-1] + nums[i] - nums[i-k];
            }
        }

        vector<int> lms(N,INT_MIN);
        lms[0] = nums[0];
        for (int i=1; i<N; i++) {
            lms[i] = nums[i] + max(lms[i-1], 0);
        }

        int gms = k_sum[k-1];
        for (int i=k; i<N; i++) {
/*          max取0，gms＝k_sum[i] 此时subarray len ＝k
            max取lms[i-k]，此时subarray len = k +(>=1) >=k+1*/
            gms = max(gms, k_sum[i] + max(lms[i-k],0));
        }
        return gms;
    }
};


class Solution {
public:
    /**
     * @param nums an array of integers
     * @param k an integer
     * @return the largest sum
     *
     * 基本同上：
     * 要点：
     * subarray len = {k-1+(>=1)} = {>=k}
     *
     */
    int maxSubarray4(vector<int>& nums, int k) {
        // Write your code here
        int N = nums.size();
        if (N < k) {
            return 0;
        }

        // 计算k-1 sum
        vector<int> k_sum(N,0);
        if (k>1) {
            k_sum[0] = nums[0];
        }
        for (int i=1; i<N; i++) {
            if (i < k-1) {
                k_sum[i] = k_sum[i-1] + nums[i];
            } else {
                k_sum[i] = k_sum[i-1] + nums[i] - nums[i-(k-1)];
            }
        }
/*        copy(k_sum.begin(), k_sum.end(),ostream_iterator<int>(cout,", "));
        cout << endl;*/

        vector<int> lms(N,INT_MIN);
        lms[0] = nums[0];
        for (int i=1; i<N; i++) {
            lms[i] = nums[i] + max(lms[i-1], 0);
        }
/*        copy(lms.begin(), lms.end(),ostream_iterator<int>(cout,", "));
        cout << endl;*/

        int gms = k_sum[k-1]+lms[0];
        for (int i=k; i<N; i++) {
/*
            subarray的长度为k-1 + (>=1) -> subarray len >=k
*/
            gms = max(gms, k_sum[i] + lms[i-(k-1)]);
            // printf("i= %d, gms = %d\n", i, gms);
        }
        return gms;
    }
};