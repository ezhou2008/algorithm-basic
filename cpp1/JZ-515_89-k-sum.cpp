/*k Sum

Description
Given n distinct positive integers, integer k (k <= n) and a number target.

Find k numbers where sum is target. Calculate how many solutions there are?

Example
Given [1,2,3,4], k = 2, target = 5.

There are 2 solutions: [1,4] and [2,3].

Return 2.

Tags
LintCode Copyright Dynamic Programming
*/


class Solution_better {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     *
     * 1. 类似递归，通过dp缩小规模，直到基本的case
     * 2. target也作为state的一个变量
     * 3. A[i]要么选上要么不选上，两种可能数量相加
     */
    int kSum(vector<int> A, int k, int target) {

        // state:
        //  solutions(i,j,t)：
        //      i: index of A,
        //      j: <=k,
        //      t <= target
        // all init to 0
        vector<vector<vector<int>>> solutions(A.size()+1,
                                              vector<vector<int>>(k+1, vector<int>(target+1,0)));

        // init: 这个是关键
        // base case: 当target缩小为0，k也缩减为0的话，说明存在一个solution
        for (int i=0; i<=A.size(); i++) {
            solutions[i][0][0] = 1;
        } //对应于： solutions[i-1][j-1][t-A[i-1]]的base case

        // function
        // 所有index ＝ 0 的情况也初始化
        for (int i=1; i<=A.size(); i++) {
        //  注意：j<i, 不加这个条件也可以，运行时间会增加写，但复杂度一样
            for (int j=1; j<=k&&j<=i; j++) {
                for (int t=1; t<=target; t++) {
                    if (A[i-1] <= t) { // A[i] either selected or not selected
                        solutions[i][j][t] = solutions[i-1][j][t] + solutions[i-1][j-1][t-A[i-1]];
                    } else { // a[i] is not possilbe to be selected
                        solutions[i][j][t] = solutions[i-1][j][t];
                    }
                }
            }
        }

        //answer
        return solutions[A.size()][k][target];


    }
};


class Solution_my {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     * 1. 类似递归，通过dp缩小规模，直到基本的case
     * 2. target也作为state的一个变量
     * 3. 和上面方案的区别：i的范围是［0，A.size()-1], 上面的方案是［0，A.size()]（人为增加一个元素）
     */
    int kSum(vector<int> A, int k, int target) {

        // state:
        //  solutions(i,j,t)：
        //      i: index of A,
        //      j: <=k,
        //      t <= target
        // all init to 0
        vector<vector<vector<int>>> solutions(A.size(), vector<vector<int>>(k+1, vector<int>(target+1,0)));

        // init:
        // base case: 当target缩小为0，k也缩减为0的话，说明存在一个solution
        for (int i=0; i<A.size(); i++) {
            solutions[i][0][0] = 1;
        }

        // init:
        // i=0 only one element in A
        for (int j=0; j<=k; j++) {
            for (int t=0; t<=target; t++) {
                if (j==1 && A[0] == t) {
                    solutions[0][j][t] = 1;
                }
            }
        }

        // function
        for (int i=1; i<A.size(); i++) {
            for (int j=1; j<=k; j++) {
                for (int t=1; t<=target; t++) {
                    // A[i] either selected or not selected
                    if (A[i] <= t) { //selected
                        solutions[i][j][t] = solutions[i-1][j][t] + solutions[i-1][j-1][t-A[i]];
                    } else { //not selected
                        solutions[i][j][t] = solutions[i-1][j][t];
                    }
                }
            }
        }

        //answer
        return solutions[A.size()-1][k][target];


    }
};