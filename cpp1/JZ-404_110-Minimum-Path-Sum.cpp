/*Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes
the sum of all numbers along its path.

Note
You can only move either down or right at any point in time.
*/

class Solution_1_recommend {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     *
     * 递推关系：
     *      在从上面和从左边来的路径中取最小，加上当前grid的值
     *
     * 不添加辅助行和列
     */
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0) return 0;


        int m_row = grid.size();
        int n_col = grid[0].size();


        //state
        vector<vector<int>> sum(m_row, vector<int>(n_col, 0));

        // init
        // col 0
        sum[0][0] = grid[0][0];
        for (int row = 1; row < m_row; row++) {
            sum[row][0] = sum[row-1][0] + grid[row][0];
        }
        for (int col = 1; col < n_col; col++) {
            sum[0][col] = sum[0][col-1] + grid[0][col];
        }

        //function
        for (int row = 1; row < m_row; row++) {
            for (int col = 1; col < n_col; col++) {
                sum[row][col] = grid[row][col] + min(sum[row][col-1],sum[row-1][col]);
            }
        }
        return sum[m_row-1][n_col-1];
    }
};



class Solution_2 {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     *
     * 添加辅助行和列（0行，0列）
     * 相对于不添加辅助行列而言，代码要简洁写
     *
     */
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0) return 0;


        int m_row = grid.size();
        int n_col = grid[0].size();

        //state
        vector<vector<int>> sum(m_row+1, vector<int>(n_col+1, INT_MAX));

        //init
/*
        sum(1,1) 没法用状态转移方程计算，所以单独初始化
        为什么不能是因为 sum(1,1) = grid[0][0] + min(INT_MAX,INT_MAX) = INT_MAX
*/
        sum[1][1] = grid[0][0];

        //function
        for (int row = 1; row <= m_row; row++) {
            for (int col = 1; col <= n_col; col++) {
/*
                sum(1,1) 没法用状态转移方程计算，跳过
*/
                if (row==1 && col==1) continue;
/*
                注意：grid和sum的序数差1
*/
                sum[row][col] = grid[row-1][col-1] + min(sum[row][col-1],sum[row-1][col]);
            }
        }
        return sum[m_row][n_col];
    }
};

