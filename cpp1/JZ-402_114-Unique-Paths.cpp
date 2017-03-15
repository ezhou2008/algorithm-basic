/*Unique Paths

Description
A robot is located at the top-left corner of a m x n grid
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid
(marked 'Finish' in the diagram below).

How many possible unique paths are there?

Notice
m and n will be at most 100.

Have you met this question in a real interview? Yes
        Example
*/

class Solution_uniquePaths {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     *
     * 注意：没有必要添加多余的行和列，直接初始化第一列和第一行就行
     * 1. 坐标型
     * 2. 递推关系：
     *    path(i,j) = 从上面过来的path(i,j-1) + 从左边过来的path(i-1,j)
     */
    int uniquePaths(int m, int n) {

        // state
        vector<vector<int>> paths(m, vector<int>(n, 0));

        // init
//        init first col 初始化第一列，初始化为1
        for (int row=0; row<m; row++) {
            paths[row][0] = 1;
        }

//        init first row 初始化第一行，初始化为1
        for (int col=0; col<n; col++) {
            paths[0][col] = 1;
        }


//        function 状态转移方程 dp[i][j] = dp[i][j-1] + dp[i-1][j]
        for (int row=1; row<m; row++) {
            for (int col=1; col<n; col++) {
                paths[row][col] = paths[row-1][col] + paths[row][col-1];
            }
        }

        //answer
        return paths[m-1][n-1];
    }
};
