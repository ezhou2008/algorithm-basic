/*Find Minimum in Rotated Sorted Array II

Description

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

Notice
The array may contain duplicates.

Have you met this question in a real interview? Yes
        Example
Given [4,4,5,6,7,0,1,2] return 0.
*/


class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
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
    int findMin(vector<int> &num) {
        //find first element that is < last element

        int min_num = INT_MAX;

        for (int i = 0; i < num.size(); i++) {
            min_num = min(min_num, num[i]);
        }
        return min_num;
    }
};
