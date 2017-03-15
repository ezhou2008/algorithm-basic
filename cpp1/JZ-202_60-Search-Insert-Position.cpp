/*
Search Insert Position

Description
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume NO duplicates in the array.

Example
[1,3,5,6], 5 → 2

[1,3,5,6], 2 → 1

[1,3,5,6], 7 → 4

[1,3,5,6], 0 → 0
*/



class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     *
     * 基本同basic binary search
     * 返回考虑target不在数组的情况
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        //find the first index that is >=target
        // if found, return the index
        //else  return the index of last element

        if (A.size()==0) return 0;

        int start = 0;
        int end = A.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (target == A[mid]) {
                return mid;
            } else if (target < A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (A[start] == target ) {
            return start;
        }
        if(A[end] == target) {
            return end;
        }

        // target比数组的所有element都小
        if (target < A[start]) {
            return start;
        }
        // target比数组的所有element都大
        if (target > A[end]) {
            return end+1;
        }
        // target在某两数之间，返回较大的数
        return end;
    }
};