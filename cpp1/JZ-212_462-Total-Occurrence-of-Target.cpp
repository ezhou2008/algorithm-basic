/*Total Occurrence of Target

Description

Given a target number and an integer array sorted in ascending order.
Find the total number of occurrences of target in the array.

Have you met this question in a real interview? Yes
        Example
Given [1, 3, 3, 4, 5] and target = 3, return 2.

Given [2, 2, 3, 4, 6] and target = 4, return 1.

Given [1, 2, 3, 4, 5] and target = 6, return 0.

Challenge
Time complexity in O(logn)
*/

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     *
     * 要点
     *  find the first occurance and last occurance of target
     */
    int totalOccurrence(vector<int>& A, int target) {
        // Write your code here
        //find the first occurance and last occurance of target
        if (A.size() == 0) return 0;

        int first_pos = -1;
        int last_pos = -1;

//        找到first position of target
        int start = 0;
        int end =  A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (target <= A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (A[start] == target) {
            first_pos = start;
        } else if (A[end] == target) {
            first_pos = end;
        } else {
            return 0;
        }

//        找到last position of target
        start = first_pos;
        end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (target >= A[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (A[end] == target) {
            last_pos = end;
        } else if (A[start] == target) {
            last_pos = start;
        }
//        返回count
        return last_pos-first_pos+1;
    }
};