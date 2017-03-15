/*First Position of Target
Description
For a given sorted array (ascending order) and a target number,
find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

Challenge
If the count of numbers is bigger than 2^32, can your code work properly?
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
通用的二分法模板
1. start + 1 < end
2. start + (end - start) / 2
3. A[mid] ==, <, > (？target）
4. A[start] A[end] ? target

结果：
[1,4,4,5,7,7,8,9,9,10], 4

1. 如果target在里面，只有一个指针(end)指向first index of target
       (如果数组前两个为target的话，start，end指向前两个）
2. 如果target不在里面，
       在数组范围里：start,end分别指向<target(最后一个）和>target的位置（第一个）
       target比数组所有数都大：start，end指向数组最后两个数
       target比数组所有数都小：start，end指向数组前两个数
     */

    int binarySearch(vector<int> &array, int target) {
        if (array.size() == 0) return -1;

        int start = 0;
        int end = array.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (target == array[mid] ) {
/* 继续向前寻找 */
                end = mid;
            } else if (target < array[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }

/* start的判断必须在end 前面 */
        if (target == array[start]) return start;
        if (target == array[end]) return end;

        return -1;

    }
};