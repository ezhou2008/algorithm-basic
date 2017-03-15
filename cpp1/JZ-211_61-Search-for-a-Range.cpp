/*Search for a Range

Description

Given a sorted array of n integers, find the starting and ending
position of a given target value.

If the target is not found in the array, return [-1, -1].

Example
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Challenge
O(log n) time.

Tags
Binary Search Sorted Array Array
Related Problems
Easy Total Occurrence of Target
*/


class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     *
     * 分别找到first index and last index of target
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        //fint the first position and last position of target

        vector<int> res(2,-1); //init to -1(target not found)
        if(A.size() == 0) {
            return res;
        }

//        找到first index
        int start = 0;
        int end = A.size() - 1;
        while(start + 1 < end) {
            int mid = start + (end-start)/2;
            if (A[mid] == target ) {
                end = mid;
            } else if (target < A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (A[start] == target ) {
            res[0] = start;
        } else if (A[end] == target) {
            res[0] = end;
        } else { //not found
            return res;
        }

//      找到last index
        start = res[0];
        end = A.size() - 1;
        while(start + 1 < end) {
            int mid = start + (end-start)/2;
            if (target == A[mid] ) {
                start = mid;
            } else if (target < A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (A[end] == target ) {
            res[1] = end ;
        } else if (A[start] == target) {
            res[1] = start;
        } else { //not found
            //
        }

        return res;
    }
};