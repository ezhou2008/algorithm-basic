/* Backpack II

Description
Given n items with size Ai and value Vi, and a backpack with size m.
What's the maximum value can you put into the backpack?

Notice
You cannot divide item into small pieces and the total size of items
you choose should smaller or equal to m.

Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4],
and a backpack with size 10. The maximum value is 9.

Challenge
O(n x m) memory is acceptable, can you do it in O(m) memory?

*/

class Solution_1 {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     *
     * 1. ith item要么选上，要么不选。
     * 2. O(n x m) memory
     * 3. bp_size 作为state的一个参数，从而变成一个二维的dp
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here

        int arr_len = A.size();

        // state: MV(i,bp_size) max value at i-th item and backpack size of bp_size
        // arr_len没有＋1，m到是＋1了
        vector<vector<int>> MV(arr_len, vector<int>(m+1, 0));

        for(int bp_size=0; bp_size<=m; bp_size++) {
            if (A[0] <= bp_size) {
                MV[0][bp_size] = V[0];
            } // else MV =0 as initialized
        }

        for (int i=1; i<arr_len;i++) {
            for(int bp_size=1; bp_size<=m; bp_size++) {
                // 一定条件下，i-th item选上
                if (A[i] <= bp_size ) { /*取包括i-th和不包括i-th item中的大者*/
                    MV[i][bp_size] = max(MV[i-1][bp_size-A[i]] + V[i], MV[i-1][bp_size]);
                } else { // 没有选上
                    MV[i][bp_size] = MV[i-1][bp_size];
                }
            }
        }
        return MV[arr_len-1][m];
    }
};


class Solution_space_optimized {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     *
     * 1. ith item要么选上，要么不选。选上需要满足一定的条件，否则不选。
     * 2. O(m) memory
     *    在O(n x m) memory方案上优化
     *    从递推关系上看，i 行结果仅仅取决于i-1行，所以空间可以用一维数据代替二维数组
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here

        int arr_len = A.size();

        // state MV(i,j) max value with ith item and backpack size j
        vector<int> MV(m+1,0);

        for(int bp_size=0; bp_size<=m; bp_size++) {
            if (A[0] <= bp_size) {
                MV[bp_size] = V[0];
            } // else MV =0 as initialized
        }

        for (int i=1; i<arr_len;i++) {
/*
            注意：ba_size倒序进行运算
*/
            for(int bp_size=m; bp_size>=1; bp_size--) {
                // if selected
                if (A[i] <= bp_size ) {
                    MV[bp_size] = max( MV[bp_size-A[i]] + V[i], MV[bp_size] );
                } // 对于A[i] > bp_size情况，保持前面的值，不需要计算了
            }
        }
        return MV[m];
    }
};





