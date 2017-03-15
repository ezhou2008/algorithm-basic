/*
Unique Paths II

Description
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids.
How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Notice
m and n will be at most 100.

Example
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.
*/

class Solution_uniquePathsWithObstacles {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     *
     * 注意：没有必要添加多余的行和列，直接初始化第一列和第一行就行
     * 1. 坐标型
     * 2. 递推关系：
     *    path(i,j) = 从上面过来的path(i,j-1) + 从左边过来的path(i-1,j)
     *    如果(i,j)为obstacle的话，则 path(i,j) = 0;
     * 3. 递推方程里有：i-1,j-1，需要初始化path(i,0),path(0,j)
     * 4. path(i,j) = 0 表示不可达
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

//        state 状态 dp[i][j] = unique paths at pos (i,j)
        vector<vector<int>> dp(row, vector<int>(col,0));

//        init first col 初始化第一列，第一个obstacle及以后均初始化为0(已初始化），之前初始化为1
        for (int i = 0; i < row; i++ ) {
            if ( obstacleGrid[i][0] ) {
                break;
            } else {
                dp[i][0] = 1;
            }
        }
//        init first col 初始化第一行，第一个obstacle及以后均初始化为0(已初始化），之前初始化为1
        for (int j = 0; j < row; j++ ) {
            if ( obstacleGrid[0][j] ) {
                break;
            } else {
                dp[0][j] = 1;
            }
        }
//        function 状态转移方程 dp[i][j] = dp[i][j-1] + dp[i-1][j]
//        同时考虑obstacle的情况
/*
        注意：i，j 从1开始
*/
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if ( obstacleGrid[i][j] ) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
//        answer
        return dp[row-1][col-1];
    }
};