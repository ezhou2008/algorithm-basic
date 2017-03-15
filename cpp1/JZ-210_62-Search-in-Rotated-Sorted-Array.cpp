/*
Search in Rotated Sorted Array

Description
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index,
otherwise return -1.

You may assume no duplicate exists in the array.

Example
For [4, 5, 1, 2, 3] and target=1, return 2.

For [4, 5, 1, 2, 3] and target=0, return -1.

Challenge
O(logN) time
*/

class Solution_mid {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     * 1. 使用二分法模版
     * 2. 先需要判断mid所在位置，是在rotation point 左边还是右边
     * 3. 关键点：
     *    后判断target是否在mid有序的哪一边（非有序的那边判断条件很难写），其它的else就行
     *    ＊＊＊＊＊＊也就是说找找判断条件容易写的那边，其余用else＊＊＊＊＊
     *
     */
public:
    int search(vector<int> &A, int target) {

        if (A.size()==0) return -1;

        int start = 0;
        int end = A.size()-1;

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (A[mid] == target) {
                return mid;
            }
/*          下面语句如果写成(A[mid] > A[A.size()-1])也是可以的，
 *          因为A[A.size()-1]和A[0]是相邻的
 *
            唯一的区别在于，如果数组不是rotate的话，下面的写法就会
            一直用"mid在 rotation point的右边"的条件来判断，
            上面的写法会一直用"mid在 rotation point的左边"的条件来判断，
            结果区别不大，只是如果target不在数组里的话，start和end最后停留的位置有些差别*/
            if (A[mid] > A[0]) {  //mid在 rotation point的左边，mid左边是有序的
//              target是否是在mid左边
//              注意：target和数组第一个元素比较是>=(可能会相等）
                if (target < A[mid] && target >= A[0]) {
                    end = mid;
                } else {
                    start = mid;
                }
            }else { // mid在 rotation point的右边，mid右边是有序的
//                target是否是在mid右边
//                注意：target和数组最后一个元素比较是<=(可能会相等）
                if (target > A[mid] && target <= A[A.size()-1]) {
                    start = mid;
                }else {
                    end = mid;
                }
            }
        }
        if (A[start] == target) return start;
        if (A[end] == target) return end;

        return -1;
    }
};


class Solution_target {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     *
     * 基本，不同的地方在于，先判断target的位置，在判断mid和target的相对位置
     */
public:
    int search(vector<int> &A, int target) {

        if (A.size()==0) return -1;

        int start = 0;
        int end = A.size()-1;

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (A[mid] == target) {
                return mid;
            }
            if (target >= A[0]) {
                if (A[mid] < target && A[mid] >= A[0]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }else {
                if (A[mid] > target && A[mid] <= A[A.size()-1]) {
                    end = mid;
                }else {
                    start = mid;
                }
            }
        }
        if (A[start] == target) return start;
        if (A[end] == target) return end;

        return -1;
    }
};