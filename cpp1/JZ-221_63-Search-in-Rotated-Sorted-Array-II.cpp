/*Search in Rotated Sorted Array II

Description

Follow up for Search in Rotated Sorted Array:

What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Example
Given [1, 1, 0, 1, 1, 1] and target = 0, return true.
Given [1, 1, 1, 1, 1, 1] and target = 0, return false.
*/



class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     *
     * 要点：允许有duplicate，最坏的情况无法使用binary search
     *
  这道题目在面试中不会让写完整的程序
  只需要知道最坏情况下 [1,1,1....,1] 里有一个0
        这种情况下，如果mid指向0两边的1，由于两边是对称的，无法判断是左边还是右边
        从而没法知道从哪个方向靠近0（左边应该向右，右边应该向左）
  这种情况使得时间复杂度必须是 O(n)
  因此写一个for循环就好了。
  如果你觉得，不是每个情况都是最坏情况，你想用二分法解决不是最坏情况的情况，那你就写一个二分吧。
  反正面试考的不是你在这个题上会不会用二分法。这个题的考点是你想不想得到最坏情况。
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        for (int i=0; i<A.size(); i++) {
            if (A[i] == target) return true;
        }
        return false;
    }

};