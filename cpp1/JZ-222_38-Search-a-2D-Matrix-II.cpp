/*Search a 2D Matrix II

Description
Write an efficient algorithm that searches for a value in an m x n matrix,
return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.

Example
Consider the following matrix:

[
[1, 3, 5, 7],
[2, 4, 7, 8],
[3, 5, 9, 10]
]
Given target = 3, return 2.

Challenge
O(m+n) time and O(1) extra space
*/


class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     *
     * 要点：
     * 1. 不是二分法
     * 2. 每次从右上角开始，判断右上角数和target的关系，这样可以排除一行或者一列，或者一行＋一列
     *      = 排除右上角数所在行和所在列
     *     > 排除右上角数所在列
     *      < 排除右上角数所在行
     */


    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        //scan along dia..direcition

        if (matrix.size()==0) return 0;
        int count = 0;

        int num_row = matrix.size();
        int num_col = matrix[0].size();

        int row_idx = 0;
        int col_idx = num_col - 1;

        while (row_idx < num_row && col_idx >=0) {
            if (matrix[row_idx][col_idx] == target ) {
                count++;
                row_idx++; col_idx--;
            } else if(matrix[row_idx][col_idx] > target ) {
                col_idx--;
            } else {
                row_idx ++;
            }
        }
        return count;
    }
};
