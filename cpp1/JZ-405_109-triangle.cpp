/*
Triangle

Description

Given a triangle, find the minimum path sum from top to bottom.
Each step you may move to adjacent numbers on the row below.

Notice
Bonus point if you are able to do this using only O(n) extra space,
where n is the total number of rows in the triangle.

Example
Given the following triangle:

[
        [2],
       [3,4],
      [6,5,7],
     [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/



class Solution_1 {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     *
     * 1. O(n*n) extra space
     * 2. 不添加辅助行（0列需要单独计算
     *
     * 3. 将等边三角形改成直角三角形：
     *              [2],               2,
                   [3,4],   －>        3,4
                  [6,5,7],             6,5,7
                 [4,1,8,3]             4,1,8,3
     *
     * 递推公式：
     * f(i,j) = tr(i,j) + min{tri(i-1,j), tri(i-1,j-1)}
     * j = 0..i
     *
     * 初始化：
     * f(0,j)(只有一个数，因为是三角形), f(j,0)
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here

        int n_rows = triangle.size();
        // state
        //初始化成INT_MAX对于最右侧的数的计算就不需要单独出来了
        vector<vector<int>> sum(n_rows, vector<int>(n_rows, INT_MAX));

        //init
        sum[0][0] = triangle[0][0];

        // function
        for (int row = 1; row < n_rows; row++) {
            for (int col = 0; col <= row; col++) {
                if (col == 0) {
                    sum[row][col] =  triangle[row][col] + sum[row-1][col];
                } else {
                    sum[row][col] = triangle[row][col] + min(sum[row-1][col], sum[row-1][col-1]);
                }
            }
        }
        return *min_element(sum[n_rows-1].begin(), sum[n_rows-1].end());
    };
};

class Solution_2 {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     * 1. O(n) space
     *    计算逐行进行，并且只依赖上一行，所以可以只使用一行空间
     * 2. 不添加辅助行（0列需要单独计算）
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here

        int rows = triangle.size();

        //初始化成INT_MAX对于最右侧的数的计算就不需要单独出来了
        vector<int> min_sum(rows, INT_MAX);

        //initialization
        min_sum[0] = triangle[0][0];

        //function
        for ( int i = 1; i < rows; i++){
/*
            注意：j要倒序
*/
            for( int j= i; j >= 0; j--){
                if (j == 0) {  // 0列需单独处理
                    min_sum[0] = triangle[i][0] +  min_sum[0];
                } else {
                    min_sum[j] = triangle[i][j] + min(min_sum[j], min_sum[j-1]);
                }
            }
        }

        return *min_element(min_sum.begin(), min_sum.end());
    };
};

class Solution_best {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     * 1. O(n) space
     * 2. 添加辅助行（0列就不需要单独出来）
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here

        int rows = triangle.size();

        vector<int> min_sum(rows+1, INT_MAX);

        //initialization
        min_sum[1] = triangle[0][0];

        //function
        for ( int i = 2; i <= rows; i++){
            for( int j= i; j >= 1; j--){
                min_sum[j] = triangle[i-1][j-1] + min( min_sum[j] , min_sum[j-1] );
            }
        }
        return *min_element(min_sum.begin(), min_sum.end());
    };
};








