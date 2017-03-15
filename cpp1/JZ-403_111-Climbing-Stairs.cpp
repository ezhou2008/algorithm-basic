/*Climbing Stairs

Description
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?

Example
Given an example n=3 , 1+1+1=2+1=1+2=3
                      ——
                    3｜
                    ——
                  2｜
                 ——
              1 ｜
             ——
   ground(0)｜
   ---------

 return 3
*/


class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     *
     * 思路见状态转移方程
     *
     */
    int climbStairs(int n) {

/*
        state
        注意 i代表stairs的steps数目，所以需要是1-n，i＝0(可以认为是ground）是为了计算方便

*/    vector<int> ways(n+1, 0);

/*
        init
        状态转移里面有ways[i-1]，ways[i-2],所以至少要初始化到ways[0], ways[1]
*/
        ways[0] = 1;
        ways[1] = 1;
        // ways[2] = 2;
/*
 *      function 状态转移
        第一次climb 1 step or 2 step, 对应的ways分别为ways[i-1] 和ways[i-2]
*/

        for (int i=2; i<=n; i++) {
            ways[i] = ways[i-1] + ways[i-2];
        }

//        answer
        return ways[n];
    }
};