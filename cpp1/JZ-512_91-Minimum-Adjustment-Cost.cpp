/*minimum Adjustment Cost

Description
Given an integer array, adjust each integers so that the difference
of every adjacent integers are not greater than a given number target.

If the array before adjustment is A, the array after adjustment is B,
you should minimize the sum of |A[i]-B[i]|
3
 Notice
You can assume each number in the array is a positive integer and not greater than 100.

Example
Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3],
the adjustment cost is 2 and it's minimal.

Return 2.
*/


class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     *
     * state: MAC(i,j) = min adjustment cost of  changing A[i] to j
     * MAC(i,j) = min{ MAC(i-1,k) } + |A(i)-j| , k<=100(or Max of array4) && |k-j| <= target
     *      也就是找出A[i-1] change to k的最小值，加上当前的cost{A[i]-j}
     *      总共3变量，3重循环
     */
    int MinAdjustmentCost(vector<int> A, int target) {

        const int M = 100;
//        const int M = *max_element(A.begin(), A.end());

        // state: MAC(i,j) = min adjustment cost of  changing A[i] to j
        vector <vector<int>> MAC(A.size(), vector<int>(M + 1, INT_MAX));

/*
 * 注意：这里MAC[0][j] 不是＝＝0，如果初始化为0的话，就有问题
        但是min{MAC(0,j)} == 0, 也就是说A.size()==1的话，不需要调整，因为没有相邻的数
*/
        for (int j = 0; j <= M; j++) {
            MAC[0][j] = abs(A[0] - j);;
        }

        // function:
        // MAC(i,j) = min{ MAC(i-1,k) } + |A(i)-j| , k<=100 && |k-j| <= target

        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j <= M; j++) {
                for (int k = 0; k <= M; k++) {
                    if (abs(k - j) <= target) {
                        MAC[i][j] = min(MAC[i][j], MAC[i - 1][k]);
                    }
                }
                MAC[i][j] += abs(A[i] - j);
            }
        }

        // answer
        return *min_element(MAC[A.size() - 1].begin(), MAC[A.size() - 1].end());

    }
};