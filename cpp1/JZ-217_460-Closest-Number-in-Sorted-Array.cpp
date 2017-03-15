/*K Closest Numbers In Sorted Array

Description

Given a target number, a non-negative integer k and an integer array A sorted
in ascending order, find the k closest numbers to target in A, sorted in
ascending order by the difference between the number and target.
Otherwise, sorted in ascending order by number if the difference is same.

Example
Given A = [1, 2, 3], target = 2 and k = 3, return [2, 1, 3].

Given A = [1, 4, 6, 8], target = 3 and k = 3, return [4, 1, 6].

Challenge
O(logn + k) time complexity.
*/



class Solution {
public:
    /**
     * @param A an integer array
     * @param target an integer
     * @param k a non-negative integer
     * @return an integer array
     * 基本思路：
     *      1. 找到closest number
     *      2. 以closest为中心，使用两指针寻找next closest直到k个
     */
    vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
        vector<int> ret;
        if(A.size() == 0) return ret;
        if(k==0) return ret;


        // search for target
        int closest = -1;
        int start = 0;
        int end = A.size()-1;
        while(start + 1 < end) {
            int mid = start +(end-start)/2;
            if (A[mid] == target) {
                closest = mid;
                break;
            } else if (A[mid]<target){
                start = mid;
            } else {
                end = mid;
            }
        }
        // 确定closest
        if (closest == -1) {
            // 使用<=的原因是，保证start第一个被选上，因为题目有排序要求
            // e.g. {25,35,40,50}, t= 30, k=2
            // 这种情况下，25第一个选上，从而满足要求：
            // “Otherwise, sorted in ascending order by number if the difference is same”
            if (abs(A[start]-target) <= abs(A[end]-target)) {
                closest = start;
            } else {
                closest = end;
            }
        }

        int left = closest, right = closest;
        while(ret.size() < k) {
            if (left == right ) {
                ret.push_back(A[left]);
                left--; right++;
                continue;
            }
            if(left<0 && right >A.size()-1) {
                break;
            }
            if (left < 0) {
                ret.push_back( A[right++] ) ;
            } else if (right > A.size()-1) {
                ret.push_back( A[left--] ) ;
            } else if( abs(A[left]-target) <= abs(A[right]-target) ) {
                ret.push_back( A[left--] ) ;
            } else {
                ret.push_back( A[right++] ) ;
            }
        }
        return ret;
    }
};