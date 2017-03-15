/*Jump Game

Description

Given an array of non-negative integers, you are initially positioned
at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Notice
This problem have two method which is Greedy and Dynamic Programming.

The time complexity of Greedy method is O(n).

The time complexity of Dynamic Programming method is O(n^2).

We manually set the small data set to allow you pass the test in both ways.
This is just to let you learn how to use this problem in dynamic programming ways.
If you finish it in dynamic programming ways, you can try greedy method to
make it accept again.

Example
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

Tags
        Greedy Dynamic Programming Array
        Related Problems
        Medium Jump Game II
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     *
     * 对于位置i，如果其前面任意位置j是可达（从位置0），而且从j到i是可达的话，i就可达。
     * reachable(i)= 可达，if ｛reachable(j) && j能到i}, j=0,i-1
     *                else: 不可达
     *
     * reachable(i):表示从起始位置是否能到达位置j。
     * 需要的结果是reachable(n)
     */
    bool canJump(vector<int> A) {


        // state
        vector<bool> reachable(A.size(), false);
        //init
        reachable[0] = true;

        for (int i = 1; i < A.size(); i++) {
            for (int j=0; j<i; j++) {
                // 位置j reachable 而且从i从j可达
                if (reachable[j] && A[j]>=(i-j)) {
                    reachable[i] = true;
                    break;
                }
            }
        }
        return reachable[A.size()-1];


    };
};
