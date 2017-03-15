/*
 * Implement int sqrt(int x).

Compute and return the square root of x.

Have you met this question in a real interview? Yes
        Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3

Challenge
        O(log(x))

Tags
        Binary Search Mathematics Facebook
        Related Problems
        Medium Pow(x, n) 38 %
Easy First Position of Target
 */

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     *
     * 要点：
     *  寻找last position of y*y <= target
     */
    int sqrt(int x) {
        // write your code here

        long start = 0;
        long end = x;

        while (start + 1 < end) {
            long mid = start + (end-start)/2;
//            继续往后寻找
            if (mid*mid <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        // 如果在范围里的话，end应该更靠近目标值
        if (end*end <= x){
            return (int)end;
        }else {
            return (int)start;
        }
    }
};