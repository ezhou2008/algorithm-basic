/*Search in a Big Sorted Array

Description
Given a big sorted array with positive integers sorted by ascending order.
The array is so big so that you can not get the length of the whole array directly,
and you can only access the kth number by ArrayReader.get(k) (or ArrayReader->get(k) for C++).
Find the first index of a target number. Your algorithm should be in O(log k),
where k is the first index of the target number.
Return -1, if the number doesn't exist in the array.

Notice
If you accessed an inaccessible index (outside of the array),
ArrayReader.get will return 2,147,483,647.

Example
Given [1, 3, 6, 9, 21, ...], and target = 3, return 1.
Given [1, 3, 6, 9, 21, ...], and target = 4, return -1.

Challenge
O(log k), k is the first index of the given target number.
*/




/**
* Definition of ArrayReader:
*
* class ArrayReader {
    * public:
    *     int get(int index) {
        *          // return the number on given index,
                *          // return -1 if index is less than zero.
                        *     }
    * };
*/
class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     *
     * step 1: *2步进找到上界
     * step 2: 标准binary search for first occurance on index
     *
     */
    int searchBigSortedArray(ArrayReader *reader, int target) {
        // write your code here

        //step 1: *2步进找到上界
        int start = 0;
        int end = 1;

        while ( target > reader->get(end-1)) {
            end *= 2;
        }

        // start此时可以去(end_+1)/2-1
        // 直接取0更简单，和上面应该只差一步

        //binary search找first occurance
        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (target == reader->get(mid)) {
                end = mid;
            } else if (target < reader->get(mid) ) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (target == reader->get(start)) {
            return start;
        }
        if (target == reader->get(end)) {
            return end;
        }


        return -1;
    }
};