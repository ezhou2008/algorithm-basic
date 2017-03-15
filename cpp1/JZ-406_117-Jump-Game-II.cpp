/*Jump Game II

Description

Given an array of non-negative integers, you are initially positioned
at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     * 基本方案：
     * 对于ith位置，找出ith之前所有位置j中最小者（而且必须从j能到到达i）
     *
     * steps(i): 从起始位置到i 位置的最小step数
     * step（i）＝ min｛steps(j)}+1 j=0,i-1,j到i可达
     * step（n-1):是最后结果
     *
     * 因为每个step（i）独立的依赖于step（j）｛A[i]是maximum jump length｝，
     * 不是仅仅依赖于i 前面某几项, 所以需要两重循环计算,依赖关系如下：
     * step(1): {step(0),A(0)}
     * step(2): {step(0),A(0),{step(1),A(1)}
     * step(3): {step(0),A(0),{step(1),A(1),step(2),A(3)}
     * ......
     * step(n): {step(0),A(0),{step(1),A(1),step(2),A(3)}....step(n-1),A(n-1)}
     *
     *
     */
    int jump(vector<int> A) {
        int n_arr = A.size();

        // state
        vector<int> steps(n_arr,INT_MAX);
        //int
        steps[0] = 0;
        //function
        for(int i=1;  i<n_arr; i++) {
            for (int j=0; j<i; j++) {
                if ( A[j] >= (i-j) ) { //i is reachable from j by one step
                    steps[i] = min(steps[j], steps[i]);
                }
            }
/*
            不要忘记
*/
            steps[i]++;
        }
        //answer
        return steps[n_arr-1];

    }
};