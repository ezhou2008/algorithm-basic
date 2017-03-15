/*Closest Number in Sorted Array

Description

Given a target number and an integer array A sorted in ascending order,
 find the index i in A such that A[i] is closest to the given target.

Return -1 if there is no element in the array.

Notice
There can be duplicate elements in the array,
and we can return any of the indices with same value.

Example
Given [1, 2, 3] and target = 2, return 1.

Given [1, 4, 6] and target = 3, return 1.

Given [1, 4, 6] and target = 5, return 1 or 2.

Given [1, 3, 3, 4] and target = 2, return 0 or 1 or 2.

Challenge
O(logn) time complexity.
*/

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     *
     *  对于classic binary search:
     *  如果target不在里面，在数组范围里：start,end分别指向<target(最后一个）和>target的位置（第一个)
     *  找出start和end中和target最近一个即可。
     */
    int closestNumber(vector<int>& A, int target) {
        // Write your code here
        if (A.size()==0) return -1;

        int start = 0;
        int end = A.size()-1;

        while(start + 1 < end) {
            int mid = start +(end-start)/2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                start = mid;
            } else {
                end= mid;
            }
        }
        if(abs(A[start]-target) < abs(A[end]-target)) {
            return start;
        } else {
            return end;
        }
    }
};


/*
--------following for backup only-----------------
*/

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     * 要点：
     * 1. find last occurance of <=target
     * 2. find fist occurance >= target
     * 3. 返回和target更近的数
     */
    int closestNumber(vector<int>& A, int target) {
        // Write your code here
        //find last occurance of <=target
        // find fist occurance >= target
        //choose between the closest between first and last occurance

        if (A.size()==0) return -1;

        int first_pos = -1, last_pos=-1;

//        1. find last occurance of <=target
        int start = 0;
        int end = A.size()-1;

        while(start + 1 < end) {
            int mid = start +(end-start)/2;
            if (A[mid] <= target) {
                start = mid;
            } else {
                end= mid;
            }
        }
        if(A[end] <= target) {
            last_pos = end;
        }else if (A[start] <= target) {
            last_pos = start;
        } else {
            return 0; //所有的数都比target大，返回第一个数
        }

//        2. find fist occurance >= target
        start = last_pos;
        end = A.size()-1;

        while(start + 1 < end) {
            int mid = start +(end-start)/2;
            if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if(A[start] >= target) {
            first_pos = start;
        }else if (A[end] >= target) {
            first_pos = end;
        } else{
            return A.size()-1; //所有的数都比target小，返回最后一个数
        }

//        3. 返回和target更近的数
        if ( A[first_pos]-target > target-A[last_pos] ) {
            return last_pos;
        }else {
            return first_pos;
        }


    }
};