/*Find Minimum in Rotated Sorted Array

Description
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

Notice
You may assume no duplicate exists in the array.

Example
Given [4, 5, 6, 7, 0, 1, 2] return 0
*/


class Solution_better {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     *
     * Given [4, 5, 6, 7, 0, 1, 2] return 0
     * 1. 寻找第一个小于最后一个数的element
     * 2. 要考虑没有rotate的情况
     * 注意：不能是"寻找第一个小于＊＊第一个数＊＊的element"，因为无法处理没有rotate的情况
     * （除非首先排除掉这种情况），但"寻找第一个小于＊＊最后一个数＊＊的element"就可以
     *   正确的处理没有rotate的情况。
     *
     *
     */
    int findMin(vector<int> &num) {

        if (num.size() == 0) return -1;
        //数组只有一个元素的情况，去掉这种情况后，其它比较好处理
        if (num.size() == 1) return num[0];

        int start = 0;
        int end = num.size() - 1;
        int target = num[end];

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (num[mid] < target) {
                end = mid;
            } else if (num[mid] > target) {
                start = mid;
            } //else 不可能＝＝target
        }
        //start,end 要么是 2，1，要么是1，2的情况
        if (num[start] < target) {
            return num[start];
        }else {
            return num[end];
        }

    }

};

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     * Given [4, 5, 6, 7, 0, 1, 2] return 0
     * 寻找一个（不是第一个）小于前面的数的element
     * 这种方法比"寻找第一个小于最后一个数的element"，稍稍麻烦一点
     */
    int findMin(vector<int> &num) {
        //find the element that is < previous
        if (num.size() == 1) return num[0];
        //排除没有rotate的情况
        if (num[0] < num[num.size()-1]) {
            return num[0];
        }

        int start = 0;
        int end = num.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (num[mid] < num[mid-1]) {
                return num[mid];
            }
            if (num[mid] > num[0]) { //在"4，5，6，7"的区域
                start = mid;
            } else { //在0，1，2的区域
                end = mid;
            }
        }

        if (num[start] < num[start-1]) {
            return num[start];
        }
        if (num[end] < num[end-1]) {
            return num[end];
        }
    }

};