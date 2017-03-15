/*Search a 2D Matrix

Description

Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example
Consider the following matrix:

[
[1, 3, 5, 7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.

Challenge
O(log(n) + log(m)) time
*/

class Solution_1 {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     *
由于matrix有如下特性，所以把matrix每一行首尾相连成一个1d arrary, 然后使用标准二分法搜索

This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
     *
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here

        //base cases
        if (matrix.empty()) return false;

        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col - 1;

        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (target == matrix[mid/col][mid%col]) {
                return true;
            } else if (target < matrix[mid/col][mid%col]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (target == matrix[start/col][start%col]) {
            return true;
        }
        if (target == matrix[end/col][end%col]) {
            return true;
        }
        return false;
    }
};


class Solution_2 {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     *
     * O(log(n) + log(m)) time
     * 1. 现在第一列里找，找到对应的行
     * 2. 再在相应的行里找
     *
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here

        if (matrix.size() == 0) return false;
        int n_row = matrix.size();
        int n_col = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[n_row-1][n_col-1]) return false;
/*
        find the row where target reside
*/
        //(search the insert position of target in first column)
        int start = 0;
        int end = n_row - 1;
        int mid;
        int row_target = -1;

        while (start + 1 < end){
            mid = start + (end - start)/2;
            if (matrix[mid][0] == target){
                return true;
            }else if (target < matrix[mid][0]) {
                end = mid;
            }else {
                start = mid;
            }
        }
        if(target < matrix[start][0]) return false;
        else if(target == matrix[start][0]) return true;
        else if(target < matrix[end][0]){
            row_target = start;
        }else if(target == matrix[end][0]) return true;
        else { //target > matrix[end][0]
            row_target = end;
        }

/*
        find in target row
*/
        start = 0;
        end = n_col- 1;

        while (start + 1 < end){
            mid = start + (end - start)/2;
            if (matrix[row_target][mid] == target){
                return true;
            }else if (target < matrix[row_target][mid]) {
                end = mid;
            }else {
                start = mid;
            }
        }
        if(target == matrix[row_target][start]) return true;
        if(target == matrix[row_target][end]) return true;

        return false;
    }
};


class Solution_3 {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     *
     * 类似：Search a 2D Matrix II
     * O(m+n) time, 比二分法差写
     *
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
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
                return true;
            } else if(matrix[row_idx][col_idx] > target ) {
                col_idx--;
            } else {
                row_idx ++;
            }
        }
        return count;
    }
};


